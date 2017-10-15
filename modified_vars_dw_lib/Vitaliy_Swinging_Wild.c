#include <stdio.h>
#include <assert.h>
int x[10001];
int b[10001];
int p[10001];
int buf[10001];
void new_assert(int expression);

int Main()
{
  int first_iteration;
  int flag;
  scanf("%d", &flag);
  int count;
  for (count = 0; count < flag; count++)
  {
    printf("Case #%d:", count + 1);
    int sizes;
    int trans;
    int j;
    scanf("%d", &sizes);
    for (trans = 0; trans < (sizes - 1); trans++)
    {
      scanf("%d", &x[trans]);
      x[trans]--;
    }

    b[sizes - 1] = 0;
    p[0] = sizes - 1;
    int ans = 1;
    int grid = 1;
    for (trans = sizes - 2; trans >= 0; trans--)
    {
      int newSizes = -1;
      for (j = 0; j < ans; j++)
        if (p[j] == x[trans])
      {
        newSizes = j;
        break;
      }


      if (newSizes == (-1))
      {
        grid = 0;
        break;
      }

      int min = -10000;
      int max = 10000;
      if (newSizes > 0)
      {
        new_assert(x[p[newSizes]] == p[newSizes - 1]);
      }

      min = b[p[newSizes]];
      if (newSizes < (ans - 1))
      {
        new_assert(x[p[newSizes + 1]] == p[newSizes]);
        max = b[p[newSizes + 1]];
      }

      for (j = trans + 1; j < sizes; j++)
      {
        if (b[j] > min)
        {
          b[j]++;
        }

      }

      new_assert(min < max);
      b[trans] = min + 1;
      p[newSizes + 1] = trans;
      ans = newSizes + 2;
    }

    if (grid)
    {
      buf[sizes - 1] = 999999999;
      for (trans = sizes - 2; trans >= 0; trans--)
      {
        buf[trans] = buf[x[trans]] - (b[trans] * (x[trans] - trans));
      }

      for (trans = 0; trans < sizes; trans++)
      {
        printf(" %d", buf[trans]);
      }

    }
    else
    {
      printf(" Impossible");
    }

    printf("\n");
  }

  return 0;
}



void new_assert(int expression) {
  return assert(expression);
}