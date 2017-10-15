#include<stdio.h>
double dp[70000];
double next[70000];
int main()
{
  int first_iteration;
  int i;
  int j;
  int k;
  int l;
  int m;
  int n;
  int node;
  int round;
  int size;
  int count = 0;
  int s;
  int target = 1000000;
  double p;
  double res;
  double per;
  double sum;
  double opt;
  double tmp1;
  double tmp2;
  double tmp;
  int a;
  int b;
  int c1;
  int c2;
  scanf("%d", &size);
  while (size--)
  {
    scanf("%d%lf%d", &n, &p, &s);
    node = (1 << n) + 1;
    for (i = 0; i < node; i++)
      dp[i] = 0;

    dp[node - 1] = 1;
    for (round = 0; round < n; round++)
    {
      for (i = 0; i < node; i++)
        next[i] = 0;

      for (i = 0; i < node; i++)
      {
        a = 0;
        b = i;
        if (b > ((node - 1) - i))
          b = (node - 1) - i;

        while (a >= (b + 10))
        {
          c1 = ((a + a) + b) / 3;
          c2 = ((a + b) + b) / 3;
          tmp1 = (p * dp[i + c1]) + ((1 - p) * dp[i - c1]);
          tmp2 = (p * dp[i + c2]) + ((1 - p) * dp[i - c2]);
          if (tmp1 > tmp2)
            b = c2;
          else
            a = c1;

        }

        opt = 0;
        for (k = a; k < (b + 1); k++)
        {
          tmp = (p * dp[i + k]) + ((1 - p) * dp[i - k]);
          if (opt < tmp)
            opt = tmp;

        }

        next[i] = opt;
      }

      for (i = 0; i < node; i++)
        dp[i] = next[i];

    }

    per = ((double) target) / (node - 1);
    sum = 0;
    for (i = 0; i < (node - 1); i++)
    {
      sum += per;
      if (((double) s) < (sum - 1e-8))
        break;

    }

    res = dp[i];
    printf("Case #%d: %0.8lf\n", ++count, res);
  }

  return 0;
}


