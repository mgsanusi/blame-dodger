#include "stdio.h"
#include "string.h"
char game[102][102];
int gain[102];
int count[102];
double iT[102];
double owp[102];
double oowp[102];
int Main(int argc, char **argv)
{
  int first_iteration;
  int x;
  int k;
  int bs;
  int res;
  int place;
  FILE *n;
  n = fopen(argv[1], "r");
  fscanf(n, "%d", &x);
  for (k = 1; k <= x; k++)
  {
    memset(game, 0, sizeof(game));
    memset(gain, 0, sizeof(gain));
    memset(count, 0, sizeof(count));
    memset(iT, 0, sizeof(iT));
    memset(owp, 0, sizeof(owp));
    memset(oowp, 0, sizeof(oowp));
    fscanf(n, "%d ", &bs);
    char c;
    for (res = 0; res < bs; res++)
    {
      for (place = 0; place < bs; place++)
      {
        fscanf(n, "%c", &game[res][place]);
      }

      fscanf(n, "%c", &c);
    }

    for (res = 0; res < bs; res++)
    {
      for (place = 0; place < bs; place++)
      {
        if (game[res][place] == '1')
        {
          gain[res]++;
          count[res]++;
        }
        else
          if (game[res][place] == '0')
        {
          count[res]++;
        }


      }

    }

    for (res = 0; res < bs; res++)
    {
      iT[res] = ((double) gain[res]) / count[res];
    }

    for (res = 0; res < bs; res++)
    {
      for (place = 0; place < bs; place++)
      {
        if (game[res][place] == '1')
        {
          owp[res] += ((double) gain[place]) / (count[place] - 1);
        }
        else
          if (game[res][place] == '0')
        {
          owp[res] += ((double) (gain[place] - 1)) / (count[place] - 1);
        }


      }

      owp[res] /= count[res];
    }

    for (res = 0; res < bs; res++)
    {
      for (place = 0; place < bs; place++)
      {
        if (game[res][place] != '.')
        {
          oowp[res] += owp[place];
        }

      }

      oowp[res] /= count[res];
    }

    printf("Case #%d:\n", k);
    for (res = 0; res < bs; res++)
    {
      printf("%lf\n", ((0.25 * iT[res]) + (0.50 * owp[res])) + (0.25 * oowp[res]));
    }

  }

  fclose(n);
  return 0;
}


