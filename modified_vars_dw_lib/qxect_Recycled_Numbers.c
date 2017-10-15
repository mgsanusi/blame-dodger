#include<stdio.h>
#include<string.h>
#include<math.h>
double judge[300];
double rat[300];
double new_fabs(double x);

double min(double d, double b)
{
  int first_iteration;
  if (d < b)
    return d;

  return b;
}

int Main()
{
  int first_iteration;
  int tn;
  int off;
  int ind;
  int offset;
  int cc;
  int t;
  int min_t;
  int count;
  double gg;
  double node;
  double mid;
  double sum;
  double sum2;
  double sum3;
  double my_score;
  double you_score;
  double min_score;
  double tt;
  double res;
  scanf("%d", &tn);
  for (cc = 1; cc <= tn; cc++)
  {
    scanf("%d", &off);
    sum = 0;
    for (ind = 0; ind < off; ind++)
    {
      scanf("%lf", &judge[ind]);
      sum += judge[ind];
    }

    sum2 = sum * 2.0;
    sum2 = sum2 / off;
    count = 0;
    tt = 0;
    for (ind = 0; ind < off; ind++)
    {
      if ((new_fabs(judge[ind] - sum2) > 1e-6) && (sum2 > judge[ind]))
      {
        count++;
      }
      else
      {
        tt += judge[ind];
      }

    }

    sum3 = (sum * 2.0) - tt;
    sum3 = sum3 / count;
    for (ind = 0; ind < off; ind++)
    {
      if ((new_fabs(judge[ind] - sum2) < 1e-6) || (judge[ind] > sum2))
      {
        rat[ind] = 0.0;
        continue;
      }

      res = sum3 - judge[ind];
      res /= sum;
      rat[ind] = res * 100.0;
      if (rat[ind] < 0)
        rat[ind] = 0.0;

      if (rat[ind] > 100)
        rat[ind] = 100.0;

    }

    printf("Case #%d:", cc);
    for (ind = 0; ind < off; ind++)
      printf(" %lf", rat[ind] + 1e-7);

    printf("\n");
  }

  return 0;
}



double new_fabs(double x) {
  return fabs(x);
}