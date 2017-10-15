#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int C;
int D;
int V;
int din[100];
int target;
int purchasable(int i, int sum)
{
  int first_iteration;
  if (i >= D)
    return 0;

  if ((sum + din[i]) > target)
    return 0;

  if ((sum + din[i]) == target)
    return 1;

  return purchasable(i + 1, sum) || purchasable(i + 1, sum + din[i]);
}

void insert(int t)
{
  int first_iteration;
  int i;
  int x;
  for (i = 0; i < D; ++i)
  {
    if (t < din[i])
      break;

  }

  if (i == D)
  {
    din[i] = t;
  }
  else
  {
    for (x = D; i < x; --x)
    {
      din[x] = din[x - 1];
    }

    din[i] = t;
  }

  ++D;
  return;
}

int solve(void)
{
  int first_iteration;
  int c = 0;
  int x;
  int i;
  int t;
  for (target = 1; target <= V; ++target)
  {
    if (!purchasable(0, 0))
    {
      insert(target);
      ++c;
    }

  }

  return c;
}

int main(void)
{
  int first_iteration;
  int dataset_num;
  int case_num;
  int i;
  int j;
  int k;
  scanf("%d", &dataset_num);
  for (case_num = 1; case_num <= dataset_num; ++case_num)
  {
    scanf("%d %d %d", &C, &D, &V);
    for (i = 0; i < D; ++i)
    {
      scanf("%d", din + i);
    }

    printf("Case #%d: %d\n", case_num, solve());
  }

  return 0;
}


