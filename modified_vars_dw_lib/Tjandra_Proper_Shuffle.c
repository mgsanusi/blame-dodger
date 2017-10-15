#include<stdio.h>
#include<string.h>
typedef unsigned u;
char b[111][111];
char time[111][111];
u queenf[111][111];
int Main()
{
  int first_iteration;
  u fpI = 0;
  u q;
  u size;
  u rep;
  u j;
  u k;
  u array;
  u xdrs;
  u y;
  u ret;
  u m;
  for (scanf("%u", &q); (fpI++) < q;)
  {
    scanf("%u", &size);
    for (rep = 0; rep < size; rep++)
    {
      scanf("%s", b[rep]);
      time[rep][0] = b[rep][0];
      array = 0;
      for (j = (k = (xdrs = 1)); b[rep][j]; j++, xdrs++)
      {
        if (b[rep][j] != b[rep][j - 1])
        {
          time[rep][k++] = b[rep][j];
          queenf[rep][array++] = xdrs;
          xdrs = 0;
        }

      }

      time[rep][k] = '\0';
      queenf[rep][array++] = xdrs;
    }

    printf("Case #%u: ", fpI);
    for (rep = 0; (++rep) < size;)
    {
      if (strcmp(time[rep], time[rep - 1]))
      {
        printf("Fegla Won\n");
        goto fin;
      }

    }

    for (ret = (j = 0); j < array; j++)
    {
      m = 0;
      for (rep = 0; rep < size; rep++)
        if (queenf[rep][j] > m)
        m = queenf[rep][j];


      y = 1000;
      for (xdrs = 0; (xdrs++) < m;)
      {
        for (rep = (k = 0); rep < size; rep++)
        {
          k += xdrs > queenf[rep][j] ? xdrs - queenf[rep][j] : queenf[rep][j] - xdrs;
        }

        if (y > k)
          y = k;

      }

      ret += y;
    }

    printf("%u\n", ret);
    fin:
    ;

  }

  return 0;
}


