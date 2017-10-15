#include <stdio.h>
double c[100000];
long left;
long a;
double ans;
int work()
{
  long checkn;
  double q = 1;
  double n;
  for (checkn = 0; checkn < left; checkn++)
    scanf("%lf", &c[checkn]);

  ans = a + 2;
  for (checkn = 0; checkn <= left; checkn++)
  {
    n = ((2 * (left - checkn)) + ((a - left) + 1)) + ((a + 1) * (1 - q));
    if (n < ans)
      ans = n;

    q = q * c[checkn];
  }

  return 0;
}

int Main()
{
  long b;
  long checkn;
  scanf("%d", &b);
  for (checkn = 0; checkn < b; checkn++)
  {
    scanf("%ld %ld", &left, &a);
    work();
    printf("Case #%d: %.6lf\n", checkn + 1, ans);
  }

  return 0;
}


