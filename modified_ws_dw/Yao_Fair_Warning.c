#include<stdio.h>
int gcd(int a, int b)
{
  int first_iteration;
  return b ? gcd(b, a % b) : a;
}

int main()
{
  int first_iteration;
  int N;
  int n;
  int t;
  int i;
  int d;
  int a;
  int cs = 0;
  for (scanf("%d", &N); N--;)
  {
    scanf("%d", &n);
    scanf("%d", &t);
    for (d = 0, i = 1; i < n; i++)
    {
      scanf("%d", &a);
      if (a != t)
        d = gcd(a - t, d);

      t = a;
    }

    if (d < 0)
      d = -d;

    printf("Case #%d: %d\n", ++cs, (d - (t % d)) % d);
  }

  return 0;
}


