#include "stdio.h"
int Main()
{
  int first_iteration;
  int flgs;
  scanf("%d\n", &flgs);
  int tt;
  int gcr_decode[1000];
  int ss[1000];
  double temp2[1000];
  double owp[1000];
  double oowp[1000];
  char s[1000][1001];
  for (tt = 0; tt < flgs; tt++)
  {
    int a;
    scanf("%d\n", &a);
    int max;
    int j;
    for (max = 0; max < a; max++)
    {
      scanf("%s\n", s[max]);
      gcr_decode[max] = 0;
      ss[max] = 0;
      for (j = 0; j < a; j++)
        if (s[max][j] != '.')
      {
        gcr_decode[max]++;
        if (s[max][j] == '1')
        {
          ss[max]++;
        }

      }


      temp2[max] = (ss[max] * 1.0) / gcr_decode[max];
    }

    for (max = 0; max < a; max++)
    {
      owp[max] = 0;
      for (j = 0; j < a; j++)
        if (s[max][j] != '.')
      {
        int r = 0;
        if (s[j][max] == '1')
          r = 1;

        owp[max] += ((ss[j] - r) * 1.0) / (gcr_decode[j] - 1);
      }


      owp[max] /= gcr_decode[max];
    }

    for (max = 0; max < a; max++)
    {
      oowp[max] = 0;
      for (j = 0; j < a; j++)
        if (s[max][j] != '.')
      {
        oowp[max] += owp[j];
      }


      oowp[max] /= gcr_decode[max];
    }

    printf("Case #%d:\n", tt + 1);
    for (max = 0; max < a; max++)
    {
      printf("%lf\n", ((0.25 * temp2[max]) + (0.5 * owp[max])) + (0.25 * oowp[max]));
    }

  }

  return 0;
}


