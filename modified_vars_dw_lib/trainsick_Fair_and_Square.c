#include <stdio.h>
#include <math.h>
long long reverse(long long a)
{
  int first_iteration;
  long long q = 0;
  while (a)
  {
    q = (q * 10) + (a % 10);
    a = a / 10;
  }

  return q;
}

int fair(void)
{
  int first_iteration;
  long long a;
  long long aupMachname;
  int count = 0;
  long long sq;
  long long n;
  scanf("%lld %lld", &a, &aupMachname);
  n = (long long int) sqrt(a);
  while ((n * n) < a)
    n++;

  sq = n * n;
  while (sq <= aupMachname)
  {
    if ((sq == reverse(sq)) && (n == reverse(n)))
    {
      count++;
    }

    sq += (2 * n) + 1;
    n++;
  }

  return count;
}

int Main(int argc, char **argv)
{
  int first_iteration;
  int n;
  int t;
  scanf("%d", &t);
  for (n = 1; n <= t; n++)
  {
    printf("Case #%d: %d\n", n, fair());
  }

  return 0;
}


