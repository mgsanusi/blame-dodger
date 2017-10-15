#include "stdio.h"
#include "string.h"

#include <stddef.h>
char game[102][102];
int gain[102];
int count[102];
double iT[102];
double owp[102];
double oowp[102];
FILE * new_fopen(const char *filename, const char *mode);
void * new_memset(void *ptr, int value, int num);

int new_fclose(FILE *stream);


int new_fscanf(FILE *stream, const char *format, ...);

int Main(int argc, char **argv)
{
  int first_iteration;
  int x;
  int k;
  int bs;
  int res;
  int place;
  FILE *n;
  n = new_fopen(argv[1], "r");
  fscanf(n, "%d", &x);
  for (k = 1; k <= x; k++)
  {
    new_memset(game, 0, sizeof(game));
    new_memset(gain, 0, sizeof(gain));
    new_memset(count, 0, sizeof(count));
    new_memset(iT, 0, sizeof(iT));
    new_memset(owp, 0, sizeof(owp));
    new_memset(oowp, 0, sizeof(oowp));
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

  new_fclose(n);
  return 0;
}



FILE * new_fopen(const char *filename, const char *mode) {
  return fopen(filename, mode);
}
void * new_memset(void *ptr, int value, int num);

int new_fclose(FILE *stream) {
  return fclose(stream);
}
void * new_memset(void *ptr, int value, int num) {
  return memset(ptr, value, num);
}