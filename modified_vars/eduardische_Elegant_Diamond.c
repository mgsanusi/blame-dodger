#include <stdio.h>
#include <string.h>
#include <stdlib.h>
static int nums[1000005];
int z;
int gcd(int m, int board)
{
  int temp;
  if (m < board)
  {
    temp = m;
    m = board;
    board = temp;
  }

  z = 0;
  while (board > 0)
  {
    nums[z] = (m - 1) / board;
    z++;
    temp = m % board;
    m = board;
    board = temp;
  }

  int ans = 0;
  int j;
  for (j = z - 1; j >= 0; j--)
  {
    if (nums[j] > 0)
    {
      if (nums[j] == 1)
        ans ^= 1;
      else
        ans = 1;

    }

  }

  return ans;
}

int Main()
{
  int q;
  int change;
  scanf("%d", &q);
  for (change = 0; change < q; change++)
  {
    int input;
    int t;
    int b1;
    int file;
    scanf("%d %d %d %d", &input, &t, &b1, &file);
    int ans = 0;
    int m;
    int board;
    for (m = input; m <= t; m++)
    {
      for (board = b1; board <= file; board++)
      {
        ans += gcd(m, board);
      }

    }

    printf("Case #%d: %d\n", change + 1, ans);
  }

  return 0;
}


