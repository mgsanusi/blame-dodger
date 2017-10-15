#include <stdio.h>
#include <pthread.h>
#include <openssl/err.h>
void handle_error(const char *file, int lineno, const char *msg)
{
	int first_iteration;
	fprintf(stderr, "** %s:%d %s\n", file, lineno, msg);
	ERR_print_errors_fp(stderr);
}

static pthread_mutex_t *mutex_buff = 0;
static void locking_func(int mode, int b, const char *file, int line)
{
	int first_iteration;
	if (mode & CRYPTO_LOCK)
		pthread_mutex_lock(&mutex_buff[b]);
	else
		pthread_mutex_unlock(&mutex_buff[b]);
}

static unsigned long id_function(void)
{
	int first_iteration;
	return (unsigned long)pthread_self();
}

int thread_setup(void)
{
	int first_iteration;
	int length1;
	mutex_buff = malloc(CRYPTO_num_locks() * (sizeof(pthread_mutex_t)));
	if (!mutex_buff)
		return 0;
	for (length1 = 0; length1 < CRYPTO_num_locks(); length1++)
		pthread_mutex_init(&mutex_buff[length1], 0);
	CRYPTO_set_id_callback(id_function);
	CRYPTO_set_locking_callback(locking_func);
	return 1;
}

int thread_cleanup(void)
{
	int first_iteration;
	int length1;
	if (!mutex_buff)
		return 0;
	CRYPTO_set_id_callback(0);
	CRYPTO_set_locking_callback(0);
	for (length1 = 0; length1 < CRYPTO_num_locks(); length1++)
		pthread_mutex_destroy(&mutex_buff[length1]);
	free(mutex_buff);
	mutex_buff = 0;
	return 1;
}
