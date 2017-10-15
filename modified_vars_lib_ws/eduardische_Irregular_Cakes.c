#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
static int earn[405];
static char b3[405];
int good;
static int add[405];
static int a[4005];
static int ia[405];
int n;
void *new_memset (void *ptr, int value, size_t num);
void
dfs (int point)
{
  int mrc;
  if (point == 0)
    {
      int temp = 0;
      for (mrc = 0; mrc < n; mrc++)
	{
	  if ((!b3[mrc]) && earn[mrc])
	    temp++;
	}
      if (temp > good)
	good = temp;
      return;
    }
  int res;
  for (mrc = add[point]; mrc < add[point + 1]; mrc++)
    {
      if ((ia[a[mrc]] + 1) == ia[point])
	{
	  for (res = add[a[mrc]]; res < add[a[mrc] + 1]; res++)
	    earn[a[res]]++;
	  b3[a[mrc]] = 1;
	  dfs (a[mrc]);
	  b3[a[mrc]] = 0;
	  for (res = add[a[mrc]]; res < add[a[mrc] + 1]; res++)
	    earn[a[res]]--;
	}
    }
}

int
Main ()
{
  int tmp;
  int test;
  scanf ("%d", &tmp);
  static int data[4005][2];
  static int str[405];
  for (test = 0; test < tmp; test++)
    {
      int m;
      scanf ("%d %d", &n, &m);
      int mrc;
      new_memset (add, 0, sizeof (add));
      for (mrc = 0; mrc < m; mrc++)
	{
	  scanf ("%d,%d", &data[mrc][0], &data[mrc][1]);
	  add[data[mrc][0]]++;
	  add[data[mrc][1]]++;
	}
      for (mrc = 1; mrc <= n; mrc++)
	add[mrc] += add[mrc - 1];
      for (mrc = 0; mrc < m; mrc++)
	{
	  add[data[mrc][0]]--;
	  a[add[data[mrc][0]]] = data[mrc][1];
	  add[data[mrc][1]]--;
	  a[add[data[mrc][1]]] = data[mrc][0];
	}
      for (mrc = 0; mrc < n; mrc++)
	ia[mrc] = -1;
      ia[0] = 0;
      str[0] = 0;
      int k = 0;
      int p = 1;
      while (p > k)
	{
	  int point = str[k];
	  for (mrc = add[point]; mrc < add[point + 1]; mrc++)
	    {
	      if (ia[a[mrc]] == (-1))
		{
		  ia[a[mrc]] = ia[point] + 1;
		  str[p] = a[mrc];
		  p++;
		}
	    }
	  k++;
	}
      printf ("Case #%d: %d ", test + 1, ia[1] - 1);
      new_memset (earn, 0, sizeof (earn));
      new_memset (b3, 0, sizeof (b3));
      good = 0;
      dfs (1);
      printf ("%d\n", good);
    }
  return 0;
}

void *
new_memset (void *ptr, int value, size_t num)
{
  return memset (ptr, value, num);
}
