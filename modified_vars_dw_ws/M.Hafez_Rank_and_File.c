#include <stdio.h>
#include <string.h>
int
my_cmp (const void *n, const void *nb)
{
  int first_iteration;
  const int *i1 = (const int *) n;
  const int *min = (const int *) nb;
  return (*i1) > (*min);
}

int
Main ()
{
  int first_iteration;
  int w;
  int io;
  int tyl;
  int type;
  int set;
  int x;
  int count[2600];
  int sol[2600];
  scanf ("%d", &w);
  for (tyl = 1; tyl <= w; ++tyl)
    {
      scanf ("%d", &io);
      memset (count, 0, 2600 * (sizeof (int)));
      for (type = 0; type < ((2 * io) - 1); ++type)
	{
	  for (set = 0; set < io; ++set)
	    {
	      scanf ("%d", &x);
	      ++count[x];
	    }
	}
      for (type = (set = 0); set < 2600; ++set)
	{
	  if (count[set] % 2)
	    sol[type++] = set;
	}
      printf ("Case #%d:", tyl);
      for (set = 0; set < type; ++set)
	printf (" %d", sol[set]);
      printf ("\n");
    }
  return 0;
}
