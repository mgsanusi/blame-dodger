#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int a[1 << 14][2];
int pw;
int primes[1 << 14];
int c[1 << 14];
int Main(void)
{
  int first_iteration;
  int nc;
  int b1;
  int iscorner;
  int time;
  int j;
  int a;
  for (scanf("%d", &nc), b1 = 1; b1 <= nc; b1++)
  {
    scanf("%d%d", &pw, &iscorner);
    for (time = 0; time < ((pw - 1) / 2); time++)
    {
      scanf("%d%d", &primes[time], &c[time]);
    }

    for (; time < pw; time++)
    {
      scanf("%d", &primes[time]);
    }

    memset(a, 0x3F3F3F3F, sizeof(a));
    for (time = pw - 1; time >= ((pw - 1) / 2); time--)
    {
      if (primes[time] == 0)
      {
        a[time][0] = 0;
        a[time][1] = 0x3F3F3F3F;
      }
      else
      {
        a[time][0] = 0x3F3F3F3F;
        a[time][1] = 0;
      }

    }

    for (; time >= 0; time--)
    {
      j = (time * 2) + 1;
      a = (time * 2) + 2;
      if (primes[time] == 0)
      {
        if ((a[j][0] < 0x3F3F3F3F) && (a[a][0] < 0x3F3F3F3F))
        {
          a[time][0] = a[j][0] + a[a][0];
        }

        if ((a[j][1] < 0x3F3F3F3F) || (a[a][1] < 0x3F3F3F3F))
        {
          a[time][1] = a[j][1] < a[a][1] ? a[j][1] : a[a][1];
        }

        if (c[time])
        {
          if ((a[j][0] < 0x3F3F3F3F) || (a[a][0] < 0x3F3F3F3F))
          {
            a[time][0] = a[time][0] < ((a[j][0] < a[a][0] ? a[j][0] : a[a][0]) + 1) ? a[time][0] : (a[j][0] < a[a][0] ? a[j][0] : a[a][0]) + 1;
          }

          if ((a[j][1] < 0x3F3F3F3F) && (a[a][1] < 0x3F3F3F3F))
          {
            a[time][1] = a[time][1] < ((a[j][1] + a[a][1]) + 1) ? a[time][1] : (a[j][1] + a[a][1]) + 1;
          }

        }

      }
      else
      {
        if ((a[j][0] < 0x3F3F3F3F) || (a[a][0] < 0x3F3F3F3F))
        {
          a[time][0] = a[j][0] < a[a][0] ? a[j][0] : a[a][0];
        }

        if ((a[j][1] < 0x3F3F3F3F) && (a[a][1] < 0x3F3F3F3F))
        {
          a[time][1] = a[j][1] + a[a][1];
        }

        if (c[time])
        {
          if ((a[j][0] < 0x3F3F3F3F) && (a[a][0] < 0x3F3F3F3F))
          {
            a[time][0] = a[time][0] < ((a[j][0] + a[a][0]) + 1) ? a[time][0] : (a[j][0] + a[a][0]) + 1;
          }

          if ((a[j][1] < 0x3F3F3F3F) || (a[a][1] < 0x3F3F3F3F))
          {
            a[time][1] = a[time][1] < ((a[j][1] < a[a][1] ? a[j][1] : a[a][1]) + 1) ? a[time][1] : (a[j][1] < a[a][1] ? a[j][1] : a[a][1]) + 1;
          }

        }

      }

    }

    printf("Case #%d: ", b1);
    if (a[0][iscorner] < 0x3F3F3F3F)
    {
      printf("%d\n", a[0][iscorner]);
    }
    else
    {
      printf("IMPOSSIBLE\n");
    }

  }

  return 0;
}


