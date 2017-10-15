#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stddef.h>
int16_t reach[2][2][2][721];
uint8_t take[2][1440];
int ti;
int tn;
int i;
int j;
int k;
int n;
int m;
int ans;
void *new_memset(void *ptr, int value, size_t num);
int new_fscanf(FILE *stream, const char *format, ...);
int new_fprintf(FILE *stream, const char *format, ...);
int main()
{
  int first_iteration;
  fscanf(stdin, "%d", &tn);
  for (ti = 1; ti <= tn; ++ti)
  {
    fprintf(stdout, "Case #%d: ", ti);
    new_memset(take, 0, sizeof(take));
    fscanf(stdin, "%d%d", &n, &m);
    for (i = 0; i < n; ++i)
    {
      fscanf(stdin, "%d%d", &j, &k);
      for (; j < k; ++j)
        take[0][j] = 1;

    }

    for (i = 0; i < m; ++i)
    {
      fscanf(stdin, "%d%d", &j, &k);
      for (; j < k; ++j)
        take[1][j] = 1;

    }

    new_memset(reach[0], 0, sizeof(reach[0]));
    if (!take[0][0])
      reach[0][0][0][1] = 1;

    if (!take[1][0])
      reach[0][1][1][0] = 1;

    for (i = 1; i < 1440; ++i)
    {
      new_memset(reach[i & 1], 0, sizeof(reach[i & 1]));
      for (j = 0; j < 2; ++j)
        for (k = 0; k <= 720; ++k)
      {
        if (!take[0][i])
        {
          if ((k > 0) && reach[1 - (i & 1)][j][0][k - 1])
            reach[i & 1][j][0][k] = reach[1 - (i & 1)][j][0][k - 1];

          if (((k > 0) && reach[1 - (i & 1)][j][1][k - 1]) && ((!reach[i & 1][j][0][k]) || ((reach[1 - (i & 1)][j][1][k - 1] + 1) < reach[i & 1][j][0][k])))
            reach[i & 1][j][0][k] = reach[1 - (i & 1)][j][1][k - 1] + 1;

        }

        if (!take[1][i])
        {
          if (reach[1 - (i & 1)][j][1][k])
            reach[i & 1][j][1][k] = reach[1 - (i & 1)][j][1][k];

          if (reach[1 - (i & 1)][j][0][k] && ((!reach[i & 1][j][1][k]) || ((reach[1 - (i & 1)][j][0][k] + 1) < reach[i & 1][j][1][k])))
            reach[i & 1][j][1][k] = reach[1 - (i & 1)][j][0][k] + 1;

        }

      }


    }

    for (ans = reach[1][0][0][720], i = 0; i < 2; ++i)
      for (j = 0; j < 2; ++j)
      if (reach[1][i][j][720] && ((ans == 0) || ((reach[1][i][j][720] - (i == j ? 1 : 0)) < ans)))
      ans = reach[1][i][j][720] - (i == j ? 1 : 0);



    fprintf(stdout, "%d\n", ans);
  }

  return 0;
}

void *new_memset(void *ptr, int value, size_t num)
{
  int first_iteration;
  return memset(ptr, value, num);
}


