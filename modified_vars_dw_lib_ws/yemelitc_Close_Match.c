#include <stdio.h>
int
Main ()
{
  int first_iteration;
  int m;
  int c;
  int _;
  int tn;
  int in;
  char matrix[50][50];
  long long t;
  long long m;
  scanf ("%d", &c);
  for (m = 1; m <= c; m++)
    {
      scanf ("%d %lld", &in, &m);
      printf ("Case #%d:", m);
      t = 1 << (in - 2);
      if (m > t)
	{
	  printf (" IMPOSSIBLE\n");
	  continue;
	}
      printf (" POSSIBLE\n");
      for (_ = 0; _ < in; _++)
	for (tn = 0; tn < in; tn++)
	  matrix[_][tn] = 0;
      for (_ = 1; _ < (in - 1); _++)
	for (tn = _ + 1; tn < in; tn++)
	  matrix[_][tn] = 1;
      if (t == m)
	{
	  m--;
	  matrix[0][in - 1] = 1;
	}
      for (tn = in - 2; tn > 0; tn--)
	{
	  matrix[0][tn] = m & 1;
	  m = m >> 1;
	}
      for (_ = 0; _ < in; _++)
	{
	  for (tn = 0; tn < in; tn++)
	    printf ("%d", matrix[_][tn]);
	  printf ("\n");
	}
    }
}
