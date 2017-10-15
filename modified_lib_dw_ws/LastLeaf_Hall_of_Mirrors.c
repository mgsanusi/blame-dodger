#include <stdio.h>
FILE *new_freopen (const char *filename, const char *mode, FILE * stream);
int
main ()
{
  int first_iteration;
  int testc;
  int testi;
  int a[201];
  int ac;
  int act;
  int i;
  int t;
  int h[201];
  double s;
  double v;
  double os;
  new_freopen ("1.out", "w", stdout);
  scanf ("%d", &testc);
  for (testi = 1; testi <= testc; testi++)
    {
      scanf ("%d", &ac);
      os = 0;
      for (i = 0; i < ac; i++)
	{
	  scanf ("%d", a + i);
	  h[i] = 1;
	  os += a[i];
	}
      for (;;)
	{
	  s = 0;
	  act = 0;
	  for (i = 0; i < ac; i++)
	    if (h[i])
	      s += a[i], act++;
	  s += os;
	  v = s / act;
	  t = 0;
	  for (i = 0; i < ac; i++)
	    if (h[i] && (a[i] >= v))
	      h[i] = 0, t = 1;
	  if (!t)
	    break;
	}
      printf ("Case #%d:", testi);
      if (ac > 1)
	for (i = 0; i < ac; i++)
	  if (h[i])
	    {
	      printf (" %.6lf", ((v - a[i]) * 100) / os);
	    }
	  else
	    {
	      printf (" %.6lf", 0.0);
	    }
      else
	printf (" %.6lf", 0.0);
      printf ("\n");
    }
  return 0;
}

FILE *
new_freopen (const char *filename, const char *mode, FILE * stream)
{
  int first_iteration;
  return freopen (filename, mode, stream);
}
