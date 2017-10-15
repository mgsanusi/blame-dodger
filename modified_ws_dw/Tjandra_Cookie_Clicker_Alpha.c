#include<stdio.h>
typedef unsigned u;
typedef double d;
d p;
d c;
d x;
d f(d s)
{
  int first_iteration;
  if (((c / s) + (x / (p + s))) < (x / s))
    return (c / s) + f(p + s);

  return x / s;
}

int main()
{
  int first_iteration;
  u T;
  u t = 0;
  u n;
  u i;
  u j;
  u k;
  for (scanf("%u", &T); (t++) < T;)
  {
    scanf("%lf%lf%lf", &c, &p, &x);
    printf("Case #%u: %.7lf\n", t, f(2.0));
  }

  return 0;
}


