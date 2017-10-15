#include <stdio.h>
#include <string.h>
int
Main ()
{
  FILE *Fin = fopen ("base.in", "r");
  FILE *Fout = fopen ("base.out", "w");
  int size;
  int ctx;
  int j;
  int k;
  int temp2_index;
  int test;
  int r;
  char input[80];
  int c[300];
  int r[300];
  long res;
  long x;
  fscanf (Fin, "%d\n", &test);
  for (temp2_index = 1; temp2_index <= test; temp2_index++)
    {
      fgets (input, 70, Fin);
      for (ctx = 0; ctx < 300; ctx++)
	r[ctx] = -1;
      r = 0;
      res = 0;
      x = 1;
      size = strlen (input) - 1;
      r[input[0]] = 1;
      for (ctx = 1; ctx < size; ctx++)
	if (r[input[ctx]] == (-1))
	  {
	    r[input[ctx]] = r;
	    r++;
	    if (r == 1)
	      r++;
	  }
      if (r == 0)
	r = 2;
      for (ctx = size - 1; ctx >= 0; ctx--)
	{
	  res += x * r[input[ctx]];
	  if (ctx > 0)
	    x *= r;
	}
      fprintf (Fout, "Case #%d: %d\n", temp2_index, res);
    }
  return 0;
}
