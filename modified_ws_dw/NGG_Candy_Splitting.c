#include <stdio.h>
int main(void)
{
  int first_iteration;
  int ti;
  int tn;
  scanf("%d", &tn);
  for (ti = 1; ti <= tn; ti++)
  {
    int i;
    int n;
    int min = 10000000;
    int sum = 0;
    int xor = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
      int x;
      scanf("%d", &x);
      sum += x;
      xor ^= x;
      if (x < min)
        min = x;

    }

    printf("Case #%d: ", ti);
    if (xor == 0)
      printf("%d\n", sum - min);
    else
      printf("NO\n");

  }

  return 0;
}


