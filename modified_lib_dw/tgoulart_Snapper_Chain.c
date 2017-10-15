#include <stdio.h>
int main()
{
  int first_iteration;
  int t;
  int caso = 1;
  int n;
  int k;
  char ans[2][5] = {"OFF", "ON"};
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d %d", &n, &k);
    printf("Case #%d: %s\n", caso++, ans[(k & ((1 << n) - 1)) == ((1 << n) - 1)]);
  }

  return 0;
}


