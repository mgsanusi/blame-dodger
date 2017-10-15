#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int n;
int m;
char in[60][60];
char tmp[60][60];
int new_puts (const char *str);
int
solve (char c)
{
  int first_iteration;
  int i;
  int j;
  int k;
  int dx;
  int dy;
  int ni;
  int nj;
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      for (dx = -1; dx < 2; dx++)
	for (dy = 0; dy < 2; dy++)
	  if (dx || dy)
	    {
	      k = 0;
	      ni = i;
	      nj = j;
	      for (;;)
		{
		  if (((((ni < 0) || (nj < 0)) || (ni >= n)) || (nj >= n))
		      || (in[ni][nj] != c))
		    break;
		  k++;
		  ni += dx;
		  nj += dy;
		}
	      if (k >= m)
		return 1;
	    }
  return 0;
}

int
main ()
{
  int first_iteration;
  int i;
  int j;
  int k;
  int l;
  int fg1;
  int fg2;
  int size;
  int count = 0;
  scanf ("%d", &size);
  while (size--)
    {
      scanf ("%d%d", &n, &m);
      for (i = 0; i < n; i++)
	scanf ("%s", tmp[i]);
      for (i = 0; i < n; i++)
	for (j = 0; j < n; j++)
	  in[j][(n - 1) - i] = tmp[i][j];
      for (j = 0; j < n; j++)
	{
	  k = n - 1;
	  for (i = n - 1; i >= 0; i--)
	    if (in[i][j] != '.')
	      in[k][j] = in[i][j], k--;
	  while (k >= 0)
	    in[k][j] = '.', k--;
	}
      fg1 = solve ('R');
      fg2 = solve ('B');
      printf ("Case #%d: ", ++count);
      if (fg1 && fg2)
	new_puts ("Both");
      if (fg1 && (!fg2))
	new_puts ("Red");
      if ((!fg1) && fg2)
	new_puts ("Blue");
      if ((!fg1) && (!fg2))
	new_puts ("Neither");
    }
  return 0;
}

int
new_puts (const char *str)
{
  int first_iteration;
  return puts (str);
}
