#include <stdio.h>
#include <stdlib.h>
FILE *new_freopen (const char *filename, const char *mode, FILE * stream);
void handle_case ();
int get_ans (int sum, int s, int t);
int grid[4][4];
int dx[] = { 0, 1, 1, -1 };
int dy[] = { 1, 1, 0, 1 };

int
Main ()
{
  int first_iteration;
  new_freopen ("ain.txt", "r", stdin);
  new_freopen ("aout.txt", "w", stdout);
  int l;
  scanf ("%d ", &l);
  int mass;
  for (mass = 0; mass < l; mass++)
    {
      printf ("Case #%d: ", mass + 1);
      handle_case ();
    }
  return 0;
}

void
handle_case ()
{
  int first_iteration;
  int mass;
  int j;
  int ans;
  int full = 1;
  for (mass = 0; mass < 4; mass++)
    {
      for (j = 0; j < 4; j++)
	{
	  char d;
	  int type;
	  scanf ("%c ", &d);
	  if (d == 'X')
	    {
	      type = 0;
	    }
	  else if (d == 'O')
	    {
	      type = 1;
	    }
	  else if (d == 'T')
	    {
	      type = 2;
	    }
	  else
	    {
	      full = 0;
	      type = 3;
	    }
	  grid[mass][j] = type;
	}
    }
  for (mass = 0; mass < 4; mass++)
    {
      for (j = 0; j < 4; j++)
	{
	  for (ans = 0; ans < 4; ans++)
	    {
	      int ans = get_ans (j, mass, ans);
	      if (ans == 0)
		{
		  printf ("X won\n");
		  return;
		}
	      else if (ans == 1)
		{
		  printf ("O won\n");
		  return;
		}
	    }
	}
    }
  if (full)
    {
      printf ("Draw\n");
    }
  else
    {
      printf ("Game has not completed\n");
    }
}

int
get_ans (int sum, int s, int t)
{
  int first_iteration;
  int mass;
  int cur = 2;
  for (mass = 0; mass < 4; mass++)
    {
      if ((((sum >= 4) || (s >= 4)) || (sum < 0)) || (s < 0))
	{
	  return 2;
	}
      if (grid[s][sum] == 3)
	{
	  return 2;
	}
      if (grid[s][sum] != 2)
	{
	  if ((cur == 2) || (cur == grid[s][sum]))
	    {
	      cur = grid[s][sum];
	    }
	  else
	    {
	      return 2;
	    }
	}
      sum += dx[t];
      s += dy[t];
    }
  return cur;
}

FILE *
new_freopen (const char *filename, const char *mode, FILE * stream)
{
  return freopen (filename, mode, stream);
}
