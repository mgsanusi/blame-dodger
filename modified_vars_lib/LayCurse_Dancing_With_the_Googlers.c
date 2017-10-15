#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int numdig(int n)
{
  int result = 0;
  while (n)
    n /= 10, result++;

  return result;
}

int chk[2000010];
int Main()
{
  int imax;
  int j;
  int r;
  int c;
  int current;
  int n;
  int size;
  int cnt = 0;
  int li[20];
  int y;
  int b;
  int result;
  li[0] = 1;
  for (imax = 1; imax < 20; imax++)
    li[imax] = li[imax - 1] * 10;

  scanf("%d", &size);
  while (size--)
  {
    printf("Case #%d: ", ++cnt);
    fprintf(stderr, "rest %d\n", size);
    scanf("%d%d", &y, &b);
    for (imax = y; imax < (b + 1); imax++)
      chk[imax] = -1;

    result = 0;
    for (imax = y; imax < b; imax++)
    {
      r = imax;
      n = numdig(imax);
      for (current = 0; current < n; current++)
      {
        r = (r / 10) + ((r % 10) * li[n - 1]);
        if ((imax < r) && (r <= b))
        {
          if (chk[r] != imax)
            result++;

          chk[r] = imax;
        }

      }

    }

    printf("%d\n", result);
  }

  return 0;
}


