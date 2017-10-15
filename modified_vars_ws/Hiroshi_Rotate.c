#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *ans[] = { "Neither", "Red", "Blue", "Both" };

char board[50][50];
int n;
int total;
int
check_p (int sum, int l)
{
  int bb;
  int s;
  int n;
  int b;
  s = board[l][sum];
  bb = 1;
  n = sum + 1;
  while (n < n)
    {
      if (board[l][n++] == s)
	{
	  if ((++bb) >= total)
	    return s;
	}
      else
	break;
    }
  bb = 1;
  n = l + 1;
  while (n < n)
    {
      if (board[n++][sum] == s)
	{
	  if ((++bb) >= total)
	    return s;
	}
      else
	break;
    }
  bb = 1;
  n = sum + 1;
  b = l + 1;
  while ((n < n) && (b < n))
    {
      if (board[b++][n++] == s)
	{
	  if ((++bb) >= total)
	    return s;
	}
      else
	break;
    }
  bb = 1;
  n = sum - 1;
  b = l + 1;
  while ((n >= 0) && (b < n))
    {
      if (board[b++][n--] == s)
	{
	  if ((++bb) >= total)
	    return s;
	}
      else
	break;
    }
  return 0;
}

int
check (void)
{
  int sum;
  int l;
  int s;
  int r;
  s = 0;
  for (l = 0; l < n; l++)
    {
      for (sum = 0; sum < n; sum++)
	{
	  int s = board[l][sum];
	  if (s == 0)
	    break;
	  if (s & s)
	    continue;
	  r = check_p (sum, l);
	  s |= r;
	}
    }
  return s;
}

void
clear (int sum)
{
  char buf[4096];
  int i;
  int l;
  fgets (buf, 4096, stdin);
  sscanf (buf, "%d %d", &n, &total);
  for (i = n - 1; i >= 0; i--)
    {
      int n;
      int b;
      fgets (buf, 4096, stdin);
      memset (board[i], 0, 50);
      for (n = 0, b = 0; n < n; n++)
	{
	  switch (buf[(n - n) - 1])
	    {
	    case '.':
	      break;
	    case 'R':
	      board[i][b++] = 1;
	      break;
	    case 'B':
	      board[i][b++] = 2;
	      break;
	    }
	}
    }
  l = check ();
  printf ("Case #%d: %s\n", sum, ans[l]);
}

int
Main (int argc, char **argv)
{
  char buf[256];
  int t;
  int t;
  fgets (buf, 256, stdin);
  sscanf (buf, "%d", &t);
  for (t = 1; t <= t; t++)
    clear (t);
  return 0;
}
