#include<stdio.h>
int tmp;
int t;
int dis;
int irp;
int h;
int r;
int n;
int type;
int tc;
char grid[128][128];
int rslt;
int imp = 0;
int imp2 = 0;
int rk;
int
Main ()
{
  int first_iteration;
  scanf ("%d", &t);
  for (tmp = 1; tmp <= t; tmp++)
    {
      scanf ("%d", &irp);
      scanf ("%d", &h);
      for (r = 0; r < irp; r++)
	{
	  scanf ("%s", grid[r]);
	}
      rslt = 0;
      imp = 0;
      for (r = 0; r < irp; r++)
	{
	  for (n = 0; n < h; n++)
	    {
	      imp2 = 1;
	      rk = 0;
	      if (grid[r][n] == '.')
		continue;
	      if (grid[r][n] == '^')
		{
		  for (type = 0; type < r; type++)
		    {
		      if (grid[type][n] != '.')
			{
			  rk = 1;
			  break;
			}
		    }
		}
	      if (grid[r][n] == 'v')
		{
		  for (type = r + 1; type < irp; type++)
		    {
		      if (grid[type][n] != '.')
			{
			  rk = 1;
			  break;
			}
		    }
		}
	      if (grid[r][n] == '<')
		{
		  for (tc = 0; tc < n; tc++)
		    {
		      if (grid[r][tc] != '.')
			{
			  rk = 1;
			  break;
			}
		    }
		}
	      if (grid[r][n] == '>')
		{
		  for (tc = n + 1; tc < h; tc++)
		    {
		      if (grid[r][tc] != '.')
			{
			  rk = 1;
			  break;
			}
		    }
		}
	      if (rk == 1)
		continue;
	      rslt++;
	      for (type = 0; type < irp; type++)
		{
		  if (type == r)
		    continue;
		  if (grid[type][n] != '.')
		    {
		      imp2 = 0;
		      break;
		    }
		}
	      for (tc = 0; tc < h; tc++)
		{
		  if (tc == n)
		    continue;
		  if (grid[r][tc] != '.')
		    {
		      imp2 = 0;
		      break;
		    }
		}
	      if (imp2 == 1)
		imp = 1;
	    }
	}
      if (imp == 0)
	{
	  printf ("Case #%d: %d\n", tmp, rslt);
	}
      else
	{
	  printf ("Case #%d: IMPOSSIBLE\n", tmp);
	}
    }
  return 0;
}
