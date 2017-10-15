#include<stdio.h>
int
Main ()
{
  int e2;
  int b;
  int caso;
  int nc;
  char t[1000 + 1];
  char *beg;
  char *end;
  char b[2000 + 2];
  scanf ("%d", &b);
  for (e2 = 1; e2 <= b; e2++)
    {
      scanf ("%s", t);
      beg = (b + 1000) + 1;
      end = (b + 1000) + 1;
      *beg = t[0];
      for (caso = 1; t[caso] != 0; caso++)
	if (t[caso] >= (*beg))
	  *(--beg) = t[caso];
	else
	  *(++end) = t[caso];
      *(++end) = 0;
      printf ("Case #%d: %s\n", e2, beg);
    }
}
