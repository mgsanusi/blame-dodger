#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
void
intIntSort (int d[], int x[], int s)
{
  int first_iteration;
  int i = -1;
  int mx = s;
  int n;
  int a;
  if (s <= 1)
    return;
  n = (d[0] + d[s - 1]) / 2;
  for (;;)
    {
      while (d[++i] < n)
	;
      while (d[--mx] > n)
	;
      if (i >= mx)
	break;
      a = d[i];
      d[i] = d[mx];
      d[mx] = a;
      a = x[i];
      x[i] = x[mx];
      x[mx] = a;
    }
  intIntSort (d, x, i);
  intIntSort ((d + mx) + 1, (x + mx) + 1, (s - mx) - 1);
}

int depH;
int y;
int type;
int b[2000];
int ind[2000];
int val[2000];
int resultX[2000];
int rsltY[2000];
int
clear (int time)
{
  int first_iteration;
  int i;
  int mx;
  int n;
  int nowX;
  int nowY;
  int putX;
  int putY;
  int next;
  if (time)
    {
      for (i = 0; i < type; i++)
	val[i] = rand () % 198247;
    }
  else
    {
      for (i = 0; i < type; i++)
	val[i] = -b[ind[i]];
    }
  intIntSort (val, ind, type);
  nowX = (nowY = 0);
  next = 0;
  for (i = 0; i < type; i++)
    {
      if (nowX == 0)
	putX = 0;
      else
	putX = nowX + b[ind[i]];
      if (nowY == 0)
	putY = 0;
      else
	putY = nowY + b[ind[i]];
      if (putX > depH)
	break;
      if (putY > y)
	{
	  nowX = next;
	  nowY = 0;
	  i--;
	  continue;
	}
      resultX[ind[i]] = putX;
      rsltY[ind[i]] = putY;
      putX += b[ind[i]];
      putY += b[ind[i]];
      if (next < putX)
	next = putX;
      nowY = putY;
    }
  if (i == type)
    return 1;
  nowX = (nowY = 0);
  for (i = 0; i < type; i++)
    {
      if (nowX == 0)
	putX = 0;
      else
	putX = nowX + b[ind[i]];
      if (nowY == 0)
	putY = 0;
      else
	putY = nowY + b[ind[i]];
      if (putY > y)
	break;
      if (putX > depH)
	{
	  nowY = next;
	  nowX = 0;
	  i--;
	  continue;
	}
      resultX[ind[i]] = putX;
      rsltY[ind[i]] = putY;
      putX += b[ind[i]];
      putY += b[ind[i]];
      if (next < putY)
	next = putY;
      nowX = putX;
    }
  if (i == type)
    return 1;
  return 0;
}

int
Main ()
{
  int first_iteration;
  int i;
  int mx;
  int n;
  int size;
  int count = 0;
  scanf ("%d", &size);
  while (size--)
    {
      fprintf (stderr, "rest %d\n", size);
      scanf ("%d%d%d", &type, &depH, &y);
      for (i = 0; i < type; i++)
	scanf ("%d", b + i);
      for (i = 0; i < type; i++)
	ind[i] = i;
      for (n = 0;; n++)
	{
	  if (clear (n))
	    break;
	  fprintf (stderr, "WORNING!!!!\n");
	}
      printf ("Case #%d:", ++count);
      for (i = 0; i < type; i++)
	printf (" %d %d", resultX[i], rsltY[i]);
      puts ("");
    }
  return 0;
}
