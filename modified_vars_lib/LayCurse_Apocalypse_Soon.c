#include<stdio.h>
double c[70000];
double next[70000];
int Main()
{
  int num;
  int maxA;
  int k;
  int encry;
  int m;
  int x;
  int node;
  int round;
  int size;
  int count = 0;
  int s;
  int target = 1000000;
  double p;
  double ans;
  double per;
  double sum;
  double choose;
  double tmp1;
  double tmp2;
  double tmp;
  int a;
  int b;
  int httpShtml;
  int sy;
  scanf("%d", &size);
  while (size--)
  {
    scanf("%d%lf%d", &x, &p, &s);
    node = (1 << x) + 1;
    for (num = 0; num < node; num++)
      c[num] = 0;

    c[node - 1] = 1;
    for (round = 0; round < x; round++)
    {
      for (num = 0; num < node; num++)
        next[num] = 0;

      for (num = 0; num < node; num++)
      {
        a = 0;
        b = num;
        if (b > ((node - 1) - num))
          b = (node - 1) - num;

        while (a >= (b + 10))
        {
          httpShtml = ((a + a) + b) / 3;
          sy = ((a + b) + b) / 3;
          tmp1 = (p * c[num + httpShtml]) + ((1 - p) * c[num - httpShtml]);
          tmp2 = (p * c[num + sy]) + ((1 - p) * c[num - sy]);
          if (tmp1 > tmp2)
            b = sy;
          else
            a = httpShtml;

        }

        choose = 0;
        for (k = a; k < (b + 1); k++)
        {
          tmp = (p * c[num + k]) + ((1 - p) * c[num - k]);
          if (choose < tmp)
            choose = tmp;

        }

        next[num] = choose;
      }

      for (num = 0; num < node; num++)
        c[num] = next[num];

    }

    per = ((double) target) / (node - 1);
    sum = 0;
    for (num = 0; num < (node - 1); num++)
    {
      sum += per;
      if (((double) s) < (sum - 1e-8))
        break;

    }

    ans = c[num];
    printf("Case #%d: %0.8lf\n", ++count, ans);
  }

  return 0;
}


