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

  unsigned int cases = atoi(mem);
  r = strlen(mem) + 1;
  fprintf(stderr, "Cases: %u\n", cases);
  double n[100000];
  double r[100000];
  double p_g;
  double good;
  double is_there_solution;
  int k;
  int out;
  unsigned int case_t = 0;
  while (case_t < cases)
  {
    k = atoi(mem + r);
    r += strlen(mem + r) + 1;
    out = atoi(mem + r);
    r += strlen(mem + r) + 1;
    int t = 0;
    while (t < k)
    {
      n[t] = atof(mem + r);
      r += strlen(mem + r) + 1;
      t++;
    }

    p_g = 1.0;
    t = 0;
    while (t < k)
    {
      r[t] = p_g;
      p_g *= n[t];
      t++;
    }

    r[t] = p_g;
    good = 2110000.0;
    t = 0;
    while (t <= k)
    {
      is_there_solution = ((double) (((out + k) + 1) - (2 * t))) + ((out + 1) * (1.0 - r[t]));
      if (good > is_there_solution)
      {
        good = is_there_solution;
      }

      t++;
    }

    if (good > ((double) (out + 2)))
    {
      good = (double) (out + 2);
    }

    printf("Case #%u: %lf\n", case_t + 1, good);
    case_t++;
  }

  return 0;
}


