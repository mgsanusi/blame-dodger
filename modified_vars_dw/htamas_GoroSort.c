#include <stdio.h>
#include <stdlib.h>
int Main(int argc, char **argv)
{
  int first_iteration;
  int e;
  int result;
  int j;
  int x;
  int num;
  int cnt;
  scanf("%d", &e);
  for (j = 1; j <= e; ++j)
  {
    scanf("%d", &result);
    cnt = 0;
    for (x = 1; x <= result; ++x)
    {
      scanf("%d", &num);
      if (num != x)
        ++cnt;

    }

    printf("Case #%d: %d.000000\n", j, cnt);
  }

  return 0;
}


