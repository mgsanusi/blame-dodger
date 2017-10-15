#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stddef.h>
#include <stddef.h>
ssize_t new_read(int fd, void *buf, size_t count);
size_t new_strlen(const char *str);
void *new_malloc(size_t size);
int new_atoi(const char *str);
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

    q++;
  }

  unsigned int Cases = new_atoi(Mem);
  q = new_strlen(Mem) + 1;
  fprintf(stderr, "Cases: %u\n", Cases);
  int Trans[26] = {121, 104, 101, 115, 111, 99, 118, 120, 100, 117, 105, 103, 108, 98, 107, 114, 122, 116, 110, 119, 106, 112, 102, 109, 97, 113};
  unsigned int Case_T = 0;
  while (Case_T < Cases)
  {
    int x = 0;
    char *a = Mem + q;
    int y = new_strlen(Mem + q);
    while (x < y)
    {
      if ((Mem[q + x] <= 'z') && (Mem[q + x] >= 'a'))
      {
        Mem[q + x] = Trans[Mem[q + x] - 'a'];
      }

      x++;
    }

    q += new_strlen(Mem + q) + 1;
    printf("Case #%u: %s\n", Case_T + 1, a);
    Case_T++;
  }

  return 0;
}

ssize_t new_read(int fd, void *buf, size_t count)
{
  int first_iteration;
  return read(fd, buf, count);
}

size_t new_strlen(const char *str);
void *new_malloc(size_t size);
int new_atoi(const char *str)
{
  int first_iteration;
  return atoi(str);
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


