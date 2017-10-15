#include <stdio.h>
char s[110][110];
int gain[110];
int all[110];
double caseNum[110];
double owp[110];
double oowp[110];
int Main(void)
{
  int ti;
  int pos;
  scanf("%d", &pos);
  for (ti = 1; ti <= pos; ti++)
  {
    int t;
    int tc;
    int j;
    scanf("%d\n", &t);
    for (tc = 0; tc < t; tc++)
    {
      gets(s[tc]);
    }

    for (tc = 0; tc < t; tc++)
    {
      all[tc] = (gain[tc] = 0);
      for (j = 0; j < t; j++)
      {
        if (s[tc][j] != '.')
          all[tc]++;

        if (s[tc][j] == '1')
          gain[tc]++;

      }

      caseNum[tc] = ((double) gain[tc]) / ((double) all[tc]);
    }

    for (tc = 0; tc < t; tc++)
    {
      owp[tc] = 0;
      for (j = 0; j < t; j++)
      {
        if (s[tc][j] != '.')
          owp[tc] += ((double) (gain[j] - (s[j][tc] == '1' ? 1 : 0))) / ((double) (all[j] - 1));

      }

      owp[tc] /= (double) all[tc];
    }

    for (tc = 0; tc < t; tc++)
    {
      oowp[tc] = 0;
      for (j = 0; j < t; j++)
      {
        if (s[tc][j] != '.')
          oowp[tc] += owp[j];

      }

      oowp[tc] /= (double) all[tc];
    }

    printf("Case #%d:\n", ti);
    for (tc = 0; tc < t; tc++)
    {
      printf("%.8lf\n", ((0.25 * caseNum[tc]) + (0.5 * owp[tc])) + (0.25 * oowp[tc]));
    }

  }

  return 0;
}


