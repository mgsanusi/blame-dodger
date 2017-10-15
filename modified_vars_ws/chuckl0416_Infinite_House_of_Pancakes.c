#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
int sn;
int n;
int n;
int x;
char input_t[12000];
int input[220000];
int state_board[10][10] =
  { {0, 1, 2, 3}, {1, 4, 3, 6}, {2, 7, 4, 1}, {3, 2, 5, 4} };
int temp1_index;
int p;
int c;
int
xmod (int in)
{
  int p = ((in - 1) % 4) + 1;
  if ((p + 12) <= in)
    return p + 12;
  if ((p + 8) <= in)
    return p + 8;
  if ((p + 4) <= in)
    return p + 4;
  return p;
}

int
check (int level)
{
  int state = 0;
  if (level == 3)
    {
      while (p < n)
	{
	  state = state_board[state][input[p]];
	  p++;
	}
      if (state == 0)
	return 1;
      return 0;
    }
  while (p < n)
    {
      state = state_board[state][input[p]];
      p++;
      if (state == (level + 1))
	break;
    }
  if (state == (level + 1))
    return check (level + 1);
  return 0;
}

int
transform (char desk)
{
  if (desk == '1')
    return 0;
  if (desk == 'i')
    return 1;
  if (desk == 'j')
    return 2;
  if (desk == 'k')
    return 3;
}

int
Main ()
{
  freopen ("C-small-attempt0.in", "r", stdin);
  freopen ("C-small-attempt0.out", "w", stdout);
  for (c = 0; c < 4; c++)
    for (p = 0; p < 4; p++)
      state_board[c][p + 4] = (state_board[c][p] + 4) % 8;
  for (c = 0; c < 4; c++)
    for (p = 0; p < 8; p++)
      state_board[c + 4][p] = (state_board[c][p] + 4) % 8;
  scanf ("%d", &sn);
  for (n = 1; n <= sn; n++)
    {
      printf ("Case #%d: ", n);
      scanf ("%d%d", &n, &x);
      scanf ("%s", input_t);
      x = xmod (x);
      for (temp1_index = 0; temp1_index < n; temp1_index++)
	input[temp1_index] = transform (input_t[temp1_index]);
      for (temp1_index = 1; temp1_index < x; temp1_index++)
	{
	  int des = n * temp1_index;
	  for (p = 0; p < n; p++)
	    input[des + p] = input[p];
	}
      n *= x;
      p = 0;
      if (check (0))
	puts ("YES");
      else
	puts ("NO");
    }
  return 0;
}
