#include <stdio.h>
#include <string.h>
int zip[11];
char y1[11][11];
int x;
int path[11];
int good[11];
int cur[11];
void
btr (int num, int roboLocation, int mask, int stack[8])
{
  int i;
  int op = stack[roboLocation - 1];
  int stakk[8];
  for (i = 0; i < x; i++)
    stakk[i] = stack[i];
  for (i = 0; i < num; i++)
    {
      if (cur[i] > good[i])
	return;
      if (cur[i] < good[i])
	break;
    }
  if (num == x)
    {
      for (i = 0; i < x; i++)
	good[i] = cur[i];
      return;
    }
  for (i = 0; i < x; i++)
    if ((!(mask & (1 << i))) && y1[op][i])
      {
	cur[num] = zip[i];
	path[num] = i;
	stakk[roboLocation] = i;
	btr (num + 1, roboLocation + 1, mask + (1 << i), stakk);
      }
  if (roboLocation > 1)
    btr (num, roboLocation - 1, mask, stakk);
}

void
solve ()
{
  int i;
  int buf;
  int a;
  int in;
  int z;
  int stack[8];
  scanf ("%d %d", &x, &buf);
  for (i = 0; i < x; i++)
    scanf ("%d", &zip[i]);
  memset (y1, 0, sizeof (y1));
  for (i = 0; i < buf; i++)
    {
      scanf ("%d %d", &a, &in);
      y1[--a][--in] = 1;
      y1[in][a] = 1;
    }
  good[0] = 999999;
  for (z = (i = 0); i < x; i++)
    if (zip[z] > zip[i])
      z = i;
  path[0] = z;
  stack[0] = z;
  cur[0] = zip[z];
  btr (1, 1, 1 << z, stack);
  for (i = 0; i < x; i++)
    printf ("%d", good[i]);
  printf ("\n");
}

int
Main ()
{
  int x;
  int no = 1;
  scanf ("%d", &x);
  while (x--)
    printf ("Case #%d: ", no++), solve ();
  return 0;
}
