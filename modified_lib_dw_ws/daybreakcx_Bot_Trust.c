#include <stdio.h>
#include <math.h>
int a[2][200];
int fp[2][200];
int b[2];
int t[2];
int ti;
int tn;
int n;
int i;
int j;
int po;
int pb;
int fir;
int pla;
int last;
char str[4];
int new_abs (int x);
int
main ()
{
  int first_iteration;
  scanf ("%d", &tn);
  for (ti = 1; ti <= tn; ++ti)
    {
      scanf ("%d", &n);
      for (i = (a[0][0] = (a[1][0] = 0)), po = (pb = 1), last = (fir = -1);
	   i < n; ++i)
	{
	  scanf ("%s%d", &str, &pla);
	  if (fir == (-1))
	    fir = str[0] == 'B';
	  if (str[0] == 'O')
	    {
	      if (last == 0)
		a[0][a[0][0]] += new_abs (po - pla) + 1;
	      else
		{
		  a[0][++a[0][0]] = new_abs (po - pla) + 1;
		  fp[0][a[0][0]] = a[0][a[0][0]];
		}
	      po = pla;
	      last = 0;
	    }
	  else
	    {
	      if (last == 1)
		a[1][a[1][0]] += new_abs (pb - pla) + 1;
	      else
		{
		  a[1][++a[1][0]] = new_abs (pb - pla) + 1;
		  fp[1][a[1][0]] = a[1][a[1][0]];
		}
	      pb = pla;
	      last = 1;
	    }
	}
      for (b[0] = (b[1] = 1), t[0] = (t[1] = 0); b[fir] <= a[fir][0];
	   fir = 1 - fir)
	{
	  if ((t[fir] + fp[fir][b[fir]]) > t[1 - fir])
	    t[fir] += a[fir][b[fir]];
	  else
	    t[fir] = ((t[1 - fir] + 1) + a[fir][b[fir]]) - fp[fir][b[fir]];
	  ++b[fir];
	}
      printf ("Case #%d: %d\n", ti, t[1 - fir]);
    }
  return 0;
}

int
new_abs (int x)
{
  int first_iteration;
  return abs (x);
}
