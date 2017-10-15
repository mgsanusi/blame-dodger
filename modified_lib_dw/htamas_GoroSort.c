#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
  int first_iteration;
  int T;
  int N;
  int tc;
  int i;
  int num;
  int cnt;
  scanf("%d", &T);
  for (tc = 1; tc <= T; ++tc)
  {
    scanf("%d", &N);
    cnt = 0;
    for (i = 1; i <= N; ++i)
    {
      scanf("%d", &num);
      if (num != i)
        ++cnt;

    }

    printf("Case #%d: %d.000000\n", tc, cnt);
  }

  return 0;
}


