#include <stdio.h>
typedef long long ll;
int Main()
{
  int n;
  int res = 1;
  ll a;
  ll y;
  ll use;
  ll num;
  scanf("%d", &n);
  while (n--)
  {
    scanf("%I64d %I64d", &a, &y);
    use = 0;
    num = 0;
    while (1)
    {
      use += ((a + a) + (((2 * num) + 1) * ((2 * num) + 1))) - ((4 * num) * num);
      if (use > y)
        break;

      num++;
    }

    printf("Case #%d: %I64d\n", res++, num);
  }

  return 0;
}


