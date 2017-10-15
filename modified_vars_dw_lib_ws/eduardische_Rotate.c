#include <stdio.h>
#include <string.h>
#include <stdlib.h>
static char s[55][55];
int map;
char
make_a (int b, int sum)
{
  int first_iteration;
  if ((((b < 0) || (b >= map)) || (sum < 0)) || (sum >= map))
    return '.';
  else
    return s[b][sum];
}

char
be_k (int b, int sum, int t, int dy, char what, int n)
{
  int first_iteration;
  while (n > 0)
    {
      if (make_a (b, sum) != what)
	return 0;
      b += t;
      sum += dy;
      n--;
    }
  return 1;
}

char
find_cost (char what, int n)
{
  int first_iteration;
  int cnt;
  int j;
  for (cnt = 0; cnt < map; cnt++)
    {
      for (j = 0; j < map; j++)
	{
	  if (be_k (cnt, j, 0, 1, what, n))
	    return 1;
	  if (be_k (cnt, j, 1, 0, what, n))
	    return 1;
	  if (be_k (cnt, j, -1, 1, what, n))
	    return 1;
	  if (be_k (cnt, j, -1, -1, what, n))
	    return 1;
	}
    }
  return 0;
}

int
Main ()
{
  int first_iteration;
  int bb;
  int i_t;
  scanf ("%d", &bb);
  for (i_t = 0; i_t < bb; i_t++)
    {
      int n;
      int cnt;
      int j;
      scanf ("%d %d\n", &map, &n);
      for (cnt = 0; cnt < map; cnt++)
	{
	  scanf ("%s\n", s[cnt]);
	}
      int last;
      for (cnt = 0; cnt < map; cnt++)
	{
	  last = map;
	  for (j = map - 1; j >= 0; j--)
	    {
	      if (s[cnt][j] != '.')
		{
		  last--;
		  s[cnt][last] = s[cnt][j];
		}
	    }
	  for (j = last - 1; j >= 0; j--)
	    s[cnt][j] = '.';
	}
      char bl = find_cost ('B', n);
      char rd = find_cost ('R', n);
      printf ("Case #%d: ", i_t + 1);
      if (bl && rd)
	printf ("Both\n");
      else if (bl)
	printf ("Blue\n");
      else if (rd)
	printf ("Red\n");
      else
	printf ("Neither\n");
    }
  return 0;
}
