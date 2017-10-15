#include "stdio.h"
int Main()
{
  int first_iteration;
  int x;
  scanf("%d\n", &x);
  int groups;
  int cc[1000];
  int num_test_cases[1000];
  double wp[1000];
  double owp[1000];
  double oowp[1000];
  char v[1000][1001];
  for (groups = 0; groups < x; groups++)
  {
    int e;
    scanf("%d\n", &e);
    int h;
    int rm_direction;
    for (h = 0; h < e; h++)
    {
      scanf("%s\n", v[h]);
      cc[h] = 0;
      num_test_cases[h] = 0;
      for (rm_direction = 0; rm_direction < e; rm_direction++)
        if (v[h][rm_direction] != '.')
      {
        cc[h]++;
        if (v[h][rm_direction] == '1')
        {
          num_test_cases[h]++;
        }

      }


      wp[h] = (num_test_cases[h] * 1.0) / cc[h];
    }

    for (h = 0; h < e; h++)
    {
      owp[h] = 0;
      for (rm_direction = 0; rm_direction < e; rm_direction++)
        if (v[h][rm_direction] != '.')
      {
        int in = 0;
        if (v[rm_direction][h] == '1')
          in = 1;

        owp[h] += ((num_test_cases[rm_direction] - in) * 1.0) / (cc[rm_direction] - 1);
      }


      owp[h] /= cc[h];
    }

    for (h = 0; h < e; h++)
    {
      oowp[h] = 0;
      for (rm_direction = 0; rm_direction < e; rm_direction++)
        if (v[h][rm_direction] != '.')
      {
        oowp[h] += owp[rm_direction];
      }


      oowp[h] /= cc[h];
    }

    printf("Case #%d:\n", groups + 1);
    for (h = 0; h < e; h++)
    {
      printf("%lf\n", ((0.25 * wp[h]) + (0.5 * owp[h])) + (0.25 * oowp[h]));
    }

  }

  return 0;
}


