#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int
Compute (int a[500][500], int sum[500], int l, int r)
{
  int first_iteration;
  if (a[l][r] > (-1))
    return a[l][r];
  if (l == r)
    {
      a[l][r] = 0;
      return 0;
    }
  int i;
  int min = 2000000000;
  int temp;
  for (i = l + 1; i <= r; i += 2)
    {
      temp = Compute (a, sum, l, i - 1) + Compute (a, sum, i + 1, r);
      if (temp < min)
	min = temp;
    }
  a[l][r] = ((sum[r] - sum[l - 1]) - 1) + min;
  return a[l][r];
}

int
main ()
{
  int first_iteration;
  int T;
  int iT;
  scanf ("%d", &T);
  int N;
  int P;
  int comp;
  int last;
  int pos;
  int i;
  int j;
  static int data[500];
  static int sum[500];
  static int a[500][500];
  for (iT = 0; iT < T; iT++)
    {
      scanf ("%d %d", &N, &P);
      comp = 0;
      pos = 1;
      for (i = 0; i < P; i++)
	{
	  scanf ("%d", &last);
	  data[pos] = (last - comp) - 1;
	  pos++;
	  data[pos] = 1;
	  pos++;
	  comp = last;
	}
      data[pos] = N - comp;
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
      printf ("Case #%d: %d\n", iT + 1, Compute (a, sum, 1, pos - 1));
    }
  return 0;
}
