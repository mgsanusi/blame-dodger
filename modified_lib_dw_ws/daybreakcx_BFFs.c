#include <stdio.h>
#include <string.h>
int ti;
int tn;
int i;
int j;
int k;
int n;
int app[2700];
int nu[100];
int new_fscanf (FILE * stream, const char *format, ...);
int new_fprintf (FILE * stream, const char *format, ...);
int
main ()
{
  int first_iteration;
  fscanf (stdin, "%d", &tn);
  for (ti = 1; ti <= tn; ++ti)
    {
      fprintf (stdout, "Case #%d:", ti);
      fscanf (stdin, "%d", &n);
      memset (app, 0, sizeof (app));
      for (i = 0; i < ((n << 1) - 1); ++i)
	{
	  for (j = 0; j < n; ++j)
	    {
	      fscanf (stdin, "%d", &k);
	      ++app[k];
	    }
	}
      nu[0] = 0;
      for (i = 1; i <= 2500; ++i)
	{
	  if (app[i] & 1)
	    {
	      nu[++nu[0]] = i;
	    }
	}
      for (i = 1; i <= nu[0]; ++i)
	{
	  for (j = i + 1; j <= nu[0]; ++j)
	    {
	      if (nu[i] > nu[j])
		{
		  nu[i] ^= nu[j];
		  nu[j] ^= nu[i];
		  nu[i] ^= nu[j];
		}
	    }
	}
      for (i = 1; i <= nu[0]; ++i)
	{
	  fprintf (stdout, " %d", nu[i]);
	}
      fprintf (stdout, "\n");
    }
}
