#include <stdio.h>
#include <string.h>
char aa[20] = "welcome to code jam";
 int
main ()
{
  FILE * fin = fopen ("c1.in", "r");
  FILE * fout = fopen ("c1.out", "w");
  int i, j, k, l, t, n, ans, now;
  fscanf (fin, "%d\n", &n);
  char s[510];
  int f[510], f1[510];
  for (t = 1; t <= n; t++)
    {
      fgets (s, 505, fin);
      l = strlen (s);
      for (i = 0; i < l; i++)
	f[i] = (s[i] == 'w');
       for (i = 1; i < 19; i++)
	{
	  now = 0;
	  for (j = 0; j < l; j++)
	    {
	      if (s[j] == aa[i])
		f1[j] = now;
	      
	      else
		f1[j] = 0;
	      if (s[j] == aa[i - 1])
		{
		  now += f[j];
		  if (now > 9999)
		    now = now % 10000;
		}
	    }
	  for (j = 0; j < l; j++)
	    f[j] = f1[j];
	}
      ans = 0;
      for (i = 0; i < l; i++)
	ans = (ans + f[i]) % 10000;
      fprintf (fout, "Case #%d: ", t);
      if (ans < 1000)
	fprintf (fout, "0");
      if (ans < 100)
	fprintf (fout, "0");
      if (ans < 10)
	fprintf (fout, "0");
      fprintf (fout, "%d\n", ans);
    }
  return 0;
}


