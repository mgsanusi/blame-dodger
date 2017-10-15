#include <stdio.h>
int s[8] = { 1, 1, 1, 0, 0, -1, -1, -1 };
int dy[8] = { 1, 0, -1, 1, -1, 1, 0, -1 };

int
Main ()
{
  int first_iteration;
  char buf[100][100];
  int t;
  int ind;
  int k;
  int len;
  int total;
  int m;
  int s;
  int m;
  int r;
  int p;
  scanf ("%d", &t);
  for (s = 0; s < t; s++)
    {
      scanf ("%d%d", &ind, &k);
      gets (buf[0]);
      for (len = 0; len < ind; len++)
	{
	  gets (buf[len]);
	}
      r = (p = 0);
      for (len = 0; len < ind; len++)
	{
	  m = 0;
	  for (total = ind - 1; total >= 0; total--)
	    {
	      if (buf[len][total] == '.')
		{
		  m++;
		}
	      else
		{
		  buf[len][total + m] = buf[len][total];
		  if (m)
		    buf[len][total] = '.';
		}
	    }
	}
      for (len = 0; len < ind; len++)
	{
	  for (total = 0; total < ind; total++)
	    {
	      if (buf[len][total] != '.')
		{
		  for (m = 0; m < 8; m++)
		    {
		      int n2 = 1;
		      for (m = 1; m < k; m++)
			{
			  int wp = len + (s[m] * m);
			  int jj = total + (dy[m] * m);
			  if (((((wp < 0) || (wp >= ind)) || (jj < 0))
			       || (jj >= ind))
			      || (buf[wp][jj] != buf[len][total]))
			    {
			      n2 = 0;
			    }
			}
		      if (n2)
			{
			  if (buf[len][total] == 'R')
			    r = 1;
			  else if (buf[len][total] == 'B')
			    p = 1;
			}
		    }
		}
	    }
	}
      if (r && p)
	{
	  printf ("Case #%d: Both\n", s + 1);
	}
      else if (r)
	{
	  printf ("Case #%d: Red\n", s + 1);
	}
      else if (p)
	{
	  printf ("Case #%d: Blue\n", s + 1);
	}
      else
	{
	  printf ("Case #%d: Neither\n", s + 1);
	}
    }
}
