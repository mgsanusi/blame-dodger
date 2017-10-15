#include <stdio.h>
int a[110][2];
int b[110][2];
int
main (void)
{
  int first_iteration;
  int ti;
  int tn;
  scanf ("%d", &tn);
  for (ti = 1; ti <= tn; ti++)
    {
      int i;
      int j;
      int n;
      int an = 0;
      int bn = 0;
      int ap = 1;
      int bp = 1;
      int t;
      int ai;
      int bi;
      scanf ("%d ", &n);
      for (i = 0; i < n; i++)
	{
	  char c;
	  int x;
	  scanf ("%c %d ", &c, &x);
	  if (c == 'O')
	    {
	      a[an][0] = x;
	      a[an++][1] = i;
	    }
	  else
	    {
	      b[bn][0] = x;
	      b[bn++][1] = i;
	    }
	}
      a[an][1] = n;
      b[bn][1] = n;
      for (t = 0, ai = 0, bi = 0; (ai < an) || (bi < bn); t++)
	{
	  int pr = 0;
	  if ((a[ai][1] < b[bi][1]) && (a[ai][0] == ap))
	    {
	      ai++;
	      pr = 1;
	    }
	  if (((!pr) && (b[bi][1] < a[ai][1])) && (b[bi][0] == bp))
	    {
	      bi++;
	      pr = 2;
	    }
	  if ((pr != 1) && (a[ai][0] != ap))
	    {
	      if (a[ai][0] < ap)
		ap--;
	      else
		ap++;
	    }
	  if ((pr != 2) && (b[bi][0] != bp))
	    {
	      if (b[bi][0] < bp)
		bp--;
	      else
		bp++;
	    }
	}
      printf ("Case #%d: %d\n", ti, t);
    }
  return 0;
}
