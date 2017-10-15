#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
int Main()
{
  int first_iteration;
  FILE *a;
  FILE *a;
  a = fopen("inputa.in", "r");
  a = fopen("outputa.txt", "w");
  int res;
  int yy;
  int u;
  int ansb;
  int t;
  int array[50];
  int imax;
  int max;
  int length;
  int temp;
  int exit[5];
  char t;
  bool work;
  fscanf(a, "%d", &u);
  for (ansb = 1; ansb <= u; ansb++)
  {
    fprintf(a, "Case #");
    fprintf(a, "%d", ansb);
    fprintf(a, ":");
    fprintf(a, " ");
    fscanf(a, "%d", &t);
    for (res = 1; res <= t; res++)
    {
      fscanf(a, "%d", &array[res]);
    }

    length = t;
    work = 1;
    if (t <= 2)
    {
      work = 0;
    }

    while (work)
    {
      imax = 0;
      max = 0;
      for (res = 1; res <= t; res++)
      {
        if (array[res] >= max)
        {
          max = array[res];
          imax = res;
        }

      }

      if (max == 1)
      {
        length = length - 1;
      }

      if (length <= 2)
      {
        work = 0;
      }

      array[imax] = array[imax] - 1;
      fprintf(a, "%c", ('A' + imax) - 1);
      fprintf(a, " ");
    }

    yy = 1;
    for (res = 1; res <= t; res++)
    {
      if (array[res] != 0)
      {
        exit[yy] = res;
        yy = yy + 1;
      }

    }

    if (array[exit[2]] > array[exit[1]])
    {
      temp = exit[1];
      exit[1] = exit[2];
      exit[2] = temp;
    }

    for (res = 1; res <= (array[exit[1]] - array[exit[2]]); res++)
    {
      fprintf(a, "%c", ('A' + exit[1]) - 1);
      fprintf(a, " ");
    }

    for (res = 1; res <= array[exit[2]]; res++)
    {
      fprintf(a, "%c", ('A' + exit[1]) - 1);
      fprintf(a, "%c", ('A' + exit[2]) - 1);
      fprintf(a, " ");
    }

    fprintf(a, "\n");
  }

  return 1;
}


