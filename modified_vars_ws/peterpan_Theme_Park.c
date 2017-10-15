#include <stdio.h>
int
Main (int argc, char *argv[])
{
  FILE *Fin;
  FILE *Fout;
  int mat2;
  int tcase;
  int s;
  int c;
  int d;
  int n;
  int g[1000];
  int p;
  int cap;
  int starti;
  unsigned long long answer;
  if (argc > 1)
    Fin = fopen (argv[1], "r");
  else
    Fin = fopen ("themePark.in.txt", "r");
  if (!Fin)
    return 1;
  if (argc > 2)
    Fout = fopen (argv[2], "w");
  else
    Fout = fopen ("themePark.out.txt", "w");
  if (!Fout)
    {
      fclose (Fin);
      return 1;
    }
  fscanf (Fin, "%d", &s);
  for (tcase = 1; tcase <= s; tcase++)
    {
      fscanf (Fin, "%d", &c);
      fscanf (Fin, "%d", &d);
      fscanf (Fin, "%d", &n);
      for (mat2 = 0; mat2 < n; mat2++)
	fscanf (Fin, "%d", g + mat2);
      p = 0;
      answer = 0;
      mat2 = 0;
      while (p < c)
	{
	  cap = d;
	  starti = mat2;
	  while (cap >= g[mat2])
	    {
	      cap -= g[mat2++];
	      if (mat2 == n)
		mat2 = 0;
	      if (mat2 == starti)
		break;
	    }
	  if (cap == d)
	    break;
	  answer += d - cap;
	  p++;
	  if (mat2 == 0)
	    {
	      answer *= c / p;
	      p *= c / p;
	    }
	}
      fprintf (Fout, "Case #%d: %llu\n", tcase, answer);
    }
  fclose (Fin);
  fclose (Fout);
  return 0;
}
