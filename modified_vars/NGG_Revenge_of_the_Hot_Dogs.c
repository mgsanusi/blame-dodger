#include <stdio.h>
char t[110][110];
int gain[110];
int all[110];
double cs[110];
double owp[110];
double oowp[110];
int Main(void)
{
  int ti;
  int vx;
  scanf("%d", &vx);
  for (ti = 1; ti <= vx; ti++)
  {
    int c;
    int i;
    int ha;
    scanf("%d\n", &c);
    for (i = 0; i < c; i++)
    {
      gets(t[i]);
    }

    for (i = 0; i < c; i++)
    {
      all[i] = (gain[i] = 0);
      for (ha = 0; ha < c; ha++)
      {
        if (t[i][ha] != '.')
          all[i]++;

        if (t[i][ha] == '1')
          gain[i]++;

      }

      cs[i] = ((double) gain[i]) / ((double) all[i]);
    }

    for (i = 0; i < c; i++)
    {
      owp[i] = 0;
      for (ha = 0; ha < c; ha++)
      {
        if (t[i][ha] != '.')
          owp[i] += ((double) (gain[ha] - (t[ha][i] == '1' ? 1 : 0))) / ((double) (all[ha] - 1));

      }

      owp[i] /= (double) all[i];
    }

    for (i = 0; i < c; i++)
    {
      oowp[i] = 0;
      for (ha = 0; ha < c; ha++)
      {
        if (t[i][ha] != '.')
          oowp[i] += owp[ha];

      }

      oowp[i] /= (double) all[i];
    }

    printf("Case #%d:\n", ti);
    for (i = 0; i < c; i++)
    {
      printf("%.8lf\n", ((0.25 * cs[i]) + (0.5 * owp[i])) + (0.25 * oowp[i]));
    }

  }

  return 0;
}


