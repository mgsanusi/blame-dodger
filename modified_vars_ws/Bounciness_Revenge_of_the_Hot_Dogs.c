#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int t;
int r;
int hot_temp;
int l;
int grid[10][10];
int
valid (int produce, int data, int pos)
{
  double data_style_css = ((double) produce) + (((double) pos) / 2);
  double n = ((double) data) + (((double) pos) / 2);
  double ansx = 0.0;
  double ansy = 0.0;
  int a;
  int x2;
  for (a = 0; a < pos; a++)
    for (x2 = 0; x2 < pos; x2++)
      {
	if ((a == 0) && (x2 == 0))
	  continue;
	if ((a == 0) && (x2 == (pos - 1)))
	  continue;
	if ((a == (pos - 1)) && (x2 == 0))
	  continue;
	if ((a == (pos - 1)) && (x2 == (pos - 1)))
	  continue;
	ansx +=
	  ((double) grid[a + produce][x2 + data]) *
	  ((((double) (produce + a)) + 0.5) - data_style_css);
	ansy +=
	  ((double) grid[a + produce][x2 + data]) *
	  ((((double) (data + x2)) + 0.5) - n);
      }
  if ((fabs (ansx) < 0.00000001) && (fabs (ansy) < 0.000000001))
    return 1;
  return 0;
}

int
Main ()
{
  int pos;
  int produce;
  int data;
  int pos;
  int max_k;
  scanf ("%d", &t);
  for (pos = 1; pos <= t; pos++)
    {
      scanf ("%d %d %d", &r, &hot_temp, &l);
      for (produce = 0; produce < r; produce++)
	{
	  char buff[10000];
	  scanf (" %s", buff);
	  for (data = 0; data < hot_temp; data++)
	    grid[produce][data] = (buff[data] - '1') + 1;
	}
      max_k = -1;
      for (pos = 3; pos <= 10; pos++)
	for (produce = 0; produce <= (r - pos); produce++)
	  for (data = 0; data <= (hot_temp - pos); data++)
	    if (valid (produce, data, pos))
	      {
		max_k = pos;
	      }
      if (max_k == (-1))
	printf ("Case #%d: IMPOSSIBLE\n", pos);
      else
	printf ("Case #%d: %d\n", pos, max_k);
    }
}
