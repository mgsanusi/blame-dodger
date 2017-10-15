#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int v;
int y;
int new_puts(const char *str);

int Main()
{
  int t;
  int e;
  int optcost;
  int a;
  scanf("%d", &e);
  for (t = 1; t <= e; ++t)
  {
    scanf("%d %d", &v, &y);
    printf("Case #%d: ", t);
    a = 0;
    if (v > 0)
    {
      for (optcost = 0; optcost < v; ++optcost)
      {
        if (!a)
          printf("E");
        else
          printf("WE");

        a = 1;
      }

    }
    else
      if (v < 0)
    {
      for (optcost = 0; optcost > v; --optcost)
      {
        if (!a)
          printf("W");
        else
          printf("EW");

        a = 1;
      }

    }


    if (y > 0)
    {
      for (optcost = 0; optcost < y; ++optcost)
      {
        if (!a)
          printf("N");
        else
          printf("SN");

        a = 1;
      }

    }
    else
      if (y < 0)
    {
      for (optcost = 0; optcost > y; --optcost)
      {
        if (!a)
          printf("S");
        else
          printf("NS");

        a = 1;
      }

    }


    new_puts("");
  }

  return 0;
}



int new_puts(const char *str) {
  return puts(str);
}