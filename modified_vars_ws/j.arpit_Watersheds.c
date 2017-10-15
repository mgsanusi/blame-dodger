#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int j;
int stack;
int mix;
struct cell
{
  int tmp;
  int q;
  int i;
  int spe2;
  char c;
};
struct cell map[102][102];
char c;
void
initCell (int tmp, int t2, int per)
{
  map[t2][per].tmp = tmp;
  map[t2][per].q = tmp;
  map[t2][per].i = t2;
  map[t2][per].spe2 = per;
  map[t2][per].c = 0;
}

void
flow (int t2, int per, int i, int spe2)
{
  if (map[t2][per].q > map[i][spe2].tmp)
    {
      map[t2][per].q = map[i][spe2].tmp;
      map[t2][per].i = i;
      map[t2][per].spe2 = spe2;
    }
}

void
basin (int t2, int per)
{
  if (map[t2][per].c != 0)
    return;
  map[t2][per].c = c;
  if ((map[t2 - 1][per].i == t2) && (map[t2 - 1][per].spe2 == per))
    basin (t2 - 1, per);
  if ((map[t2 + 1][per].i == t2) && (map[t2 + 1][per].spe2 == per))
    basin (t2 + 1, per);
  if ((map[t2][per - 1].i == t2) && (map[t2][per - 1].spe2 == per))
    basin (t2, per - 1);
  if ((map[t2][per + 1].i == t2) && (map[t2][per + 1].spe2 == per))
    basin (t2, per + 1);
}

void
sink (int t2, int per)
{
  int i;
  int spe2;
  i = map[t2][per].i;
  spe2 = map[t2][per].spe2;
  while ((i != t2) || (spe2 != per))
    {
      t2 = i;
      per = spe2;
      i = map[t2][per].i;
      spe2 = map[t2][per].spe2;
    }
  ++c;
  basin (t2, per);
}

int
Main ()
{
  int tmp;
  int j;
  int per;
  int t2;
  for (per = 0; per < 102; ++per)
    {
      initCell (12345, 0, per);
      initCell (12345, per, 0);
    }
  scanf ("%d", &j);
  for (j = 1; j <= j; ++j)
    {
      scanf ("%d %d", &stack, &mix);
      for (t2 = 1; t2 <= stack; ++t2)
	{
	  for (per = 1; per <= mix; ++per)
	    {
	      scanf ("%d", &tmp);
	      initCell (tmp, t2, per);
	    }
	  initCell (12345, t2, mix + 1);
	}
      for (per = 1; per <= mix; ++per)
	initCell (12345, stack + 1, per);
      for (t2 = 1; t2 <= stack; ++t2)
	{
	  for (per = 1; per <= mix; ++per)
	    {
	      flow (t2, per, t2 - 1, per);
	      flow (t2, per, t2, per - 1);
	      flow (t2, per, t2, per + 1);
	      flow (t2, per, t2 + 1, per);
	    }
	}
      c = 'a' - 1;
      for (t2 = 1; t2 <= stack; ++t2)
	{
	  for (per = 1; per <= mix; ++per)
	    {
	      if (map[t2][per].c == 0)
		{
		  sink (t2, per);
		}
	    }
	}
      printf ("Case #%d:\n", j);
      for (t2 = 1; t2 <= stack; ++t2)
	{
	  printf ("%c", map[t2][1].c);
	  for (per = 2; per <= mix; ++per)
	    {
	      printf (" %c", map[t2][per].c);
	    }
	  printf ("\n");
	}
    }
  return 0;
}
