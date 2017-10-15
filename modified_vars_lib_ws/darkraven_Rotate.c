#include<stdio.h>
#include<string.h>
#include <stddef.h>
#include <stddef.h>
int g[60][60];
int f[60][60][4];
int tmpg[60][60];
void *new_memset (void *ptr, int value, size_t num);
void *new_memcpy (void *destination, const void *source, size_t num);
void
rotate (int a, int t)
{
  new_memcpy (tmpg, g, sizeof (g));
  int depth;
  int vx;
  for (depth = a - 1; depth >= 0; depth--)
    for (vx = 0; vx < t; vx++)
      g[vx][(a - depth) - 1] = tmpg[depth][vx];
}

void
gravity (int a, int t)
{
  int depth;
  new_memcpy (tmpg, g, sizeof (g));
  new_memset (g, 0, sizeof (g));
  for (depth = 0; depth < t; depth++)
    {
      int p2 = a - 1;
      int vx;
      for (vx = a - 1; vx >= 0; vx--)
	if (tmpg[vx][depth])
	  {
	    g[p2][depth] = tmpg[vx][depth];
	    p2--;
	  }
    }
}

int
check (int a, int t, int color, int p2)
{
  new_memset (f, 0, sizeof (f));
  int depth;
  int vx;
  for (depth = 0; depth < a; depth++)
    for (vx = 0; vx < t; vx++)
      {
	if (g[depth][vx] != color)
	  {
	    f[depth][vx][0] = (f[depth][vx][1] =
			       (f[depth][vx][2] = (f[depth][vx][3] = 0)));
	    continue;
	  }
	if (depth > 0)
	  f[depth][vx][0] = f[depth - 1][vx][0] + 1;
	else
	  f[depth][vx][0] = 1;
	if (vx > 0)
	  f[depth][vx][1] = f[depth][vx - 1][1] + 1;
	else
	  f[depth][vx][1] = 1;
	if ((depth > 0) && (vx > 0))
	  f[depth][vx][2] = f[depth - 1][vx - 1][2] + 1;
	else
	  f[depth][vx][2] = 1;
	if (depth > 0)
	  f[depth][vx][3] = f[depth - 1][vx + 1][3] + 1;
	else
	  f[depth][vx][3] = 1;
      }
  for (depth = 0; depth < a; depth++)
    for (vx = 0; vx < t; vx++)
      if ((((f[depth][vx][0] >= p2) || (f[depth][vx][1] >= p2))
	   || (f[depth][vx][2] >= p2)) || (f[depth][vx][3] >= p2))
	return 1;
  return 0;
}

int
Main ()
{
  int second;
  scanf ("%d", &second);
  int e;
  for (e = 1; e <= second; e++)
    {
      new_memset (g, 0, sizeof (g));
      int c;
      int m;
      scanf ("%d%d", &c, &m);
      int depth;
      int vx;
      for (depth = 0; depth < c; depth++)
	for (vx = 0; vx < c; vx++)
	  {
	    char tt;
	    for (scanf ("%c", &tt);
		 ((tt != '.') && (tt != 'R')) && (tt != 'B');
		 scanf ("%c", &tt))
	      ;
	    switch (tt)
	      {
	      case '.':
		g[depth][vx] = 0;
		break;
	      case 'R':
		g[depth][vx] = 1;
		break;
	      case 'B':
		g[depth][vx] = 2;
		break;
	      }
	  }
      rotate (c, c);
      gravity (c, c);
      if (check (c, c, 1, m))
	if (check (c, c, 2, m))
	  printf ("Case #%d: Both\n", e);
	else
	  printf ("Case #%d: Red\n", e);
      else if (check (c, c, 2, m))
	printf ("Case #%d: Blue\n", e);
      else
	printf ("Case #%d: Neither\n", e);
    }
  return 0;
}

void *new_memset (void *ptr, int value, size_t num);
void *
new_memcpy (void *destination, const void *source, size_t num)
{
  return memcpy (destination, source, num);
}

void *
new_memset (void *ptr, int value, size_t num)
{
  return memset (ptr, value, num);
}
