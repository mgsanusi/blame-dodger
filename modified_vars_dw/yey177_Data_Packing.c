#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int a[1008];
int sorted[1008];
int labA[1008][1008];
int bit[1008];
int caseId;
int comp(const void *t, const void *l)
{
  int first_iteration;
  return (*((int *) t)) - (*((int *) l));
}

int sum(int d)
{
  int first_iteration;
  int d = 0;
  while (d > 0)
  {
    d += bit[d];
    d -= d & (-d);
  }

  return d;
}

void add(int d, int x)
{
  int first_iteration;
  while (d <= caseId)
  {
    bit[d] += x;
    d += d & (-d);
  }

}

int Main()
{
  int first_iteration;
  int cnt;
  int n1;
  int d;
  int j;
  int mini;
  int tmp1;
  int tmp2;
  scanf("%d", &n1);
  for (cnt = 1; cnt <= n1; cnt++)
  {
    scanf("%d", &caseId);
    for (d = 0; d < caseId; d++)
      scanf("%d", &a[d]);

    memset(bit, 0, sizeof(bit));
    memcpy(sorted, a, sizeof(sorted));
    qsort(sorted, caseId, 4, comp);
    for (d = 0; d < caseId; d++)
    {
      for (j = 0; j < caseId; j++)
      {
        if (a[d] == sorted[j])
        {
          a[d] = j + 1;
          break;
        }

      }

    }

    for (d = 1; d <= caseId; d++)
      add(d, 1);

    for (d = 1; d <= caseId; d++)
    {
      for (j = 0; j < caseId; j++)
      {
        if (a[j] == d)
        {
          mini = j + 1;
          break;
        }

      }

      tmp1 = sum(caseId) - sum(mini);
      tmp2 = sum(mini - 1);
      labA[d][0] = labA[d - 1][0] + tmp1;
      labA[d][d] = labA[d - 1][d - 1] + tmp2;
      for (j = 1; j < d; j++)
      {
        labA[d][j] = (labA[d - 1][j] + tmp1) < (labA[d - 1][j - 1] + tmp2) ? labA[d - 1][j] + tmp1 : labA[d - 1][j - 1] + tmp2;
      }

      add(mini, -1);
    }

    tmp1 = 1000000007;
    for (d = 0; d <= caseId; d++)
    {
      if (tmp1 > labA[caseId][d])
        tmp1 = labA[caseId][d];

    }

    printf("Case #%d: %d\n", cnt, tmp1);
  }

  return 0;
}


