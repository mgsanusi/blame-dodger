#include <stdio.h>
int ti;
int j;
int j;
int x;
int c;
int rslt;
int Main()
{
  int first_iteration;
  scanf("%d", &j);
  for (ti = 1; ti <= j; ++ti)
  {
    scanf("%d", &x);
    for (j = 1, rslt = 0; j <= x; ++j)
    {
      scanf("%d", &c);
      rslt += c != j;
    }

    printf("Case #%d: %d\n", ti, rslt);
  }

  return 0;
}


