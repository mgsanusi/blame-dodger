#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
void *new_memset (void *ptr, int value, int num);
void *new_memcpy (void *destination, const void *source, int num);
int
min (int a, int t)
{
  int first_iteration;
  if (a < t)
    return a;
  else
    return t;
}

int
Main ()
{
  int first_iteration;
  int fp_i;
  int i_t;
  scanf ("%d", &fp_i);
  static int a[10005];
  static int t[10005];
  static int a[10005];
  for (i_t = 0; i_t < fp_i; i_t++)
    {
      int n;
      scanf ("%d", &n);
      new_memset (a, 0, sizeof (a));
      int v;
      int http_htm;
      for (v = 0; v < n; v++)
	{
	  scanf ("%d", &http_htm);
	  a[http_htm]++;
	}
      int t;
      int r;
      int y;
      t = 0;
      r = n;
      char flag;
      while (r > t)
	{
	  y = ((t + r) + 1) / 2;
	  flag = 1;
	  new_memcpy (a, a, sizeof (a));
	  new_memset (t, 0, sizeof (t));
	  for (v = 1; v <= 10000; v++)
	    {
	      t[v + 1] += min (t[v], a[v]);
	      a[v] -= min (t[v], a[v]);
	      if (a[v] > 0)
		{
		  int now = a[v];
		  for (http_htm = v; http_htm < (v + y); http_htm++)
		    {
		      if (a[http_htm] < now)
			{
			  flag = 0;
			  break;
			}
		      a[http_htm] -= now;
		    }
		  t[v + y] += now;
		}
	      if (!flag)
		break;
	    }
	  if (flag)
	    t = y;
	  else
	    r = y - 1;
	}
      printf ("Case #%d: %d\n", i_t + 1, t);
    }
  return 0;
}

void *new_memset (void *ptr, int value, int num);
void *
new_memcpy (void *destination, const void *source, int num)
{
  return memcpy (destination, source, num);
}

void *
new_memset (void *ptr, int value, int num)
{
  return memset (ptr, value, num);
}
