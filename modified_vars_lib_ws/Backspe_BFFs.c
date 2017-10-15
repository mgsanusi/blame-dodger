#include <stdio.h>
typedef long long ll;
int r;
int s[120][60];
int caseno[60][120];
int a[60][2];
int count[120];
int rslt[60];
int rc;
int rcp;
int
nsort ()
{
  int label;
  int j;
  int tmp;
  int rn;
  for (rn = 0; rn < r; rn++)
    {
      for (label = 0; label < ((2 * r) - 1); label++)
	caseno[rn][label] = s[label][rn];
      for (label = 0; label < (((2 * r) - 1) - 1); label++)
	{
	  for (j = 1; j < (((2 * r) - 1) - label); j++)
	    {
	      if (caseno[rn][label] > caseno[rn][label + j])
		{
		  tmp = caseno[rn][label];
		  caseno[rn][label] = caseno[rn][label + j];
		  caseno[rn][label + j] = tmp;
		}
	    }
	}
    }
  return 0;
}

int
Main ()
{
  int y;
  int dx;
  int label;
  int j;
  int p;
  int cl_ops[2];
  scanf ("%d", &dx);
  for (y = 1; y <= dx; y++)
    {
      scanf ("%d", &r);
      for (label = 0; label < 60; label++)
	{
	}
      for (label = 0; label < 60; label++)
	{
	  for (j = 0; j < 120; j++)
	    {
	      caseno[label][j] = 0;
	      s[j][label] = 0;
	      count[j] = 0;
	    }
	  a[label][0] = (a[label][1] = 0);
	}
      for (label = 0; label < ((2 * r) - 1); label++)
	{
	  for (j = 0; j < r; j++)
	    {
	      scanf ("%d", &s[label][j]);
	    }
	}
      nsort ();
      for (label = 0; label < r; label++)
	{
	  p = caseno[label][label * 2];
	  for (j = 0; j < ((2 * r) - 1); j++)
	    {
	      if (s[j][label] == p)
		{
		  a[label][count[label]] = j;
		  count[label]++;
		}
	    }
	  if (count[label] == 1)
	    {
	      rc = label;
	      rcp = p;
	    }
	}
      printf ("Case #%d:", y);
      int cnt2 = 0;
      for (label = 0; label < ((2 * r) - 1); label++)
	{
	  if (caseno[rc][label] == s[a[rc][0]][cnt2])
	    {
	      if (caseno[rc][label] != rcp)
		{
		  caseno[rc][label] = -1;
		}
	      cnt2++;
	    }
	  if (caseno[rc][label] != (-1))
	    printf (" %d", caseno[rc][label]);
	}
      printf ("\n");
    }
}
