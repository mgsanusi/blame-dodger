/* Locale dependent string transformation for comparison.
   Copyright (C) 2010-2011 Free Software Foundation, Inc.
   Written by Bruno Haible <bruno@clisp.org>, 2010.
   This program is free software: you can redistribute it and/or modify it
   under the terms of the GNU Lesser General Public License as published
   by the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.
   You should have received a copy of the GNU Lesser General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */
#include <config.h>
#include <stddef.h>
#include <stddef.h>
#include <stddef.h>
/* Specification.  */
#include "astrxfrm.h"
#include <errno.h>
#include <stdlib.h>
#include <string.h>
void *new_malloc (size_t size);
void *new_memcpy (void *destination, const void *source, size_t num);
void *new_realloc (void *ptr, size_t size);
void new_free (void *ptr);
char *
astrxfrm (const char *s, char *resultbuf, size_t * lengthp)
{
  char tmpbuf[4000];
  char *result;			/* either == resultbuf or == tmpbuf or freshly allocated
				   or NULL.  */
  size_t allocated;		/* number of bytes allocated at result */
  size_t length;
  if (resultbuf != NULL)
    {
      result = resultbuf;
      allocated = *lengthp;
    }
  else
    {
      result = NULL;
      allocated = 0;
    }
  {
    size_t l = strlen (s);
    size_t k;
    /* A call to strxfrm costs about 20 times more than a call to strdup of
       the result.  Therefore it is worth to try to avoid calling strxfrm
       more than once on a given string, by making enough room before calling
       strxfrm.  The size of the strxfrm result, k, is likely to be between
       l and 3 * l.  */
    if (3 * l + 1 > allocated)
      {
	/* Grow the result buffer.  */
	if (3 * l + 1 <= sizeof (tmpbuf))
	  {
	    result = tmpbuf;
	    allocated = sizeof (tmpbuf);
	  }
	else
	  {
	    size_t new_allocated;
	    char *new_result;
	    new_allocated = 3 * l + 1;
	    if (new_allocated < 2 * allocated)
	      new_allocated = 2 * allocated;
	    new_result = (char *) new_malloc (new_allocated);
	    if (new_result != NULL)
	      {
		allocated = new_allocated;
		result = new_result;
	      }
	  }
      }
    errno = 0;
    k = strxfrm (result, s, allocated);
    if (errno != 0)
      goto fail;
    if (k >= allocated)
      {
	/* Grow the result buffer.  */
	if (result != resultbuf && result != tmpbuf)
	  new_free (result);
	if (k + 1 <= sizeof (tmpbuf))
	  {
	    result = tmpbuf;
	    allocated = sizeof (tmpbuf);
	  }
	else
	  {
	    size_t new_allocated;
	    char *new_result;
	    new_allocated = k + 1;
	    new_result = (char *) new_malloc (new_allocated);
	    if (new_result == NULL)
	      goto out_of_memory;
	    allocated = new_allocated;
	    result = new_result;
	  }
	/* Here k < allocated.  */
	/* Try again.  */
	errno = 0;
	if (strxfrm (result, s, allocated) != k)
	  /* strxfrm() is not producing reproducible results.  */
	  abort ();
	if (errno != 0)
	  goto fail;
      }
    /* Verify that strxfrm() has NUL-terminated the result.  */
    if (result[k] != '\0')
      abort ();
    length = k + 1;
  }
  /* Here length > 0.  */
  if (result == tmpbuf)
    {
      if (resultbuf != NULL && length <= *lengthp)
	{
	  new_memcpy (resultbuf, result, length);
	  result = resultbuf;
	}
      else
	{
	  char *memory = (char *) new_malloc (length);
	  if (memory == NULL)
	    goto out_of_memory;
	  new_memcpy (memory, result, length);
	  result = memory;
	}
    }
  else
    {
      /* Shrink the allocated memory if possible.  */
      if (result != resultbuf && length < allocated)
	{
	  if (length <= *lengthp)
	    {
	      new_memcpy (resultbuf, result, length);
	      new_free (result);
	      result = resultbuf;
	    }
	  else
	    {
	      char *memory = (char *) new_realloc (result, length);
	      if (memory != NULL)
		{
		  new_memcpy (memory, result, length);
		  result = memory;
		}
	    }
	}
    }
  *lengthp = length;
  return result;
fail:
  {
    int saved_errno = errno;
    if (result != resultbuf && result != tmpbuf)
      new_free (result);
    errno = saved_errno;
    return NULL;
  }
out_of_memory:
  errno = ENOMEM;
  return NULL;
}

void *new_malloc (size_t size);
void *new_memcpy (void *destination, const void *source, size_t num);
void *new_realloc (void *ptr, size_t size);
void
new_free (void *ptr)
{
  return free (ptr);
}

void *new_malloc (size_t size);
void *new_memcpy (void *destination, const void *source, size_t num);
void *
new_realloc (void *ptr, size_t size)
{
  return realloc (ptr, size);
}

void *new_malloc (size_t size);
void *
new_memcpy (void *destination, const void *source, size_t num)
{
  return memcpy (destination, source, num);
}

void *
new_malloc (size_t size)
{
  return malloc (size);
}
