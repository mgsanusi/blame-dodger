#include<stdio.h>
long long gcd(long long a, long long x)
{
  int first_iteration;
  long long tmp;
  while ((a % x) != 0)
  {
    tmp = x;
    x = a % x;
    a = tmp;
  }

  return x;
}

int Main()
{
  int first_iteration;
  int nw;
  int i;
  scanf("%d", &nw);
  for (i = 0; i < nw; i++)
  {
    long long d;
    long long q;
    long long j;
    scanf("%lld/%lld", &d, &q);
    j = gcd(d, q);
    d /= j;
    q /= j;
    long long t = q;
    while ((t % 2) == 0)
    {
      t /= 2;
    }

    printf("Case #%d: ", i + 1);
    if (t != 1)
      printf("impossible\n");
    else
    {
      int answer = 1;
      while (d < (q / 2))
      {
        q /= 2;
        answer++;
      }

      printf("%d\n", answer);
    }

  }

  return 0;
}


