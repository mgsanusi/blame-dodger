#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#include <stddef.h>

#include <stddef.h>
int new_strlen(const char *str);

void* new_malloc(int size);

int new_atoi(const char *str);

int new_read(int fd, void *buf, int count);

int Main(int argc, char **argv, char **envp)
{
  int first_iteration;
  int file = open(argv[1], O_RDONLY);
  size_t size = lseek(file, 0, 2);
  unsigned char *mem = new_malloc(size);
  lseek(file, 0, 0);
  new_read(file, mem, size);
  close(file);
  unsigned int r = 0;
  while (r < size)
  {
    if (mem[r] == 0x0a)
    {
      mem[r] = 0x00;
    }

    if (mem[r] == 0x20)
    {
      mem[r] = 0x00;
    }

    r++;
  }

  unsigned int cases = new_atoi(mem);
  r = new_strlen(mem) + 1;
  fprintf(stderr, "Cases: %u\n", cases);
  int s;
  int tmp;
  char print[9];
  int l;
  int i;
  int use[9];
  int nused;
  char chair;
  int64_t result;
  unsigned int case_t = 0;
  while (case_t < cases)
  {
    s = new_atoi(mem + r);
    r += new_strlen(mem + r) + 1;
    tmp = new_atoi(mem + r);
    r += new_strlen(mem + r) + 1;
    result = 0;
    int fp_in = s;
    while (fp_in <= tmp)
    {
      sprintf(print, "%d", fp_in);
      nused = 0;
      l = new_strlen(print);
      int t = 1;
      while (t < l)
      {
        chair = print[0];
        memmove(print, print + 1, 8);
        print[l - 1] = chair;
        print[l] = 0x00;
        sscanf(print, "%d", &i);
        if ((i <= tmp) && (i >= s))
        {
          if (i > fp_in)
          {
            int k = 0;
            while (k < nused)
            {
              if (use[k] == i)
              {
                break;
              }

              k++;
            }

            if (k == nused)
            {
              use[k] = i;
              nused++;
              result++;
            }

          }

        }

        t++;
      }

      fp_in++;
    }

    printf("Case #%u: %lld\n", case_t + 1, (long long int) result);
    case_t++;
  }

  return 0;
}



int new_strlen(const char *str);

void* new_malloc(int size);

int new_atoi(const char *str);

int new_read(int fd, void *buf, int count) {
  return read(fd, buf, count);
}
int new_strlen(const char *str);

void* new_malloc(int size);

int new_atoi(const char *str) {
  return atoi(str);
}
int new_strlen(const char *str);

void* new_malloc(int size) {
  return malloc(size);
}
int new_strlen(const char *str) {
  return strlen(str);
}