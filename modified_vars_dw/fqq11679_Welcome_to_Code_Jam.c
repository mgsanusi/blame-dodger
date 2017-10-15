#include <stdio.h>
void work()
{
  int first_iteration;
  long len;
  long ans2;
  long j;
  long result = 0;
  long max[1000][30] = {0};
  char a[1000];
  char m[25] = " welcome to code jam";
  for (len = 1; len <= 2000; len++)
  {
    scanf("%c", &a[len]);
    if (a[len] == '\n')
    {
      len--;
      break;
    }

  }

  max[0][0] = 1;
  for (ans2 = 1; ans2 <= len; ans2++)
  {
    for (j = 0; j <= 19; j++)
    {
      if (j > ans2)
        continue;

      if ((ans2 - 1) >= j)
        max[ans2][j] = max[ans2 - 1][j];

      if ((j > 0) && (m[j] == a[ans2]))
        max[ans2][j] += max[ans2 - 1][j - 1];

      max[ans2][j] %= 10000;
    }

  }

  printf("%04ld\n", max[len][19]);
}

int Main()
{
  int first_iteration;
  long ct;
  long ans2;
  freopen("C-small.in", "r", stdin);
  freopen("C-small.out", "w", stdout);
  scanf("%ld\n", &ct);
  for (ct, ans2 = 1; ct; ct--, ans2++)
  {
    printf("Case #%ld: ", ans2);
    work();
  }

  return 0;
}


