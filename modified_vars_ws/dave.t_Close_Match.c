#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *file_name_in = "input.txt";
char *file_name_out = "output.txt";
FILE *in;
FILE *out;
int k[27];
int s[27];
int
cmp_p (const void *v, const void *b)
{
  int r = k[*((int *) v)];
  int b = k[*((int *) b)];
  if (r > b)
    return -1;
  if (r == b)
    return 0;
  return 1;
}

int
Main (void)
{
  int t;
  int r;
  int n;
  int pp;
  int y;
  int i;
  in = fopen (file_name_in, "r");
  out = fopen (file_name_out, "w");
  fscanf (in, "%d", &r);
  for (t = 1; t <= r; t++)
    {
      fprintf (out, "Case #%d:", t);
      fscanf (in, "%d", &pp);
      i = 0;
      for (n = 1; n <= pp; ++n)
	{
	  fscanf (in, "%d", &k[n]);
	  i += k[n];
	  s[n - 1] = n;
	}
      qsort (s, pp, sizeof (int), cmp_p);
      while (i > 3)
	{
	  if (k[s[0]] > k[s[1]])
	    {
	      fprintf (out, " %c", ('A' - 1) + s[0]);
	      k[s[0]] -= 1;
	      i--;
	    }
	  else
	    {
	      fprintf (out, " %c%c", ('A' - 1) + s[0], ('A' - 1) + s[1]);
	      k[s[0]] -= 1;
	      k[s[1]] -= 1;
	      i--;
	      i--;
	      qsort (s, pp, sizeof (int), cmp_p);
	    }
	}
      qsort (s, pp, sizeof (int), cmp_p);
      if (i == 3)
	{
	  fprintf (out, " %c", ('A' - 1) + s[0]);
	  fprintf (out, " %c%c", ('A' - 1) + s[1], ('A' - 1) + s[2]);
	}
      else
	{
	  fprintf (out, " %c%c", ('A' - 1) + s[0], ('A' - 1) + s[1]);
	}
      fprintf (out, "\n");
    }
  fclose (in);
  fclose (out);
}
