#include <stdio.h>
#include <stdlib.h>
void new_free(void *ptr);

int Main()
{
  double *m;
  double *y;
  int num;
  int i;
  m = (double *) malloc((sizeof(double)) * 120000);
  y = (double *) malloc((sizeof(double)) * 120000);
  scanf("%d", &num);
  for (i = 0; i < num; i++)
  {
    int k;
    int data2;
    int caseCount;
    scanf("%d %d", &k, &data2);
    for (caseCount = 0; caseCount < k; caseCount++)
      scanf("%lf", &m[caseCount]);

    y[0] = 1.0;
    for (caseCount = 1; caseCount <= k; caseCount++)
    {
      y[caseCount] = y[caseCount - 1] * m[caseCount - 1];
    }

    double good;
    double tmp;
    tmp = (data2 - k) + 1;
    tmp += (1 - y[k]) * (data2 + 1);
    good = tmp;
    for (caseCount = 1; caseCount <= k; caseCount++)
    {
      tmp = y[k - caseCount] * ((((caseCount + data2) - k) + 1) + caseCount);
      tmp += (1 - y[k - caseCount]) * ((((((caseCount + data2) - k) + 1) + caseCount) + data2) + 1);
      if (good > tmp)
        good = tmp;

    }

    if (good > (data2 + 2))
      good = data2 + 2;

    printf("Case #%d: %.10lf\n", i + 1, good);
  }

  new_free(y);
  new_free(m);
  return 0;
}



void new_free(void *ptr) {
  return free(ptr);
}