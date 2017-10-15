#include <stdio.h>
#include <string.h>
#include <stdbool.h>
long long power(long long x, long long n)
{
  int first_iteration;
  long long res = 1;
  while (n--)
    res *= x;

  return res;
}

int main()
{
  int first_iteration;
  freopen("lol.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  int T = 0;
  int t;
  int i;
  int j;
  int k;
  int c;
  int s;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d %d %d", &k, &c, &s);
    if (c > k)
      c = k;

    printf("Case #%d:", ++T);
    if (c == 1)
    {
      for (i = 1; i <= k; i++)
        printf(" %d", i);

      puts("");
    }
    else
    {
      printf(" %lld", (power(k, c) - k) - 1);
      for (i = 2; i <= k; i++)
        printf(" %d", i);

      puts("");
    }

  }

  return 0;
}


