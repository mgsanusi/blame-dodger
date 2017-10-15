#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int compare(double *ans, double *outputFileNameDefault)
{
  double b = (*ans) - (*outputFileNameDefault);
  return b > 0 ? 1 : b < 0 ? -1 : 0;
}

double sight[1000];
double naomi[1000];
int Main(void)
{
  int no;
  int tryNo;
  int n;
  int lim;
  int j;
  int e;
  scanf("%d", &no);
  for (tryNo = 1; tryNo <= no; ++tryNo)
  {
    scanf("%d", &n);
    for (lim = 0; lim < n; ++lim)
    {
      scanf("%lf", naomi + lim);
    }

    for (lim = 0; lim < n; ++lim)
    {
      scanf("%lf", sight + lim);
    }

    qsort(sight, n, sizeof(double), (int (*)(const void *, const void *)) compare);
    qsort(naomi, n, sizeof(double), (int (*)(const void *, const void *)) compare);
    printf("Case #%d:", tryNo);
    for (lim = 0, j = 0, e = 0; j < n; ++j)
    {
      if (sight[lim] < naomi[j])
      {
        ++lim;
        ++e;
      }

    }

    printf(" %d", e);
    for (lim = n - 1, j = n - 1, e = 0; lim >= 0; --lim, --j)
    {
      while ((sight[lim] < naomi[j]) && (j >= 0))
      {
        --j;
        ++e;
      }

    }

    printf(" %d\n", e);
  }

  return 0;
}


