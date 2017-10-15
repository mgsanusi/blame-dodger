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

    q++;
  }

  unsigned int cases = atoi(mem);
  q = strlen(mem) + 1;
  fprintf(stderr, "Cases: %u\n", cases);
  int trans[26] = {121, 104, 101, 115, 111, 99, 118, 120, 100, 117, 105, 103, 108, 98, 107, 114, 122, 116, 110, 119, 106, 112, 102, 109, 97, 113};
  unsigned int case_t = 0;
  while (case_t < cases)
  {
    int bd = 0;
    char *a = mem + q;
    int num = strlen(mem + q);
    while (bd < num)
    {
      if ((mem[q + bd] <= 'z') && (mem[q + bd] >= 'a'))
      {
        mem[q + bd] = trans[mem[q + bd] - 'a'];
      }

      bd++;
    }

    q += strlen(mem + q) + 1;
    printf("Case #%u: %s\n", case_t + 1, a);
    case_t++;
  }

  return 0;
}


