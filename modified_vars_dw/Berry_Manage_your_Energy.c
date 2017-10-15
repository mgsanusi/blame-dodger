#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
int Main(int argc, char **argv, char **envp)
{
  int first_iteration;
  int file = open(argv[1], O_RDONLY);
  size_t size = lseek(file, 0, 2);
  char *mem = malloc(size);
  lseek(file, 0, 0);
  read(file, mem, size);
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

  unsigned int cases = atoi(mem);
  q = strlen(mem) + 1;
  fprintf(stderr, "Cases: %u\n", cases);
  unsigned int caseT = 0;
  int res[100];
  int ins;
  int l;
  int n;
  while (caseT < cases)
  {
    l = atoi(mem + q);
    q += strlen(mem + q) + 1;
    n = atoi(mem + q);
    q += strlen(mem + q) + 1;
    int l = 0;
    while (l < n)
    {
      res[l] = atoi(mem + q);
      q += strlen(mem + q) + 1;
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


