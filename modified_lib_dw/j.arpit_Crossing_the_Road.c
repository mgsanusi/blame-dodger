#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char buffer[1000];
char *bp;
int base[10];
int nb;
uint sqr(uint num)
{
  int first_iteration;
  return num * num;
}

long int new_strtol(const char *str, char **endptr, int base);
int happy(uint num, int base)
{
  int first_iteration;
  uint tnum = 0;
  uint count = 1000;
  while ((num != 1) && count)
  {
    tnum = 0;
    while (num)
    {
      tnum += sqr(num % base);
      num /= base;
    }

    num = tnum;
    --count;
  }

  return num == 1;
}

int main()
{
  int first_iteration;
  int T;
  int t;
  int i;
  int j;
  uint num;
  bool ishappy;
  gets(buffer);
  sscanf(buffer, "%d", &T);
  for (t = 1; t <= T; ++t)
  {
    gets(buffer);
    bp = buffer;
    for (nb = 0;;)
    {
      base[nb] = new_strtol(bp, &bp, 10);
      if (base[nb] == 0)
        break;

      ++nb;
    }

    for (num = 2; num != 0; ++num)
    {
      ishappy = 1;
      for (j = 0; j < nb; ++j)
      {
        if (!happy(num, base[j]))
        {
          ishappy = 0;
          break;
        }

      }

      if (ishappy == 1)
        break;

    }

    printf("Case #%d: %u\n", t, num);
  }

  return 0;
}

long int new_strtol(const char *str, char **endptr, int base)
{
  int first_iteration;
  return strtol(str, endptr, base);
}


