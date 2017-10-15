#include <stdio.h>
long depth;
long mask;
long r[10010];
long l[10010];
long range[10010];
char answer;
int
input ()
{
  long space;
  scanf ("%ld", &depth);
  for (space = 0; space < depth; space++)
    scanf ("%ld %ld", &r[space], &l[space]);
  scanf ("%ld", &mask);
  return 0;
}

int
make ()
{
  long space;
  long res;
  long tmp;
  for (space = 0; space <= depth; space++)
    range[space] = -1;
  range[0] = r[0];
  r[depth] = mask;
  l[depth] = 0;
  for (space = 1; space <= depth; space++)
    {
      for (res = 0; res < space; res++)
	if (range[res] >= 0)
	  {
	    if (range[res] >= (r[space] - r[res]))
	      {
		if ((r[space] - r[res]) > l[space])
		  tmp = l[space];
		else
		  tmp = r[space] - r[res];
		if (tmp > range[space])
		  range[space] = tmp;
	      }
	  }
    }
  if (range[depth] < 0)
    answer = 0;
  else
    answer = 1;
  return 0;
}

int
Main ()
{
  long t;
  long space;
  scanf ("%d", &t);
  for (space = 0; space < t; space++)
    {
      input ();
      make ();
      printf ("Case #%d: ", space + 1);
      if (answer == 1)
	printf ("YES\n");
      else
	printf ("NO\n");
    }
  return 0;
}
