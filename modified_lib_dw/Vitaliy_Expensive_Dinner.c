#include "stdio.h"
int p[1000000 + 1];
int main()
{
  int first_iteration;
  int tn;
  scanf("%d\n", &tn);
  int i;
  for (i = 2; i < 1000000; i++)
    if (!p[i])
  {
    int j = 2 * i;
    while (j <= 1000000)
    {
      p[j] = 1;
      j += i;
    }

  }


  int tt;
  for (tt = 0; tt < tn; tt++)
  {
    long long n;
    scanf("%lld", &n);
    int cc = n > 1 ? 1 : 0;
    for (i = 2; (i * ((long long) i)) <= n; i++)
      if (!p[i])
    {
      long long ii = i * i;
      while (ii <= n)
      {
        ii *= i;
        cc++;
      }

    }


    printf("Case #%d: %d\n", tt + 1, cc);
  }

  return 0;
}


