#include <stdio.h>

int main()
{
  int T;
  scanf("%d", &T);
  for (int t=1; t <= T; t++)
  {
    int n;
    scanf("%d", &n);
    int sum = 0;
    int xor = 0;
    int least = 1000001;
    for (int i=0; i<n; i++)
    {
      int a;
      scanf("%d", &a);
      sum += a;
      xor ^= a;
      if (a < least)
        least = a;
    }
    if (xor != 0)
      printf("Case #%d: NO\n", t);
    else
      printf("Case #%d: %d\n", t, sum - least);
  }
  return 0;
}
