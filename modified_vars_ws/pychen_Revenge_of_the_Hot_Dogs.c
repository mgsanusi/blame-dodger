#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int
Main ()
{
  int dc;
  int tCase;
  scanf ("%d", &tCase);
  for (dc = 1; dc <= tCase; dc++)
    {
      int l;
      int t;
      int e;
      int c;
      int a[100000];
      int m[100000];
      scanf ("%d %d %d %d", &l, &t, &e, &c);
      int ti;
      int j;
      int answer = 1000000000;
      for (ti = 0; ti < c; ti++)
	scanf ("%d", &a[ti]);
      for (ti = 0; ti < e; ti++)
	m[ti] = a[ti % c];
      for (ti = 0; ti < e; ti++)
	for (j = ti; j < e; j++)
	  {
	    int tmp = 0;
	    int b;
	    for (b = 0; b < e; b++)
	      if (((b == ti) && (l >= 1)) || ((b == j) && (l == 2)))
		{
		  if (tmp >= t)
		    tmp += m[b];
		  else if ((tmp + (m[b] * 2)) >= t)
		    tmp = t + (m[b] - ((t - tmp) / 2));
		  else
		    tmp += m[b] * 2;
		}
	      else
		tmp += m[b] * 2;
	    answer = answer < tmp ? answer : tmp;
	  }
      printf ("Case #%d: %d\n", dc, answer);
    }
  return 0;
}
