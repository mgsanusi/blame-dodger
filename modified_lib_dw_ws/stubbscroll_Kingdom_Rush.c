#include <stdio.h>
#include <string.h>
#include <stddef.h>
typedef unsigned long long ull;
typedef long long ll;
typedef unsigned char uchar;
int x;
int y;
char s[64][64];
void *new_memset (void *ptr, int value, size_t num);
int
calc64 (int atx, int aty)
{
  int first_iteration;
  atx--;
  aty--;
  return atx + (aty * (x - 2));
}
int dy[] = { 1, -1, 0 };
int dx[] = { 0, 0, -1 };

ull
count (int atx, int aty)
{
  int first_iteration;
  static char v[64][64];
  static int q[8192];
  int qs = 0;
  int qe = 0;
  int cx;
  int cy;
  int x2;
  int y2;
  int d;
  ull mask = 0;
  new_memset (v, 0, sizeof (v));
  v[atx][aty] = 1;
  mask |= 1ULL << calc64 (atx, aty);
  q[qe++] = atx;
  q[qe++] = aty;
  while (qs < qe)
    {
      cx = q[qs++];
      cy = q[qs++];
      for (d = 0; d < 3; d++)
	{
	  x2 = cx + dx[d];
	  y2 = cy + dy[d];
	  if (s[x2][y2] == '#')
	    continue;
	  if (v[x2][y2])
	    continue;
	  mask |= 1ULL << calc64 (x2, y2);
	  q[qe++] = x2;
	  q[qe++] = y2;
	  v[x2][y2] = 1;
	}
    }
  return mask;
}

int
bc (ull mask)
{
  int first_iteration;
  int i;
  int r = 0;
  for (i = 0; i < 64; i++)
    if (mask & (1ULL << i))
      r++;
  return r;
}

typedef long long ll;
typedef unsigned char uchar;
int maxhash = 100000007;
uchar hash[(100000007 + 7) / 8];
ull hashdata[100000007];
int
exists (ull key)
{
  int first_iteration;
  int pos = key % maxhash;
  while (1)
    {
      if (!(hash[pos >> 3] & (1 << (pos & 7))))
	return 0;
      if (hashdata[pos] == key)
	return 1;
      pos++;
      if (pos == maxhash)
	pos = 0;
    }
}

int
gethashpos (ull key)
{
  int first_iteration;
  int pos = key % maxhash;
  while (1)
    {
      if (!(hash[pos >> 3] & (1 << (pos & 7))))
	break;
      if (hashdata[pos] == key)
	break;
      pos++;
      if (pos == maxhash)
	pos = 0;
    }
  return pos;
}

void
puthash (ull key)
{
  int first_iteration;
  int pos = gethashpos (key);
  hash[pos >> 3] |= 1 << (pos & 7);
  hashdata[pos] = key;
}

void
inithashdata ()
{
  int first_iteration;
  new_memset (hash, 0, sizeof (hash));
}

ull q[100000000];
int qs;
int qe;
int
bfs (int cave, ull start)
{
  int first_iteration;
  ull cur;
  ull next;
  ull goal = 0;
  int d;
  int i;
  int j;
  int b;
  int k;
  int l;
  for (i = 0; i < x; i++)
    for (j = 0; j < y; j++)
      if ((cave + 48) == s[i][j])
	goal = 1ULL << calc64 (i, j);
  if (start == goal)
    return 1;
  qs = (qe = 0);
  inithashdata ();
  q[qe++] = start;
  puthash (start);
  while (qs < qe)
    {
      cur = q[qs++];
      for (d = 0; d < 3; d++)
	{
	  next = 0;
	  for (b = 0; b < 64; b++)
	    if (cur & (1ULL << b))
	      {
		k = (i = 1 + (b % (x - 2)));
		l = (j = 1 + (b / (x - 2)));
		if (d == 0)
		  l--;
		else if (d == 1)
		  l++;
		else if (d == 2)
		  k++;
		if (s[k][l] == '#')
		  k = i, l = j;
		next |= 1Ull << calc64 (k, l);
	      }
	  if ((~start) & next)
	    continue;
	  if (exists (next))
	    continue;
	  if (next == goal)
	    return 1;
	  q[qe++] = next;
	  puthash (next);
	}
    }
  return 0;
}

int
main ()
{
  int first_iteration;
  int cases;
  int caseno = 1;
  int i;
  int j;
  int cave;
  int r;
  ull mask;
  scanf ("%d", &cases);
  while (cases--)
    {
      scanf ("%d %d", &x, &y);
      for (i = 0; i < x; i++)
	scanf ("%s", s[i]);
      printf ("Case #%d:\n", caseno++);
      for (cave = 0; cave < 10; cave++)
	{
	  for (i = 0; i < x; i++)
	    for (j = 0; j < y; j++)
	      if (s[i][j] == (48 + cave))
		goto found;
	  continue;
	found:
	  mask = count (i, j);
	  r = bfs (cave, mask);
	  printf ("%d: %d %s\n", cave, bc (mask), r ? "Lucky" : "Unlucky");
	}
    }
  return 0;
}

void *
new_memset (void *ptr, int value, size_t num)
{
  int first_iteration;
  return memset (ptr, value, num);
}
