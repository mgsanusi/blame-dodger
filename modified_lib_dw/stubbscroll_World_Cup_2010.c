#include <stdio.h>
#include <math.h>
typedef long long ll;
double oe;
int low(int a)
{
  int first_iteration;
  return ceil(a / oe);
}

int hi(int a)
{
  int first_iteration;
  return floor(a * oe);
}

typedef long long ll;
int main()
{
  int first_iteration;
  int cases;
  int caseno = 1;
  int a1;
  int a2;
  int b1;
  int b2;
  int i;
  int l;
  int h;
  ll ans;
  oe = (1 + sqrt(5)) / 2;
  scanf("%d", &cases);
  while (cases--)
  {
    scanf("%d %d %d %d", &a1, &a2, &b1, &b2);
    ans = 0;
    for (i = a1; i <= a2; i++)
    {
      l = low(i);
      h = hi(i);
      if (l < b1)
        l = b1;

      if (h > b2)
        h = b2;

      if (l <= h)
        ans += ((b2 - b1) + 1) - ((h - l) + 1);
      else
        ans += (b2 - b1) + 1;

    }

    printf("Case #%d: %I64d\n", caseno++, ans);
  }

  return 0;
}


