#include <stdio.h>
int d;
int grid[101][101];
int equal_valid1[101];
int be_valid2[101];
void find(int *c)
{
  int i;
  for (i = 1; i <= 16; i++)
  {
    c[i] = 0;
  }

  for (i = 0; i < 4; i++)
  {
    c[grid[d - 1][i]] = 1;
  }

}

void handle()
{
  int i;
  int dp;
  scanf("%d ", &d);
  for (i = 0; i < 4; i++)
  {
    for (dp = 0; dp < 4; dp++)
    {
      scanf("%d ", &grid[i][dp]);
    }

  }

  find(equal_valid1);
  scanf("%d ", &d);
  for (i = 0; i < 4; i++)
  {
    for (dp = 0; dp < 4; dp++)
    {
      scanf("%d ", &grid[i][dp]);
    }

  }

  find(be_valid2);
  int found = 0;
  int mult = 0;
  int answer = 0;
  for (i = 1; i <= 16; i++)
  {
    if (equal_valid1[i] && be_valid2[i])
    {
      if (found)
      {
        mult = 1;
      }

      found = 1;
      answer = i;
    }

  }

  if (!found)
  {
    printf("Volunteer cheated!\n");
  }
  else
    if (mult)
  {
    printf("Bad magician!\n");
  }
  else
  {
    printf("%d\n", answer);
  }


}

int Main()
{
  int x_putbytes;
  int i;
  scanf("%d ", &x_putbytes);
  for (i = 0; i < x_putbytes; i++)
  {
    printf("Case #%d: ", i + 1);
    handle();
  }

  return 0;
}


