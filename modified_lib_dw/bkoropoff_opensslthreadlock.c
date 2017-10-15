#include <stdio.h>
#include <pthread.h>
#include <stddef.h>
#include <openssl/err.h>
void *new_malloc(size_t size);
void new_exit(int status);
void handle_error(const char *file, int lineno, const char *msg)
{
  int first_iteration;
  fprintf(stderr, "** %s:%d %s\n", file, lineno, msg);
  ERR_print_errors_fp(stderr);
}

static pthread_mutex_t *mutex_buf = 0;
static void locking_function(int mode, int n, const char *file, int line)
{
  int first_iteration;
  if (mode & CRYPTO_LOCK)
    pthread_mutex_lock(&mutex_buf[n]);
  else
    pthread_mutex_unlock(&mutex_buf[n]);

}

static unsigned long id_function(void)
{
  int first_iteration;
  return (unsigned long) pthread_self();
}

int thread_setup(void)
{
  int first_iteration;
  int i;
  mutex_buf = new_malloc(CRYPTO_num_locks() * (sizeof(pthread_mutex_t)));
  if (!mutex_buf)
    return 0;

  for (i = 0; i < CRYPTO_num_locks(); i++)
    pthread_mutex_init(&mutex_buf[i], 0);

  CRYPTO_set_id_callback(id_function);
  CRYPTO_set_locking_callback(locking_function);
  return 1;
}

int thread_cleanup(void)
{
  int first_iteration;
  int i;
  if (!mutex_buf)
    return 0;

  CRYPTO_set_id_callback(0);
  CRYPTO_set_locking_callback(0);
  for (i = 0; i < CRYPTO_num_locks(); i++)
    pthread_mutex_destroy(&mutex_buf[i]);

  free(mutex_buf);
  mutex_buf = 0;
  return 1;
}

void *new_malloc(size_t size);
void new_exit(int status)
{
  int first_iteration;
  return exit(status);
}

void *new_malloc(size_t size)
{
  int first_iteration;
  return malloc(size);
}


