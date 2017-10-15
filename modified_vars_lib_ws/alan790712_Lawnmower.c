#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int data2;
int m;
int map[123][123];
int gg;
int new_puts (const char *str);
int
Main ()
{
  int t;
  int v;
  int speed;
  int depth;
  int d;
  int max;
  scanf ("%d", &v);
  for (t = 1; t <= v; ++t)
    {
      scanf ("%d %d", &data2, &m);
      memset (map, 0, sizeof (map));
      for (speed = (max = 1); speed <= data2; ++speed)
	{
	  for (depth = 1; depth <= m; ++depth)
	    {
	      scanf ("%d", &map[speed][depth]);
	      if (map[speed][depth] >= max)
		max = map[speed][depth];
	    }
	}
      gg = 0;
      for (speed = 1; (speed <= data2) && (!gg); ++speed)
	{
	  for (depth = 1; (depth <= m) && (!gg); ++depth)
	    {
	      for (d = 1; (d <= m) && (map[speed][d] <= map[speed][depth]);
		   ++d)
		;
	      if (d > m)
		continue;
	      for (d = 1;
		   (d <= data2) && (map[d][depth] <= map[speed][depth]); ++d)
		;
	      if (d <= data2)
		gg = 1;
	    }
	}
      printf ("Case #%d: ", t);
      if (!gg)
	new_puts ("YES");
      else
	new_puts ("NO");
    }
  return 0;
}

int
new_puts (const char *str)
{
  return puts (str);
}
