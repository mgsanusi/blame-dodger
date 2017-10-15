#include <stdio.h>
#include <math.h>
int l[2][200];
int fp[2][200];
int f[2];
int w[2];
int c;
int tem;
int sum;
int atx;
int table;
int explode;
int pb;
int fir;
int pla;
int last;
char str[4];
int
Main ()
{
  scanf ("%d", &tem);
  for (c = 1; c <= tem; ++c)
    {
      scanf ("%d", &sum);
      for (atx = (l[0][0] = (l[1][0] = 0)), explode = (pb = 1), last =
	   (fir = -1); atx < sum; ++atx)
	{
	  scanf ("%s%d", &str, &pla);
	  if (fir == (-1))
	    fir = str[0] == 'B';
	  if (str[0] == 'O')
	    {
	      if (last == 0)
		l[0][l[0][0]] += abs (explode - pla) + 1;
	      else
		{
		  l[0][++l[0][0]] = abs (explode - pla) + 1;
		  fp[0][l[0][0]] = l[0][l[0][0]];
		}
	      explode = pla;
	      last = 0;
	    }
	  else
	    {
	      if (last == 1)
		l[1][l[1][0]] += abs (pb - pla) + 1;
	      else
		{
		  l[1][++l[1][0]] = abs (pb - pla) + 1;
		  fp[1][l[1][0]] = l[1][l[1][0]];
		}
	      pb = pla;
	      last = 1;
	    }
	}
      for (f[0] = (f[1] = 1), w[0] = (w[1] = 0); f[fir] <= l[fir][0];
	   fir = 1 - fir)
	{
	  if ((w[fir] + fp[fir][f[fir]]) > w[1 - fir])
	    w[fir] += l[fir][f[fir]];
	  else
	    w[fir] = ((w[1 - fir] + 1) + l[fir][f[fir]]) - fp[fir][f[fir]];
	  ++f[fir];
	}
      printf ("Case #%d: %d\n", c, w[1 - fir]);
    }
  return 0;
}
