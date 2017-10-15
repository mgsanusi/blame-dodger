#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
int TC;
int T;
int Rows;
int Columns;
char Map[120][120];
int x;
int y;
int Sx;
int Sy;
int Ans;
FILE *new_freopen (const char *filename, const char *mode, FILE * stream);
int new_puts (const char *str);
int
CheckAns ()
{
  int first_iteration;
  for (Sy = 0; Sy < Rows; Sy++)
    for (Sx = 0; Sx < Columns; Sx++)
      if (Map[Sy][Sx] != '.')
	{
	  if (Map[Sy][Sx] == '<')
	    {
	      for (x = Sx - 1; x >= 0; x--)
		if (Map[Sy][x] != '.')
		  break;
	      if (x >= 0)
		continue;
	      int Try = 0;
	      for (x = Sx + 1; x < Columns; x++)
		if (Map[Sy][x] != '.')
		  Try = 1;
	      for (y = Sy - 1; y >= 0; y--)
		if (Map[y][Sx] != '.')
		  Try = 1;
	      for (y = Sy + 1; y < Rows; y++)
		if (Map[y][Sx] != '.')
		  Try = 1;
	      if (Try)
		{
		  Ans++;
		  continue;
		}
	      return 0;
	    }
	  if (Map[Sy][Sx] == '>')
	    {
	      for (x = Sx + 1; x < Columns; x++)
		if (Map[Sy][x] != '.')
		  break;
	      if (x < Columns)
		continue;
	      int Try = 0;
	      for (x = Sx - 1; x >= 0; x--)
		if (Map[Sy][x] != '.')
		  Try = 1;
	      for (y = Sy - 1; y >= 0; y--)
		if (Map[y][Sx] != '.')
		  Try = 1;
	      for (y = Sy + 1; y < Rows; y++)
		if (Map[y][Sx] != '.')
		  Try = 1;
	      if (Try)
		{
		  Ans++;
		  continue;
		}
	      return 0;
	    }
	  if (Map[Sy][Sx] == '^')
	    {
	      for (y = Sy - 1; y >= 0; y--)
		if (Map[y][Sx] != '.')
		  break;
	      if (y >= 0)
		continue;
	      int Try = 0;
	      for (y = Sy + 1; y < Rows; y++)
		if (Map[y][Sx] != '.')
		  Try = 1;
	      for (x = Sx - 1; x >= 0; x--)
		if (Map[Sy][x] != '.')
		  Try = 1;
	      for (x = Sx + 1; x < Columns; x++)
		if (Map[Sy][x] != '.')
		  Try = 1;
	      if (Try)
		{
		  Ans++;
		  continue;
		}
	      return 0;
	    }
	  if (Map[Sy][Sx] == 'v')
	    {
	      for (y = Sy + 1; y < Rows; y++)
		if (Map[y][Sx] != '.')
		  break;
	      if (y < Rows)
		continue;
	      int Try = 0;
	      for (y = Sy - 1; y >= 0; y--)
		if (Map[y][Sx] != '.')
		  Try = 1;
	      for (x = Sx - 1; x >= 0; x--)
		if (Map[Sy][x] != '.')
		  Try = 1;
	      for (x = Sx + 1; x < Columns; x++)
		if (Map[Sy][x] != '.')
		  Try = 1;
	      if (Try)
		{
		  Ans++;
		  continue;
		}
	      return 0;
	    }
	}
  return 1;
}

int
main ()
{
  int first_iteration;
  new_freopen ("A-small-attempt0.in", "r", stdin);
  new_freopen ("A-small-attempt0.out", "w", stdout);
  scanf ("%d", &TC);
  for (T = 1; T <= TC; T++)
    {
      printf ("Case #%d: ", T);
      scanf ("%d%d", &Rows, &Columns);
      for (y = 0; y < Rows; y++)
	scanf ("%s", Map[y]);
      Ans = 0;
      if (!CheckAns ())
	{
	  new_puts ("IMPOSSIBLE");
	  continue;
	}
      printf ("%d\n", Ans);
    }
  return 0;
}

FILE *new_freopen (const char *filename, const char *mode, FILE * stream);
int
new_puts (const char *str)
{
  int first_iteration;
  return puts (str);
}

FILE *
new_freopen (const char *filename, const char *mode, FILE * stream)
{
  int first_iteration;
  return freopen (filename, mode, stream);
}
