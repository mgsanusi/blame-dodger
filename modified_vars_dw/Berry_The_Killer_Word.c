#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
int Main(int argc, char **argv, char **envp)
{
  int first_iteration;
  int file = open(argv[1], O_RDONLY);
  size_t size = lseek(file, 0, 2);
  unsigned char *mem = malloc(size);
  lseek(file, 0, 0);
  read(file, mem, size);
  close(file);
  unsigned int l = 0;
  while (l < size)
  {
    if (mem[l] == 0x0a)
    {
      mem[l] = 0x00;
    }

    if (mem[l] == 0x20)
    {
      mem[l] = 0x00;
    }

    l++;
  }

  unsigned int cases = atoi(mem);
  l = strlen(mem) + 1;
  fprintf(stderr, "Cases: %u\n", cases);
  int64_t j;
  int64_t pD;
  int64_t pG;
  int64_t temp;
  unsigned possible;
  unsigned int caseT = 0;
  while (caseT < cases)
  {
    j = atoll(mem + l);
    l += strlen(mem + l) + 1;
    pD = atoll(mem + l);
    l += strlen(mem + l) + 1;
    pG = atoll(mem + l);
    l += strlen(mem + l) + 1;
    possible = 0;
    temp = 1;
    while ((temp < 101) && (temp <= j))
    {
      if (((temp * pD) % 100) == 0)
      {
        goto Skip;
      }

      temp++;
    }

    goto Impossible;
    Skip:
    1;

    if ((((pD == 100) && (pG == 0)) || ((pD != 100) && (pG == 100))) || ((pD != 0) && (pG == 0)))
    {
      goto Impossible;
    }

    possible = 1;
    Impossible:
    printf("Case #%u: %s\n", caseT + 1, possible == 1 ? "Possible" : "Broken");

    caseT++;
  }

  return 0;
}


