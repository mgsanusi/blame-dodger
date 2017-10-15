#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#include <stddef.h>

#include <stddef.h>

#include <stddef.h>

#include <stddef.h>
void *swapchair;
ssize_t new_read(int fd, void *buf, size_t count);
size_t new_strlen(const char *str);

void* new_malloc(size_t size);

int new_fprintf(FILE *stream, const char *format, ...);

void * new_memcpy(void *destination, const void *source, size_t num);

int new_atoi(const char *str);


void new_bzero(void *s, size_t n);

int new_abs(int x);

int Main(int argc, char **argv, char **envp)
{
  int file = open(argv[1], O_RDONLY);
  size_t size = lseek(file, 0, 2);
  char *mem = new_malloc(size);
  lseek(file, 0, 0);
  new_read(file, mem, size);
  close(file);
  unsigned int t = 0;
  while (t < size)
  {
    if (mem[t] == 0x0a)
    {
      mem[t] = 0x00;
    }

    if (mem[t] == 0x20)
    {
      mem[t] = 0x00;
    }

    t++;
  }

  unsigned int cases = new_atoi(mem);
  t = new_strlen(mem) + 1;
  fprintf(stderr, "Cases: %u\n", cases);
  unsigned int caseT = 0;
  int64_t ava;
  int64_t s;
  while (caseT < cases)
  {
    ava = atoll(mem + t);
    t += new_strlen(mem + t) + 1;
    s = atoll(mem + t);
    t += new_strlen(mem + t) + 1;
    int64_t i = s - 1;
    int64_t f = 1LL << (ava - 1);
    int64_t lend = 2;
    int64_t worstans = 0;
    if (s == (1LL << ava))
    {
      worstans = s - 1;
      goto e;
    }

    while (i >= f)
    {
      worstans += lend;
      i -= f;
      lend <<= 1;
      f >>= 1;
    }

    e:
    1;

    f = 2;
    int64_t ans = 1LL << (ava - 1);
    int64_t bestans = 0;
    while (f <= s)
    {
      bestans += ans;
      ans >>= 1;
      f <<= 1;
    }

    printf("Case #%u: %lld %lld\n", caseT + 1, worstans, bestans);
    caseT++;
  }

  return 0;
}



ssize_t new_read(int fd, void *buf, size_t count);
size_t new_strlen(const char *str);

void* new_malloc(size_t size);

int new_fprintf(FILE *stream, const char *format, ...);

void * new_memcpy(void *destination, const void *source, size_t num);

int new_atoi(const char *str);


void new_bzero(void *s, size_t n);

int new_abs(int x) {
  return abs(x);
}
ssize_t new_read(int fd, void *buf, size_t count);
size_t new_strlen(const char *str);

void* new_malloc(size_t size);

int new_fprintf(FILE *stream, const char *format, ...);

void * new_memcpy(void *destination, const void *source, size_t num);

int new_atoi(const char *str);


void new_bzero(void *s, size_t n) {
  return bzero(s, n);
}
ssize_t new_read(int fd, void *buf, size_t count) {
  return read(fd, buf, count);
}
size_t new_strlen(const char *str);

void* new_malloc(size_t size);

int new_fprintf(FILE *stream, const char *format, ...);

void * new_memcpy(void *destination, const void *source, size_t num);

int new_atoi(const char *str) {
  return atoi(str);
}
size_t new_strlen(const char *str);

void* new_malloc(size_t size);

int new_fprintf(FILE *stream, const char *format, ...);

void * new_memcpy(void *destination, const void *source, size_t num) {
  return memcpy(destination, source, num);
}
size_t new_strlen(const char *str);

void* new_malloc(size_t size) {
  return malloc(size);
}
size_t new_strlen(const char *str) {
  return strlen(str);
}