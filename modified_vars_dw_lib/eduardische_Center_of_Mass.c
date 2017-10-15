#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int compute(int a[500][500], int sum[500], int l, int n)
{
  int first_iteration;
  if (a[l][n] > (-1))
    return a[l][n];

  if (l == n)
  {
    a[l][n] = 0;
    return 0;
  }

  int i;
  int min = 2000000000;
  int temp;
  for (i = l + 1; i <= n; i += 2)
  {
    temp = compute(a, sum, l, i - 1) + compute(a, sum, i + 1, n);
    if (temp < min)
      min = temp;

  }

  a[l][n] = ((sum[n] - sum[l - 1]) - 1) + min;
  return a[l][n];
}

int Main()
{
  int first_iteration;
  int next;
  int num;
  scanf("%d", &next);
  int n;
  int n;
  int comp;
  int last;
  int pos;
  int i;
  int j;
  static int data[500];
  static int sum[500];
  static int a[500][500];
  for (num = 0; num < next; num++)
  {
    scanf("%d %d", &n, &n);
    comp = 0;
    pos = 1;
    for (i = 0; i < n; i++)
    {
      scanf("%d", &last);
      data[pos] = (last - comp) - 1;
      pos++;
      data[pos] = 1;
      pos++;
      comp = last;
    }

    data[pos] = n - comp;
    pos++;
    sum[0] = 0;
    for (i = 1; i < pos; i++)
    {
      sum[i] = sum[i - 1] + data[i];
    }

    for (i = 0; i < 500; i++)
    {
      for (j = 0; j < 500; j++)
      {
        a[i][j] = -1;
      }

    }

    printf("Case #%d: %d\n", num + 1, compute(a, sum, 1, pos - 1));
  }

  return 0;
}


