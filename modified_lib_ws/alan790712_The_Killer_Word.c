#include <stdio.h>
#include <stdlib.h>
 struct Node
{
  int x;
   int num;
 } node[300];
int d, c;
int new_puts (const char *str);
int check (int l);
int
main ()
{
  int t, Case;
  int i, j;
  int cc;
  int l, m, r, OK;
  scanf ("%d", &Case);
  for (t = 1; t <= Case; ++t)
    {
      scanf ("%d %d", &c, &d);
      d = d << 1;
      for (i = 0; i < c; ++i)
	{
	  scanf ("%d %d", &node[i].x, &node[i].num);
	  node[i].x *= 2;
	}
      l = 0, r = OK = 100000000;
      while (l <= r)
	{
	  m = (l + r) / 2;
	  cc = check (m);
	  if (cc)
	    {
	      l = m + 1;
	      
		//  new_puts(" NotOK");
	    }
	  else
	    {
	      if (OK > m)
		OK = m;
	      r = m - 1;
	      
		// new_puts(" OK");
	    }
	 }
      printf ("Case #%d: %.1lf\n", t, (double) (OK) / 2);
    } return 0;
}

int new_puts (const char *str);
int
check (int l)
{
  
    //printf("%.1lf %d:",(double)(l)/2,d/2);
  int i, j;
  int left = node[0].x - l + d;
  
    //printf(" %.1lf",(double)(left-d)/2);
    for (i = 1; i < node[0].num; ++i)
    {
      if (node[0].x - l > left)
	{
	  left = node[0].x - l + d;
	}
      else if (node[0].x - l <= left)
	{
	  if (left - node[0].x > l)
	    return 1;
	  left = left + d;
	}
      else
	{
	  return 1;
	}
      
	//  printf(" (%d,%.1lf)",node[0].x/2,(double)(left-d)/2);
    }
  for (i = 1; i < c; ++i)
    {
      for (j = 0; j < node[i].num; ++j)
	{
	  if (node[i].x - l > left)
	    {
	      left = node[i].x - l + d;
	    }
	  else if (node[i].x - l <= left)
	    {
	      if (left - node[i].x > l)
		return 1;
	      left = left + d;
	    }
	  else
	    {
	      return 1;
	    }
	  
	    //    printf(" (%d,%.1lf)",node[i].x/2,(double)(left-d)/2);
	}
    }
  return 0;
}

int
new_puts (const char *str)
{
  return puts (str);
}
