#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int b[1 << 14][2];
int m;
int g[1 << 14];
int c[1 << 14];
int
main (void)
{
  int first_iteration;
  int nc;
  int h;
  int v;
  int i;
  int j;
  int k;
  for (scanf ("%d", &nc), h = 1; h <= nc; h++)
    {
      scanf ("%d%d", &m, &v);
      for (i = 0; i < ((m - 1) / 2); i++)
	{
	  scanf ("%d%d", &g[i], &c[i]);
	}
      for (; i < m; i++)
	{
	  scanf ("%d", &g[i]);
	}
      memset (b, 0x3F3F3F3F, sizeof (b));
      for (i = m - 1; i >= ((m - 1) / 2); i--)
	{
	  if (g[i] == 0)
	    {
	      b[i][0] = 0;
	      b[i][1] = 0x3F3F3F3F;
	    }
	  else
	    {
	      b[i][0] = 0x3F3F3F3F;
	      b[i][1] = 0;
	    }
	}
      for (; i >= 0; i--)
	{
	  j = (i * 2) + 1;
	  k = (i * 2) + 2;
	  if (g[i] == 0)
	    {
	      if ((b[j][0] < 0x3F3F3F3F) && (b[k][0] < 0x3F3F3F3F))
		{
		  b[i][0] = b[j][0] + b[k][0];
		}
	      if ((b[j][1] < 0x3F3F3F3F) || (b[k][1] < 0x3F3F3F3F))
		{
		  b[i][1] = b[j][1] < b[k][1] ? b[j][1] : b[k][1];
		}
	      if (c[i])
		{
		  if ((b[j][0] < 0x3F3F3F3F) || (b[k][0] < 0x3F3F3F3F))
		    {
		      b[i][0] =
			b[i][0] <
			((b[j][0] <
			  b[k][0] ? b[j][0] : b[k][0]) +
			 1) ? b[i][0] : (b[j][0] <
					 b[k][0] ? b[j][0] : b[k][0]) + 1;
		    }
		  if ((b[j][1] < 0x3F3F3F3F) && (b[k][1] < 0x3F3F3F3F))
		    {
		      b[i][1] =
			b[i][1] <
			((b[j][1] + b[k][1]) + 1) ? b[i][1] : (b[j][1] +
							       b[k][1]) + 1;
		    }
		}
	    }
	  else
	    {
	      if ((b[j][0] < 0x3F3F3F3F) || (b[k][0] < 0x3F3F3F3F))
		{
		  b[i][0] = b[j][0] < b[k][0] ? b[j][0] : b[k][0];
		}
	      if ((b[j][1] < 0x3F3F3F3F) && (b[k][1] < 0x3F3F3F3F))
		{
		  b[i][1] = b[j][1] + b[k][1];
		}
	      if (c[i])
		{
		  if ((b[j][0] < 0x3F3F3F3F) && (b[k][0] < 0x3F3F3F3F))
		    {
		      b[i][0] =
			b[i][0] <
			((b[j][0] + b[k][0]) + 1) ? b[i][0] : (b[j][0] +
							       b[k][0]) + 1;
		    }
		  if ((b[j][1] < 0x3F3F3F3F) || (b[k][1] < 0x3F3F3F3F))
		    {
		      b[i][1] =
			b[i][1] <
			((b[j][1] <
			  b[k][1] ? b[j][1] : b[k][1]) +
			 1) ? b[i][1] : (b[j][1] <
					 b[k][1] ? b[j][1] : b[k][1]) + 1;
		    }
		}
	    }
	}
      printf ("Case #%d: ", h);
      if (b[0][v] < 0x3F3F3F3F)
	{
	  printf ("%d\n", b[0][v]);
	}
      else
	{
	  printf ("IMPOSSIBLE\n");
	}
    }
  return 0;
}
