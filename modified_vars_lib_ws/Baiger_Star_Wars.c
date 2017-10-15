#include <stdio.h>
#include <string.h>
int
Main ()
{
  int n;
  int count;
  scanf ("%d", &n);
  for (count = 1; count <= n; count++)
    {
      int len;
      int bt;
      int r;
      int nc;
      int ib;
      int r;
      int b;
      int d[100 + 2][100 + 2];
      scanf ("%d %d %d", &len, &bt, &r);
      memset (d, 0, sizeof (d));
      d[0][0] = 1;
      for (nc = 0; nc < r; nc++)
	{
	  scanf ("%d %d", &r, &b);
	  d[r - 1][b - 1] = -1;
	}
      for (nc = 0; nc < len; nc++)
	for (ib = 0; ib < bt; ib++)
	  if (d[nc][ib] != (-1))
	    {
	      if (d[nc + 1][ib + 2] != (-1))
		d[nc + 1][ib + 2] = (d[nc + 1][ib + 2] + d[nc][ib]) % 10007;
	      if (d[nc + 2][ib + 1] != (-1))
		d[nc + 2][ib + 1] = (d[nc + 2][ib + 1] + d[nc][ib]) % 10007;
	    }
      printf ("Case #%d: %d\n", count, d[len - 1][bt - 1]);
    }
  return 0;
}
