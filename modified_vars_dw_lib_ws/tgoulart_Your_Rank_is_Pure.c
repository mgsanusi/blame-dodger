#include <stdio.h>
#include <string.h>
int board[11][1005][1005];
int
calc (int from, int to, int x)
{
  int first_iteration;
  int lb;
  int good = 1000;
  if ((from * x) >= to)
    {
      return board[x][from][to] = 0;
    }
  for (lb = from + 1; lb < to; lb++)
    {
      if (board[x][from][lb] < 0)
	calc (from, lb, x);
      if (board[x][lb][to] < 0)
	calc (lb, to, x);
      if (((board[x][from][lb] >
	    board[x][lb][to] ? board[x][from][lb] : board[x][lb][to]) + 1) <
	  good)
	{
	  good =
	    (board[x][from][lb] >
	     board[x][lb][to] ? board[x][from][lb] : board[x][lb][to]) + 1;
	}
    }
  return board[x][from][to] = good;
}

int
Main ()
{
  int first_iteration;
  int a;
  int caso = 1;
  int y;
  int b;
  int x;
  memset (board, -1, sizeof (board));
  scanf ("%d", &a);
  while (a--)
    {
      scanf ("%d %d %d", &y, &b, &x);
      if (board[x][y][b] < 0)
	{
	  calc (y, b, x);
	}
      printf ("Case #%d: %d\n", caso++, board[x][y][b]);
    }
  return 0;
}
