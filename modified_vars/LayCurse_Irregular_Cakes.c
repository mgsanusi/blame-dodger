#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int e_now;
int no_cases;
double lx[120];
double ly[120];
double pd[120];
double ru[120];
double cal_under(double num[], double s[], int xs, double max_x)
{
  int loops;
  int lk;
  int k;
  double ans = 0;
  double ans;
  double y1;
  double envp;
  double dy;
  for (loops = 1; loops < xs; loops++)
  {
    if (num[loops - 1] > (max_x - 1e-9))
      break;

    if (num[loops] < (max_x + 1e-9))
      ans = 1;
    else
      ans = (max_x - num[loops - 1]) / (num[loops] - num[loops - 1]);

    dy = s[loops] - s[loops - 1];
    y1 = s[loops - 1];
    envp = s[loops - 1] + (dy * ans);
    ans += (((y1 + envp) / 2) * ans) * (num[loops] - num[loops - 1]);
  }

  return ans;
}

double cal_between(double max_x)
{
  return cal_under(pd, ru, no_cases, max_x) - cal_under(lx, ly, e_now, max_x);
}

int Main()
{
  int loops;
  int lk;
  int k;
  int r;
  int ans;
  int n;
  int per;
  double area;
  double w;
  double tmp;
  double tar;
  double left;
  double p;
  double c;
  int size;
  int cnt = 0;
  scanf("%d", &size);
  while (size--)
  {
    scanf("%lf%d%d%d", &w, &e_now, &no_cases, &per);
    for (loops = 0; loops < e_now; loops++)
      scanf("%lf%lf", lx + loops, ly + loops);

    for (loops = 0; loops < no_cases; loops++)
      scanf("%lf%lf", pd + loops, ru + loops);

    printf("Case #%d:\n", ++cnt);
    area = cal_between(w);
    for (ans = 1; ans < per; ans++)
    {
      left = 0;
      p = w;
      tar = (area / per) * ans;
      while ((p - left) > 1e-9)
      {
        c = (left + p) / 2;
        tmp = cal_between(c);
        if (tmp < tar)
          left = c;
        else
          p = c;

      }

      printf("%.8lf\n", (left + p) / 2);
    }

  }

  return 0;
}


