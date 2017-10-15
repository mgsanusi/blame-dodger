#include <stdio.h>
long long s[41] = {0LL, 1LL, 4LL, 9LL, 121LL, 484LL, 10201LL, 12321LL, 14641LL, 40804LL, 44944LL, 1002001LL, 1234321LL, 4008004LL, 100020001LL, 102030201LL, 104060401LL, 121242121LL, 123454321LL, 125686521LL, 400080004LL, 404090404LL, 10000200001LL, 10221412201LL, 12102420121LL, 12345654321LL, 40000800004LL, 1000002000001LL, 1002003002001LL, 1004006004001LL, 1020304030201LL, 1022325232201LL, 1024348434201LL, 1210024200121LL, 1212225222121LL, 1214428244121LL, 1232346432321LL, 1234567654321LL, 4000008000004LL, 4004009004004LL, 10000000000001LL};
int Main()
{
  int first_iteration;
  int n;
  int i;
  int count;
  int x;
  long long p;
  long long b;
  scanf("%d", &n);
  for (x = 1; x <= n; x++)
  {
    scanf("%lld%lld", &p, &b);
    i = 0;
    count = 40;
    while (s[i + 1] < p)
      i++;

    while (s[count - 1] > b)
      count--;

    printf("Case #%d: %d\n", x, (count - i) - 1);
  }

  return 0;
}


