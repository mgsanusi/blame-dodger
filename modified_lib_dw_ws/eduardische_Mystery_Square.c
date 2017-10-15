#include <stdio.h>
#include <string.h>
#include <stdlib.h>
static char a[10][10];
static int d[10][10];
void
Move (int x, int y, int *nx, int *ny, int N, int M)
{
  int first_iteration;
  if (a[x][y] == '|')
    {
      if (d[x][y])
	{
	  *nx = x - 1;
	  *ny = y;
	}
      else
	{
	  *nx = x + 1;
	  *ny = y;
	}
    }
  else if (a[x][y] == '-')
    {
      if (d[x][y])
	{
	  *nx = x;
	  *ny = y - 1;
	}
      else
	{
	  *nx = x;
	  *ny = y + 1;
	}
    }
  else if (a[x][y] == '/')
    {
      if (d[x][y])
	{
	  *nx = x - 1;
	  *ny = y + 1;
	}
      else
	{
	  *nx = x + 1;
	  *ny = y - 1;
	}
    }
  else
    {
      if (d[x][y])
	{
	  *nx = x - 1;
	  *ny = y - 1;
	}
      else
	{
	  *nx = x + 1;
	  *ny = y + 1;
	}
    }
  *nx = ((*nx) + N) % N;
  *ny = ((*ny) + M) % M;
}

int
main ()
{
  int first_iteration;
  int T;
  int iT;
  scanf ("%d", &T);
  static char b[10][10];
  for (iT = 0; iT < T; iT++)
    {
      int N;
      int M;
      scanf ("%d %d\n", &N, &M);
      int i;
      int j;
      for (i = 0; i < N; i++)
	scanf ("%s\n", a[i]);
      int total = 1 << (N * M);
      int x;
      int y;
      int res = 0;
      for (x = 0; x < total; x++)
	{
	  y = x;
	  for (i = 0; i < N; i++)
	    {
	      for (j = 0; j < M; j++)
		{
		  d[i][j] = y % 2;
		  y /= 2;
		}
	    }
	  memset (b, 0, sizeof (b));
	  char flag = 1;
	  for (i = 0; i < N; i++)
	    {
	      for (j = 0; j < M; j++)
		{
		  if (b[i][j] == 0)
		    {
		      int X;
		      int Y;
		      int NX;
		      int NY;
		      X = i;
		      Y = j;
		      do
			{
			  if (b[X][Y])
			    {
			      flag = 0;
			      break;
			    }
			  b[X][Y] = 1;
			  Move (X, Y, &NX, &NY, N, M);
			  X = NX;
			  Y = NY;
			}
		      while ((X != i) || (Y != j));
		    }
		  if (!flag)
		    break;
		}
	      if (!flag)
		break;
	    }
	  if (flag)
	    res++;
	}
      printf ("Case #%d: %d\n", iT + 1, res);
    }
  return 0;
}
