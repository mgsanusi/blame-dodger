#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
int Main(int argc, char **argv, char **envp)
{
  int file = open(argv[1], O_RDONLY);
  size_t size = lseek(file, 0, 2);
  char *mem = malloc(size);
  lseek(file, 0, 0);
  read(file, mem, size);
  close(file);
  unsigned int c = 0;
  while (c < size)
  {
    if (mem[c] == 0x0a)
    {
      mem[c] = 0x00;
    }

    if (mem[c] == 0x20)
    {
      mem[c] = 0x00;
    }

    c++;
  }

  unsigned int cases = atoi(mem);
  c = strlen(mem) + 1;
  fprintf(stderr, "Cases: %u\n", cases);
  double n[100000];
  double w[100000];
  double j;
  double good;
  double a;
  int a;
  int w;
  unsigned int case_t = 0;
  while (case_t < cases)
  {
    a = atoi(mem + c);
    c += strlen(mem + c) + 1;
    w = atoi(mem + c);
    c += strlen(mem + c) + 1;
    int s = 0;
    while (s < a)
    {
      n[s] = atof(mem + c);
      c += strlen(mem + c) + 1;
      s++;
    }

    j = 1.0;
    s = 0;
    while (s < a)
    {
      w[s] = j;
      j *= n[s];
      s++;
    }

    w[s] = j;
    good = 2110000.0;
    s = 0;
    while (s <= a)
    {
      a = ((double) (((w + a) + 1) - (2 * s))) + ((w + 1) * (1.0 - w[s]));
      if (good > a)
      {
        good = a;
      }

      s++;
    }

    if (good > ((double) (w + 2)))
    {
      good = (double) (w + 2);
    }

    printf("Case #%u: %lf\n", case_t + 1, good);
    case_t++;
  }

  return 0;
}


