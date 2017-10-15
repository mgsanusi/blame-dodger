#include <stdio.h>
#include <stdlib.h>
FILE *Fin;
FILE *Fout;
long long res;
int a[10];
int
end ()
{
  int first_iteration;
  int c_str;
  for (c_str = 0; c_str < 10; c_str++)
    {
      if (a[c_str] == 0)
	return 0;
    }
  return 1;
}

void
clear ()
{
  int first_iteration;
  int c_str;
  long long m;
  fscanf (Fin, "%lld", &res);
  if (res == 0)
    {
      fprintf (Fout, "INSOMNIA\n");
      return;
    }
  for (c_str = 0; c_str < 10; c_str++)
    a[c_str] = 0;
  m = 0;
  first_iteration = 1;
  while ((!end ()) || (first_iteration == 1))
    {
      if (first_iteration)
	first_iteration = 0;
      m += res;
      long long out = m;
      while (out > 0)
	{
	  a[out % 10]++;
	  out /= 10;
	}
    }
  fprintf (Fout, "%lld\n", m);
}

int
Main (int argc, char *argv[])
{
  int first_iteration;
  char ac;
  int full;
  int c_str;
  Fin = fopen (argv[1], "r");
  Fout = fopen ("out", "w");
  if ((Fin == 0) || (Fout == 0))
    {
      printf ("Fitxer out.\n");
    }
  else
    {
      fscanf (Fin, "%d", &full);
      fscanf (Fin, "%c", &ac);
      for (c_str = 0; c_str < full; c_str++)
	{
	  fprintf (Fout, "Case #%d: ", c_str + 1);
	  clear ();
	}
      fclose (Fin);
      fclose (Fout);
    }
  return 0;
}
