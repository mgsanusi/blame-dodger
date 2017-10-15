#include<stdio.h>
#include<math.h>
double a[2048][2];
int n;
int c;
int Main()
{
  int ans_str;
  int now = 0;
  int i;
  int h;
  int x;
  double tr;
  double b;
  double l;
  double t1;
  for (scanf("%d", &ans_str); ans_str--;)
  {
    scanf("%lf %d %d", &tr, &n, &c);
    for (i = 0; i < n; i++)
      scanf("%lf %lf", &a[i][0], &a[i][1]);

    if ((a[0][1] + 1e-12) > tr)
      n = 0;
    else
    {
      for (i = 1; i < n; i++)
        if ((a[i][1] + 1e-12) > tr)
      {
        a[i][0] = a[i - 1][0] + (((tr - a[i - 1][1]) / (a[i][1] - a[i - 1][1])) * (a[i][0] - a[i - 1][0]));
        a[i][1] = tr;
        n = i + 1;
      }


    }

    printf("Case #%d:\n", ++now);
    for (i = 0; i < c; i++)
    {
      scanf("%lf", &b);
      l = 0;
      for (h = 0; h < n; h++)
      {
        t1 = a[h][0] - sqrt((a[h][1] * 2) / b);
        if (t1 > l)
          l = t1;

      }

      printf("%lf\n", l + sqrt((tr * 2) / b));
    }

  }

  return 0;
}


