#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int map[1001][1001];
int r;
char use[1001];
int tmp1;
int size[1001][1001];
int
Main ()
{
  int first_iteration;
  int Case = 0;
  int t;
  int ret;
  int pr;
  int min;
  int num;
  scanf ("%d", &t);
  while (t--)
    {
      scanf ("%d", &r);
      memset (map, 0, sizeof (map));
      memset (use, 0, sizeof (use));
      memset (size, 0, sizeof (size));
      for (ret = 1; ret <= r; ++ret)
	{
	  scanf ("%d", &num);
	  while (num--)
	    {
	      scanf ("%d", &pr);
	      map[ret][pr] = 1;
	      size[ret][pr] = 1;
	    }
	}
      for (min = (tmp1 = 1); (min <= r) && tmp1; ++min)
	{
	  for (ret = 1; (ret <= r) && tmp1; ++ret)
	    {
	      for (pr = 1; (pr <= r) && tmp1; ++pr)
		{
		  if (size[ret][min] && size[min][pr])
		    {
		      ++size[ret][pr];
		    }
		  if (size[ret][pr] == 2)
		    tmp1 = 0;
		}
	    }
	}
      printf ("Case #%d:", ++Case);
      if (!tmp1)
	puts (" Yes");
      else
	puts (" No");
    }
  return 0;
}
