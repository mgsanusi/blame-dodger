#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

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
  unsigned int a = 0;
  while (a < size)
  {
    if (mem[a] == 0x0a)
    {
      mem[a] = 0x00;
    }

    if (mem[a] == 0x20)
    {
      mem[a] = 0x00;
    }

    a++;
  }

  unsigned int subject = new_atoi(mem);
  a = new_strlen(mem) + 1;
  fprintf(stderr, "Cases: %u\n", subject);
  unsigned int j;
  unsigned char who;
  unsigned int button[100];
  unsigned int pers[100];
  unsigned int perPo[2];
  unsigned int perTime[2];
  unsigned int y1;
  unsigned int time;
  unsigned int temp;
  unsigned int caseT = 0;
  while (caseT < subject)
  {
    j = new_atoi(mem + a);
    a += new_strlen(mem + a) + 1;
    y1 = 0;
    while (y1 < j)
    {
      who = mem[a];
      a += new_strlen(mem + a) + 1;
      if (who == 'O')
      {
        pers[y1] = 0;
      }
      else
      {
        pers[y1] = 1;
      }

      button[y1] = new_atoi(mem + a);
      a += new_strlen(mem + a) + 1;
      y1++;
    }

    perPo[0] = 1;
    perPo[1] = 1;
    perTime[0] = 0;
    perTime[1] = 0;
    time = 0;
    y1 = 0;
    while (y1 < j)
    {
      if (button[y1] > perPo[pers[y1]])
      {
        temp = button[y1] - perPo[pers[y1]];
      }
      else
      {
        temp = perPo[pers[y1]] - button[y1];
      }

      if (temp > (time - perTime[pers[y1]]))
      {
        temp -= time - perTime[pers[y1]];
      }
      else
      {
        temp = 0;
      }

      temp += 1;
      time += temp;
      perPo[pers[y1]] = button[y1];
      perTime[pers[y1]] = time;
      y1++;
    }

    printf("Case #%u: %u\n", caseT + 1, time);
    caseT++;
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