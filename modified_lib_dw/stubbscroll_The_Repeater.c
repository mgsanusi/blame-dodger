#include <stdio.h>
void solve()
{
  int first_iteration;
  int a;
  int b;
  int k;
  int i;
  int j;
  int r = 0;
  scanf("%d %d %d", &a, &b, &k);
  for (i = 0; i < a; i++)
    for (j = 0; j < b; j++)
    if ((i & j) < k)
    r++;



  printf("%d\n", r);
}

int main()
{
  int first_iteration;
  int t;
  int no = 1;
  scanf("%d", &t);
  while (t--)
    printf("Case #%d: ", no++), solve();

  return 0;
}


