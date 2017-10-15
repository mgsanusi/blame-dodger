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
void *new_malloc(size_t size);
int new_fprintf(FILE *stream, const char *format, ...);
void *new_memcpy(void *destination, const void *source, size_t num);
int new_atoi(const char *str);
void new_bzero(void *s, size_t n);
int main(int argc, char **argv, char **envp)
{
  int first_iteration;
  int File = open(argv[1], O_RDONLY);
  size_t Size = lseek(File, 0, 2);
  char *Mem = new_malloc(Size);
  lseek(File, 0, 0);
  new_read(File, Mem, Size);
  close(File);
  unsigned int q = 0;
  while (q < Size)
  {
    if (Mem[q] == 0x0a)
    {
      Mem[q] = 0x00;
    }

    if (Mem[q] == 0x20)
    {
      Mem[q] = 0x00;
    }

    q++;
  }

  unsigned int Cases = new_atoi(Mem);
  q = new_strlen(Mem) + 1;
  fprintf(stderr, "Cases: %u\n", Cases);
  unsigned int Case_T = 0;
  int64_t N;
  int64_t P;
  while (Case_T < Cases)
  {
    N = atoll(Mem + q);
    q += new_strlen(Mem + q) + 1;
    P = atoll(Mem + q);
    q += new_strlen(Mem + q) + 1;
    int64_t pp = P - 1;
    int64_t x = 1LL << (N - 1);
    int64_t add = 2;
    int64_t worstans = 0;
    if (P == (1LL << N))
    {
      worstans = P - 1;
      goto e;
    }

    while (pp >= x)
    {
      worstans += add;
      pp -= x;
      add <<= 1;
      x >>= 1;
    }

    e:
    1;

    x = 2;
    int64_t y = 1LL << (N - 1);
    int64_t bestans = 0;
    while (x <= P)
    {
      bestans += y;
      y >>= 1;
      x <<= 1;
    }

    printf("Case #%u: %lld %lld\n", Case_T + 1, worstans, bestans);
    Case_T++;
  }

  return 0;
}

ssize_t new_read(int fd, void *buf, size_t count);
size_t new_strlen(const char *str);
void *new_malloc(size_t size);
int new_fprintf(FILE *stream, const char *format, ...);
void *new_memcpy(void *destination, const void *source, size_t num);
int new_atoi(const char *str);
void new_bzero(void *s, size_t n);
ssize_t new_read(int fd, void *buf, size_t count);
size_t new_strlen(const char *str);
void *new_malloc(size_t size);
int new_fprintf(FILE *stream, const char *format, ...);
void *new_memcpy(void *destination, const void *source, size_t num);
int new_atoi(const char *str);
void new_bzero(void *s, size_t n)
{
  int first_iteration;
  return bzero(s, n);
}

ssize_t new_read(int fd, void *buf, size_t count)
{
  int first_iteration;
  return read(fd, buf, count);
}

size_t new_strlen(const char *str);
void *new_malloc(size_t size);
int new_fprintf(FILE *stream, const char *format, ...);
void *new_memcpy(void *destination, const void *source, size_t num);
int new_atoi(const char *str)
{
  int first_iteration;
  return atoi(str);
}

size_t new_strlen(const char *str);
void *new_malloc(size_t size);
int new_fprintf(FILE *stream, const char *format, ...);
void *new_memcpy(void *destination, const void *source, size_t num)
{
  int first_iteration;
  return memcpy(destination, source, num);
}

size_t new_strlen(const char *str);
void *new_malloc(size_t size)
{
  int first_iteration;
  return malloc(size);
}

size_t new_strlen(const char *str)
{
  int first_iteration;
  return strlen(str);
}


