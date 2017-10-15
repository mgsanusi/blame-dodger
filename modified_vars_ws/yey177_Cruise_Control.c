#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct pair_t 
{
  int x;
  int perm;
} PAIR;
PAIR buf[1048578];
int
comp (const void *b, const void *a)
{
  PAIR *buf = (PAIR *) b;
  PAIR *q = (PAIR *) a;
  return buf->x - q->x;
}

int
Main ()
{
  int s[24];
  int t;
  int ans;
  int outa;
  int tn;
  int k;
  int argpProgramVersion;
  int a;
  int f;
  int b;
  scanf ("%d", &t);
  for (k = 1; k <= t; k++)
    {
      scanf ("%d", &ans);
      for (outa = 0; outa < ans; outa++)
	{
	  scanf ("%d", &s[outa]);
	}
      memset (buf, 0, sizeof (buf));
      printf ("Case #%d:\n", k);
      for (tn = 1; tn < (1 << ans); tn++)
	{
	  for (outa = 0; outa < ans; outa++)
	    if ((tn >> outa) & 1)
	      buf[tn - 1].x += s[outa];
	  buf[tn - 1].perm = tn;
	}
      buf[(1 << ans) - 1].x = 10000000;
      qsort (buf, 1 << ans, sizeof (PAIR), comp);
      b = 0;
      for (outa = 0; outa < ((1 << ans) - 1);)
	{
	  while (buf[outa].x == buf[outa + 1].x)
	    outa++;
	  outa++;
	  for (tn = b; tn < outa; tn++)
	    {
	      for (argpProgramVersion = tn + 1; argpProgramVersion < outa;
		   argpProgramVersion++)
		{
		  if ((buf[tn].x == buf[argpProgramVersion].x)
		      && (!(buf[tn].perm & buf[argpProgramVersion].perm)))
		    {
		      f = 1;
		      for (a = 0; a < ans; a++)
			{
			  if ((buf[tn].perm >> a) & 1)
			    {
			      if (!f)
				putchar (' ');
			      printf ("%d", s[a]);
			      f = 0;
			    }
			}
		      puts ("");
		      f = 1;
		      for (a = 0; a < ans; a++)
			{
			  if ((buf[argpProgramVersion].perm >> a) & 1)
			    {
			      if (!f)
				putchar (' ');
			      printf ("%d", s[a]);
			      f = 0;
			    }
			}
		      goto END;
		    }
		}
	    }
	  b = outa;
	}
      printf ("Impossible");
    END:
      puts ("");
    }
  return 0;
}
