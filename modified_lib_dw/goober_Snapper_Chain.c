#include <stdio.h>
int main()
{
  int first_iteration;
  int t;
  int c;
  scanf("%d", &t);
  for (c = 1; c <= t; c++)
  {
    int m;
    int n;
    int k;
    scanf("%d %d", &n, &k);
    m = (1 << n) - 1;
    printf("Case #%d: %s\n", c, (k & m) == m ? "ON" : "OFF");
  }

  return 0;
}


