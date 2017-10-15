#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#include <stddef.h>

#include <stddef.h>
ssize_t new_read(int fd, void *buf, size_t count);
size_t new_strlen(const char *str);

void* new_malloc(size_t size);

int new_atoi(const char *str);


int Main(int argc, char **argv, char **envp)
{
  int file = open(argv[1], O_RDONLY);
  size_t size = lseek(file, 0, 2);
  char *mem = new_malloc(size);
  lseek(file, 0, 0);
  new_read(file, mem, size);
  close(file);
  unsigned int q = 0;
  while (q < size)
  {
    if (mem[q] == 0x0a)
    {
      mem[q] = 0x00;
    }

    if (mem[q] == 0x20)
    {
      mem[q] = 0x00;
    }

    q++;
  }

  unsigned int cases = new_atoi(mem);
  q = new_strlen(mem) + 1;
  fprintf(stderr, "Cases: %u\n", cases);
  unsigned int caseT = 0;
  int res[100];
  int ins;
  int l;
  int n;
  while (caseT < cases)
  {
    l = new_atoi(mem + q);
    q += new_strlen(mem + q) + 1;
    n = new_atoi(mem + q);
    q += new_strlen(mem + q) + 1;
    int l = 0;
    while (l < n)
    {
      res[l] = new_atoi(mem + q);
      q += new_strlen(mem + q) + 1;
      l++;
    }

    int y = n;
    while (y > 1)
    {
      l = 0;
      while (l < (y - 1))
      {
        if (res[l] > res[l + 1])
        {
          int s = res[l];
          res[l] = res[l + 1];
          res[l + 1] = s;
        }

        l++;
      }

      y--;
    }

    int answer = n;
    if (l == 1)
    {
      goto End;
    }

    int b1 = 0;
    int c = l;
    l = 0;
    while (l < n)
    {
      if (c > res[l])
      {
        c += res[l];
      }
      else
      {
        while (c <= res[l])
        {
          c += c - 1;
          b1++;
        }

        c += res[l];
      }

      ins = b1 + ((n - 1) - l);
      if (answer > ins)
      {
        answer = ins;
      }

      l++;
    }

    End:
    printf("Case #%u: %d\n", caseT + 1, answer);

    caseT++;
  }

  return 0;
}



ssize_t new_read(int fd, void *buf, size_t count) {
  return read(fd, buf, count);
}
size_t new_strlen(const char *str);

void* new_malloc(size_t size);

int new_atoi(const char *str) {
  return atoi(str);
}
size_t new_strlen(const char *str);

void* new_malloc(size_t size) {
  return malloc(size);
}
size_t new_strlen(const char *str) {
  return strlen(str);
}