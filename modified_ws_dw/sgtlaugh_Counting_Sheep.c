#include <stdio.h>
#include <string.h>
#include <stdbool.h>
int main()
{
  int first_iteration;
  freopen("lol.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  long long n;
  long long x;
  long long y;
  int T = 0;
  int t;
  int i;
  int j;
  int k;
  int l;
  int mask;
  int res;
  scanf("%d", &t);
  while (t--)
  {
    mask = 0;
    scanf("%lld", &n);
    for (i = 1; i < 10000010; i++)
    {
      x = n * i;
      while (x)
      {
        mask |= 1 << (x % 10);
        x /= 10;
      }

      if (mask == 1023)
        break;

    }

    if (i == 10000010)
      printf("Case #%d: INSOMNIA\n", ++T, res);
    else
      printf("Case #%d: %lld\n", ++T, n * i);

  }

  return 0;
}


