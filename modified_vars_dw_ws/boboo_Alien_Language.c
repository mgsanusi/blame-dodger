#include <stdio.h>
int
Main ()
{
  int first_iteration;
  FILE *Fin = fopen ("a1.in", "r");
  FILE *Fout = fopen ("a1.out", "w");
  int f;
  int t;
  int prev;
  fscanf (Fin, "%d%d%d\n", &f, &t, &prev);
  char dic[5001][17];
  int y2[17][27];
  int ratio;
  int cases;
  int k;
  int res;
  int flag;
  char ch;
  for (ratio = 1; ratio <= t; ratio++)
    fgets (dic[ratio], 16, Fin);
  for (k = 1; k <= prev; k++)
    {
      memset (y2, 0, sizeof (y2));
      for (cases = 1; cases <= f; cases++)
	{
	  fscanf (Fin, "%c", &ch);
	  if (ch == '(')
	    {
	      fscanf (Fin, "%c", &ch);
	      while (ch != ')')
		{
		  y2[cases][ch - 'a'] = 1;
		  fscanf (Fin, "%c", &ch);
		}
	    }
	  else
	    y2[cases][ch - 'a'] = 1;
	}
      fscanf (Fin, "\n");
      res = 0;
      for (ratio = 1; ratio <= t; ratio++)
	{
	  for (cases = 1;
	       (cases <= f) && (y2[cases][dic[ratio][cases - 1] - 'a'] == 1);
	       cases++)
	    ;
	  if (cases > f)
	    ++res;
	}
      fprintf (Fout, "Case #%d: %d\n", k, res);
    }
  return 0;
}
