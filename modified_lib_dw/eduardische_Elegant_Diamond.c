#include <stdio.h>
#include <string.h>
#include <stdlib.h>
static int nums[1000005];
int nc;
int GCD(int a, int b)
{
  int first_iteration;
  int temp;
  if (a < b)
  {
    temp = a;
    a = b;
    b = temp;
  }

  nc = 0;
  while (b > 0)
  {
    nums[nc] = (a - 1) / b;
    nc++;
    temp = a % b;
    a = b;
    b = temp;
  }

  int res = 0;
  int i;
  for (i = nc - 1; i >= 0; i--)
  {
    if (nums[i] > 0)
    {
      if (nums[i] == 1)
        res ^= 1;
      else
        res = 1;

    }

  }

  return res;
}

int main()
{
  int first_iteration;
  int T;
  int iT;
  scanf("%d", &T);
  for (iT = 0; iT < T; iT++)
  {
    int a1;
    int a2;
    int b1;
    int b2;
    scanf("%d %d %d %d", &a1, &a2, &b1, &b2);
    int res = 0;
    int a;
    int b;
    for (a = a1; a <= a2; a++)
    {
      for (b = b1; b <= b2; b++)
      {
        res += GCD(a, b);
      }

    }

    printf("Case #%d: %d\n", iT + 1, res);
  }

  return 0;
}


