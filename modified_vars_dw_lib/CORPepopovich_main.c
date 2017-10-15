#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#include <stddef.h>
static const size_t alloc_sizes[] = {512, 4 * 1024, 16 * 1024, 64 * 1024, 68 * 1024, 128 * 1024, 256 * 1024, 1024 * 1024};
static void *string_main(void *p)
{
  int first_iteration;
  void *mem = 0;
  int srcs = 0;
  size_t alloc_size = *((size_t *) p);
  for (srcs = 0; srcs < 1000000; ++srcs)
  {
    mem = new_malloc(alloc_size);
    free(mem);
  }

  return 0;
}
void* new_malloc(int size);

int new_fprintf(FILE *stream, const char *format, ...);

void new_exit(int status);


int Main(int argc, char **argv)
{
  int first_iteration;
  int srcs = 0;
  int md = 0;
  int err = 0;
  pthread_t thread[32] = {0};
  for (md = 0; md < ((sizeof(alloc_sizes)) / (sizeof(*alloc_sizes))); ++md)
  {
    struct timespec start_time = {0};
    struct timespec end_time = {0};
    long time_diff_nsec = 0;
    for (srcs = 0; srcs < 32; ++srcs)
    {
      if ((err = pthread_create(&thread[srcs], 0, string_main, (void *) (&alloc_sizes[md]))) != 0)
      {
        fprintf(stderr, "ERROR: %d\n", err);
        new_exit(1);
      }

    }

    if (clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start_time) == (-1))
    {
      fprintf(stderr, "ERROR: %m");
      new_exit(1);
    }

    for (srcs = 0; srcs < 32; ++srcs)
    {
      if ((err = pthread_join(thread[srcs], 0)) != 0)
      {
        fprintf(stderr, "ERROR: %d\n", err);
        new_exit(1);
      }

    }

    if (clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end_time) == (-1))
    {
      fprintf(stderr, "ERROR: %m");
      new_exit(1);
    }

    time_diff_nsec = ((end_time.tv_sec - start_time.tv_sec) * 1000000000) + (end_time.tv_nsec - start_time.tv_nsec);
    printf("Allocations for %.7u bytes took \t%f(ms) per allocation\n", alloc_sizes[md], ((time_diff_nsec / ((double) 1000000)) / ((double) 1000000)) / ((double) 32));
  }

  return 0;
}



void* new_malloc(int size);

int new_fprintf(FILE *stream, const char *format, ...);

void new_exit(int status) {
  return exit(status);
}
void* new_malloc(int size) {
  return malloc(size);
}