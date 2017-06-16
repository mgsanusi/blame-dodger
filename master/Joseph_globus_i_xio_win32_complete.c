/*
 * Copyright 1999-2014 University of Chicago
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifdef _WIN32

#include "globus_i_xio_win32.h"

#define GlobusLWin32PollQueueInit()                                         \
{                                                                           \
    globus_l_xio_win32_poll_queue = 0;                                      \
    globus_l_xio_win32_poll_queue_tail = &globus_l_xio_win32_poll_queue;    \
}

#define GlobusLWin32PollQueueEnqueue(entry)                                 \
{                                                                           \
    (entry)->next = 0;                                                      \
    *globus_l_xio_win32_poll_queue_tail = (entry);                          \
    globus_l_xio_win32_poll_queue_tail = &(entry)->next;                    \
}

#define GlobusLWin32PollQueueDequeue(entry)                                 \
{                                                                           \
    (entry) = globus_l_xio_win32_poll_queue;                                \
    globus_l_xio_win32_poll_queue = (entry)->next;                          \
    if(!globus_l_xio_win32_poll_queue)                                      \
        globus_l_xio_win32_poll_queue_tail = &globus_l_xio_win32_poll_queue;\
}

#define GlobusLWin32PollQueueEmpty()                                        \
    (globus_l_xio_win32_poll_queue == 0)

typedef struct globus_l_xio_win32_poll_entry_s
{
    globus_callback_func_t              callback;
    void *                              user_arg;
    struct globus_l_xio_win32_poll_entry_s * next;
} globus_l_xio_win32_poll_entry_t;

static globus_callback_handle_t         globus_l_xio_win32_poll_handle;
static win32_mutex_t                    globus_l_xio_win32_poll_lock;
static HANDLE                           globus_l_xio_win32_poll_event;
static globus_bool_t                    globus_l_xio_win32_poll_event_sleeping;
static globus_bool_t                    globus_l_xio_win32_poll_event_pending;
static globus_l_xio_win32_poll_entry_t * globus_l_xio_win32_poll_queue;
static globus_l_xio_win32_poll_entry_t ** globus_l_xio_win32_poll_queue_tail;
static globus_l_xio_win32_poll_entry_t * globus_l_xio_win32_poll_free;

static
void
globus_l_xio_win32_wakeup_handler(
    void *                              user_arg)
{
    GlobusXIOName(globus_l_xio_win32_wakeup_handler);

    GlobusXIOSystemDebugEnter();
    
    if(globus_l_xio_win32_poll_event != 0)
    {
        SetEvent(globus_l_xio_win32_poll_event);
    }
    
    GlobusXIOSystemDebugExit();
}

static
void
globus_l_xio_win32_poll(
    void *                              user_arg)
{
    GlobusXIOName(globus_l_xio_win32_poll);

    GlobusXIOSystemDebugEnter();

    win32_mutex_lock(&globus_l_xio_win32_poll_lock);
    {
        if(GlobusLWin32PollQueueEmpty())
        {
            globus_reltime_t            time_left;
            
            globus_callback_get_timeout(&time_left);
            if(globus_reltime_cmp(&time_left, &globus_i_reltime_zero) > 0)
            {
                DWORD                   millis = INFINITE;
                
                if(!globus_time_reltime_is_infinity(&time_left))
                {
                    GlobusTimeReltimeToMilliSec(millis, time_left);
                }
                
                globus_l_xio_win32_poll_event_sleeping = GLOBUS_TRUE;
                win32_mutex_unlock(&globus_l_xio_win32_poll_lock);
                
                WaitForSingleObject(globus_l_xio_win32_poll_event, millis);
                
                win32_mutex_lock(&globus_l_xio_win32_poll_lock);
                globus_l_xio_win32_poll_event_sleeping = GLOBUS_FALSE;
                globus_l_xio_win32_poll_event_pending = GLOBUS_FALSE;
            }
        }
        
        while(!GlobusLWin32PollQueueEmpty())
        {
            globus_l_xio_win32_poll_entry_t * entry;
            
            GlobusLWin32PollQueueDequeue(entry);
            
            win32_mutex_unlock(&globus_l_xio_win32_poll_lock);
                
            entry->callback(entry->user_arg);
            
            win32_mutex_lock(&globus_l_xio_win32_poll_lock);
            
            entry->next = globus_l_xio_win32_poll_free;
            globus_l_xio_win32_poll_free = entry;
            
            if(globus_callback_has_time_expired())
            {
                break;
            }
        }
    }
    win32_mutex_unlock(&globus_l_xio_win32_poll_lock);

    GlobusXIOSystemDebugExit();
}

int
globus_i_xio_win32_complete_activate(void)
{
    globus_result_t                     result;
    globus_reltime_t                    period;
    GlobusXIOName(globus_i_xio_win32_complete_activate);
    
    GlobusXIOSystemDebugEnter();
    
    if (!globus_i_am_only_thread())
    {
        goto skip_activate;
    }
    GlobusLWin32PollQueueInit();
    win32_mutex_init(&globus_l_xio_win32_poll_lock, 0);
    globus_l_xio_win32_poll_event_sleeping = GLOBUS_FALSE;
    globus_l_xio_win32_poll_event_pending = GLOBUS_FALSE;
    globus_l_xio_win32_poll_free = 0;
    
    globus_l_xio_win32_poll_event = CreateEvent(0, FALSE, FALSE, 0);
    if(globus_l_xio_win32_poll_event == 0)
    {
        goto error_event;
    }
    
    GlobusTimeReltimeSet(period, 0, 0);
    result = globus_callback_register_periodic(
        &globus_l_xio_win32_poll_handle,
        0,
        &period,
        globus_l_xio_win32_poll,
        0);
    if(result != GLOBUS_SUCCESS)
    {
        goto error_periodic;
    }
    
    globus_callback_add_wakeup_handler(
        globus_l_xio_win32_wakeup_handler, 0);
    
skip_activate:
    GlobusXIOSystemDebugExit();
    
    return GLOBUS_SUCCESS;
    
error_periodic:
    CloseHandle(globus_l_xio_win32_poll_event);
    globus_l_xio_win32_poll_event = 0;
error_event:
    win32_mutex_destroy(&globus_l_xio_win32_poll_lock);
    GlobusXIOSystemDebugExitWithError();
    return GLOBUS_FAILURE;
}

typedef struct
{
    globus_cond_t                       cond;
    globus_mutex_t                      mutex;
} globus_l_shutdown_info_t;

static
void
globus_l_xio_win32_unregister_poll_cb(
    void *                              user_arg)
{
    globus_l_shutdown_info_t *          info;
    GlobusXIOName(globus_l_xio_win32_unregister_poll_cb);
    
    GlobusXIOSystemDebugEnter();
    
    info = (globus_l_shutdown_info_t *) user_arg;
    
    globus_mutex_lock(&info->mutex);
    {
        CloseHandle(globus_l_xio_win32_poll_event);
        globus_l_xio_win32_poll_event = 0;
        globus_cond_signal(&info->cond);
    }
    globus_mutex_unlock(&info->mutex);
    
    GlobusXIOSystemDebugExit();
}

int
globus_i_xio_win32_complete_deactivate(void)
{
    globus_result_t                     result;
    globus_l_shutdown_info_t            info;
    GlobusXIOName(globus_i_xio_win32_complete_deactivate);
    
    GlobusXIOSystemDebugEnter();

    if (!globus_i_am_only_thread())
    {
        goto skip_deactivate;
    }

    globus_mutex_init(&info.mutex, NULL);
    globus_cond_init(&info.cond, NULL);
    
    globus_mutex_lock(&info.mutex);
    {
        result = globus_callback_unregister(
            globus_l_xio_win32_poll_handle,
            globus_l_xio_win32_unregister_poll_cb,
            &info,
            0);
            
        if(result == GLOBUS_SUCCESS)
        {
            /* unregister callback destroys this event object */
            while(globus_l_xio_win32_poll_event != 0)
            {
                globus_cond_wait(&info.cond, &info.mutex);
            }
        }
        else
        {
            globus_mutex_unlock(&info.mutex);
            globus_l_xio_win32_unregister_poll_cb(&info);
            globus_mutex_lock(&info.mutex);
        }
    }
    globus_mutex_unlock(&info.mutex);
    
    globus_cond_destroy(&info.cond);
    globus_mutex_destroy(&info.mutex);
    
    win32_mutex_destroy(&globus_l_xio_win32_poll_lock);
    
    while(globus_l_xio_win32_poll_free)
    {
        globus_l_xio_win32_poll_entry_t * next =
            globus_l_xio_win32_poll_free->next;
            
        globus_free(globus_l_xio_win32_poll_free);
        
        globus_l_xio_win32_poll_free = next;
    }
    
