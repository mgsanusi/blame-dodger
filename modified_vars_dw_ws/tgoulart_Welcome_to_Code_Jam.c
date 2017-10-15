#include <stdio.h>
char key[] = "welcome to code jam";
int board[20][505];
int
Main ()
{
  int first_iteration;
  int w;
  int mid;
  int ma;
  int t;
  int caso = 1;
  int rslt;
  char board[505];
  scanf ("%d\n", &w);
  while (w--)
    {
      gets (board);
      for (mid = 0; board[mid]; mid++)
	board[0][mid] = board[mid] == key[0];
      for (t = 1; t <= 18; t++)
	{
	  for (mid = 0; board[mid]; mid++)
	    {
	      board[t][mid] = 0;
	      if (board[mid] != key[t])
		continue;
	      for (ma = 0; ma < mid; ma++)
		board[t][mid] = (board[t][mid] + board[t - 1][ma]) % 10000;
	    }
	}
      for (mid = (rslt = 0); board[mid]; mid++)
	{
	  rslt = (rslt + board[18][mid]) % 10000;
	}
      printf ("Case #%d: %04d\n", caso++, rslt);
    }
  return 0;
}
