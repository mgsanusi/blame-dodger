#include <stdio.h>
#include <stdlib.h>
struct Node
{
  int v;
  int num;
} node[300];
int d;
int c;
int new_puts (const char *str);
int check (int l);
int
Main ()
{
  int first_iteration;
  int svc_ah_wrap;
  int Case;
  int prob_for;
  int c0;
  int update_num_buttons_pressed;
  int l;
  int length;
  int aa;
  int y1;
  scanf ("%d", &Case);
  for (svc_ah_wrap = 1; svc_ah_wrap <= Case; ++svc_ah_wrap)
    {
      scanf ("%d %d", &c, &d);
      d = d << 1;
      for (prob_for = 0; prob_for < c; ++prob_for)
	{
	  scanf ("%d %d", &node[prob_for].v, &node[prob_for].num);
	  node[prob_for].v *= 2;
	}
      l = 0, aa = (y1 = 100000000);
      while (l <= aa)
	{
	  length = (l + aa) / 2;
	  update_num_buttons_pressed = check (length);
	  if (update_num_buttons_pressed)
	    {
	      l = length + 1;
	    }
	  else
	    {
	      if (y1 > length)
		y1 = length;
	      aa = length - 1;
	    }
	}
      printf ("Case #%d: %.1lf\n", svc_ah_wrap, ((double) y1) / 2);
    }
  return 0;
}

int new_puts (const char *str);
int
check (int l)
{
  int first_iteration;
  int prob_for;
  int c0;
  int left = (node[0].v - l) + d;
  for (prob_for = 1; prob_for < node[0].num; ++prob_for)
    {
      if ((node[0].v - l) > left)
	{
	  left = (node[0].v - l) + d;
	}
      else if ((node[0].v - l) <= left)
	{
	  if ((left - node[0].v) > l)
	    return 1;
	  left = left + d;
	}
      else
	{
	  return 1;
	}
    }
  for (prob_for = 1; prob_for < c; ++prob_for)
    {
      for (c0 = 0; c0 < node[prob_for].num; ++c0)
	{
	  if ((node[prob_for].v - l) > left)
	    {
	      left = (node[prob_for].v - l) + d;
	    }
	  else if ((node[prob_for].v - l) <= left)
	    {
	      if ((left - node[prob_for].v) > l)
		return 1;
	      left = left + d;
	    }
	  else
	    {
	      return 1;
	    }
	}
    }
  return 0;
}

int
new_puts (const char *str)
{
  return puts (str);
}
