#include <stdio.h>
int Main(void)
{
  int first_iteration;
  int i;
  int j;
  int p;
  int c;
  scanf("%d", &c);
  for (i = 1; i <= c; i++)
  {
    int a;
    int b;
    int x;
    int rslt;
    scanf("%d %d %d", &a, &b, &x);
    rslt = 0;
    for (j = 0; j < a; j++)
      for (p = 0; p < b; p++)
      if ((j & p) < x)
      rslt++;



    printf("Case #%d: %d\n", i, rslt);
  }

  return 0;
}