skip_deactivate:
    GlobusXIOSystemDebugExit();
    
    return GLOBUS_SUCCESS;
}

globus_result_t
globus_i_xio_win32_complete(
    globus_callback_func_t              callback,
    void *                              user_arg)
{
    globus_l_xio_win32_poll_entry_t *   entry;
    globus_result_t                     result;
    GlobusXIOName(globus_i_xio_win32_complete);

    GlobusXIOSystemDebugEnter();
    
    if (! globus_i_am_only_thread())
    {
        return globus_callback_register_oneshot(
            0,
            0,
            callback,
            user_arg);
    }

    win32_mutex_lock(&globus_l_xio_win32_poll_lock);
    {
        if(globus_l_xio_win32_poll_free)
        {
            entry = globus_l_xio_win32_poll_free;
            globus_l_xio_win32_poll_free = entry->next;
        }
        else
        {
            entry = (globus_l_xio_win32_poll_entry_t *)
                globus_malloc(sizeof(globus_l_xio_win32_poll_entry_t));
            if(!entry)
            {
                result = GlobusXIOErrorMemory("entry");
                goto error_malloc;
            }
        }
        
        entry->callback = callback;
        entry->user_arg = user_arg;
    
        GlobusLWin32PollQueueEnqueue(entry);
        
        if(globus_l_xio_win32_poll_event_sleeping &&
            !globus_l_xio_win32_poll_event_pending)
        {
            SetEvent(globus_l_xio_win32_poll_event);
            globus_l_xio_win32_poll_event_pending = GLOBUS_TRUE;
        }
    }
    win32_mutex_unlock(&globus_l_xio_win32_poll_lock);
    
    GlobusXIOSystemDebugExit();

    return GLOBUS_SUCCESS;

error_malloc:
    return result;
}
#endif /* _WIN32 */
