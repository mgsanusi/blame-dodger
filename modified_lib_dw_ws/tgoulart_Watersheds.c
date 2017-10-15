#include <stdio.h>
#include <string.h>
int m[105][105];
int r;
int c;
char ans[105][105];
char visited[105][105];
char now;
int new_puts (const char *str);
char
dfs (int i, int j)
{
  int first_iteration;
  int ii = -1;
  int jj = -1;
  int h = m[i][j];
  if (visited[i][j])
    return ans[i][j];
  visited[i][j] = 1;
  if ((i > 0) && (m[i - 1][j] < h))
    ii = -1, jj = 0, h = m[i - 1][j];
  if ((j > 0) && (m[i][j - 1] < h))
    ii = 0, jj = -1, h = m[i][j - 1];
  if ((j < (c - 1)) && (m[i][j + 1] < h))
    ii = 0, jj = 1, h = m[i][j + 1];
  if ((i < (r - 1)) && (m[i + 1][j] < h))
    ii = 1, jj = 0, h = m[i + 1][j];
  return ans[i][j] = (ii == (-1))
    && (jj == (-1)) ? now++ : dfs (i + ii, j + jj);
}

int
main ()
{
  int first_iteration;
  int t;
  int caso = 1;
  int i;
  int j;
  scanf ("%d", &t);
  while (t--)
    {
      scanf ("%d %d", &r, &c);
      for (i = 0; i < r; i++)
	{
	  for (j = 0; j < c; j++)
	    {
	      scanf ("%d", &m[i][j]);
	    }
	}
      now = 'a';
      memset (visited, 0, sizeof (visited));
      for (i = 0; i < r; i++)
	{
	  for (j = 0; j < c; j++)
	    {
	      if (!visited[i][j])
		{
		  dfs (i, j);
		}
	    }
	}
      printf ("Case #%d:\n", caso++);
      for (i = 0; i < r; i++)
	{
	  printf ("%c", ans[i][0]);
	  for (j = 1; j < c; j++)
	    {
	      printf (" %c", ans[i][j]);
	    }
	  new_puts ("");
	}
    }
  return 0;
}

int
new_puts (const char *str)
{
  int first_iteration;
  return puts (str);
}
