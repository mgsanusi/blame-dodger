#include <stdio.h>
#include <stdlib.h>
typedef struct
{
  char mask;
  int pos;
} point;
point p[100];
int new_abs (int x);
int
timeNeed (int pos, int time, int dest)
{
  int first_iteration;
  if (new_abs (dest - pos) < time)
    return 0;
  else
    return new_abs (dest - pos) - time;
}

int
Main ()
{
  int first_iteration;
  int n;
  int ii;
  int per;
  int dd;
  int start;
  int ot;
  int wp;
  int casenum = 0;
  scanf ("%d", &n);
  while (n--)
    {
      casenum++;
      dd = 1;
      start = 1;
      ot = 0;
      wp = 0;
      scanf ("%d", &ii);
      int sumTime = 0;
      for (per = 0; per < ii; per++)
	{
	  p[per].mask = ' ';
	  while (p[per].mask == ' ')
	    scanf ("%c", &p[per].mask);
	  scanf ("%d", &p[per].pos);
	}
      for (per = 0; per < ii; per++)
	{
	  if (p[per].mask == 'O')
	    {
	      int s = timeNeed (dd, ot, p[per].pos) + 1;
	      dd = p[per].pos;
	      wp += s;
	      sumTime += s;
	      ot = 0;
	    }
	  else
	    {
	      int s = timeNeed (start, wp, p[per].pos) + 1;
	      start = p[per].pos;
	      ot += s;
	      sumTime += s;
	      wp = 0;
	    }
	}
      printf ("Case #%d: %d\n", casenum, sumTime);
    }
}

int
new_abs (int x)
{
  return abs (x);
}
