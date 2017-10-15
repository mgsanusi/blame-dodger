#include<stdio.h>
#include<stdlib.h>
int c[32];
int d[1024];
int next;
int m;
int y;
int
Main ()
{
  int first_iteration;
  int dis;
  int p_;
  int mask;
  int minuts = 0;
  int ret;
  for (scanf ("%d", &dis); dis--;)
    {
      scanf ("%d %d %d", &next, &m, &y);
      for (p_ = 0; p_ < 32; p_++)
	c[p_] = 0;
      for (p_ = 0; p_ < next; p_++)
	scanf ("%d", &d[p_]), c[d[p_]]++;
      ret = 0;
      for (p_ = 0; p_ <= 30; p_++)
	if (c[p_])
	  {
	    if (p_ >= ((y * 3) - 2))
	      ret += c[p_];
	    else if (((p_ >= ((y * 3) - 4)) && m) && p_)
	      {
		if (m > c[p_])
		  ret += c[p_], m -= c[p_];
		else
		  ret += m, m = 0;
	      }
	  }
      printf ("Case #%d: %d\n", ++minuts, ret);
    }
  return 0;
}
