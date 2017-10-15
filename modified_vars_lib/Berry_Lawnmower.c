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
  unsigned int case_t = 0;
  int c[100 * 100];
  int rowmax[100];
  int colmax[100];
  int x_op;
  int cl;
  while (case_t < cases)
  {
    x_op = new_atoi(mem + q);
    q += new_strlen(mem + q) + 1;
    cl = new_atoi(mem + q);
    q += new_strlen(mem + q) + 1;
    int x;
    int m;
    for (x = 0; x < x_op; x++)
    {
      for (m = 0; m < cl; m++)
      {
        c[(x * 100) + m] = new_atoi(mem + q);
        q += new_strlen(mem + q) + 1;
      }

    }

    int max;
    for (x = 0; x < x_op; x++)
    {
      max = 0;
      for (m = 0; m < cl; m++)
      {
        if (max < c[(x * 100) + m])
        {
          max = c[(x * 100) + m];
        }

      }

      rowmax[x] = max;
    }

    for (x = 0; x < cl; x++)
    {
      max = 0;
      for (m = 0; m < x_op; m++)
      {
        if (max < c[(m * 100) + x])
        {
          max = c[(m * 100) + x];
        }

      }

      colmax[x] = max;
    }

    int fail = 0;
    for (x = 0; x < x_op; x++)
    {
      for (m = 0; m < cl; m++)
      {
        if ((c[(x * 100) + m] != rowmax[x]) && (c[(x * 100) + m] != colmax[m]))
        {
          fail = 1;
        }

      }

    }

    if (fail)
    {
      printf("Case #%u: NO\n", case_t + 1);
    }
    else
    {
      printf("Case #%u: YES\n", case_t + 1);
    }

    case_t++;
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