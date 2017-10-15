#include <stdio.h>
int
clear (int first, int cnt)
{
  int first_iteration;
  return (((cnt + first) / 2) * 2) - first;
}

int
Main ()
{
  int first_iteration;
  int q;
  int t;
  char s[200];
  int i;
  int rmCmb;
  int l;
  scanf ("%d", &t);
  for (q = 1; q <= t; q++)
    {
      scanf ("%s", s);
      printf ("Case #%d: ", q);
      rmCmb = 1;
      l = s[0] == '+' ? 0 : 1;
      for (i = 1; s[i] != '\0'; i++)
	{
	  if (s[i - 1] != s[i])
	    rmCmb++;
	}
      printf ("%d\n", clear (l, rmCmb));
    }
}
