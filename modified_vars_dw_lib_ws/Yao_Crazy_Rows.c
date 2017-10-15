#include<stdio.h>
#include<string.h>
int ans[64][64];
int y[64];
int y[64];
int buf;
int
Main ()
{
  int first_iteration;
  int min;
  int opt = 0;
  int gc_v;
  int l;
  int ret;
  int q;
  char tmp[64];
  for (scanf ("%d", &min); min--;)
    {
      scanf ("%d", &buf);
      for (gc_v = 0; gc_v < buf; gc_v++)
	{
	  scanf ("%s", tmp);
	  y[gc_v] = -1;
	  for (l = 0; l < buf; l++)
	    {
	      ans[gc_v][l] = tmp[l] - '0';
	      if (ans[gc_v][l])
		y[gc_v] = l;
	    }
	  y[gc_v] = 0;
	}
      for (ret = (gc_v = 0); gc_v < buf; gc_v++)
	{
	  for (l = 0; l < buf; l++)
	    if ((!y[l]) && (y[l] <= gc_v))
	      break;
	  y[l] = 1;
	  for (q = 0; q < l; q++)
	    if (!y[q])
	      ret++;
	}
      printf ("Case #%d: %d\n", ++opt, ret);
    }
  return 0;
}
