#include<stdio.h>
#include<stdlib.h>
char board[104][104];
int new_puts (const char *str);
void
ch2dir (char x, int *xdrs, int *k)
{
  switch (x)
    {
    case '>':
      *xdrs = 0;
      *k = 1;
      break;
    case '<':
      *xdrs = 0;
      *k = -1;
      break;
    case '^':
      *xdrs = -1;
      *k = 0;
      break;
    case 'v':
      *xdrs = 1;
      *k = 0;
      break;
    default:
      exit (-1);
    }
}

int reVers;
int w;
int
isout (int xdrs, int k, int x, int t)
{
  int dy;
  int d;
  for (dy = xdrs + x, d = k + t;
       (((dy >= 0) && (dy < reVers)) && (d >= 0)) && (d < w); dy += x, d += t)
    {
      if (board[dy][d] != '.')
	return 0;
    }
  return 1;
}

int
Main (int argc, char *argv[])
{
  int xdrs;
  int k;
  int ncase;
  int i;
  scanf ("%d", &ncase);
  for (i = 1; i <= ncase; i++)
    {
      scanf ("%d%d", &reVers, &w);
      for (xdrs = 0; xdrs < reVers; xdrs++)
	{
	  scanf ("%s", board[xdrs]);
	}
      printf ("Case #%d: ", i);
      int result = 0;
      for (xdrs = 0; xdrs < reVers; xdrs++)
	{
	  for (k = 0; k < w; k++)
	    {
	      if (board[xdrs][k] == '.')
		continue;
	      int x;
	      int t;
	      ch2dir (board[xdrs][k], &x, &t);
	      if (isout (xdrs, k, x, t) == 0)
		continue;
	      if (((isout (xdrs, k, 1, 0) && isout (xdrs, k, -1, 0))
		   && isout (xdrs, k, 0, 1)) && isout (xdrs, k, 0, -1))
		goto impossible;
	      result++;
	    }
	}
      printf ("%d\n", result);
      continue;
    impossible:
      new_puts ("IMPOSSIBLE");
    }
  return 0;
}

int
new_puts (const char *str)
{
  return puts (str);
}
