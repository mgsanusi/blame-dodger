#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int kk;
int cas;
int cell[100][100];
int result;
int dirX[] = { 0, -1, 1, 0, 0 };
int dirY[] = { 0, 0, 0, -1, 1 };

int
search (int x, int l, int dir)
{
  int i;
  int h;
  i = x + dirX[dir];
  h = l + dirY[dir];
  if ((((i < 0) || (i >= kk)) || (h < 0)) || (h >= cas))
    {
      return 0;
    }
  if (cell[i][h])
    return 1;
  return search (i, h, dir);
}

void
clear (void)
{
  int x;
  int l;
  int dir;
  for (x = 0; x < kk; ++x)
    {
      for (l = 0; l < cas; ++l)
	{
	  dir = cell[x][l];
	  if (!dir)
	    continue;
	  if (search (x, l, dir))
	    {
	      continue;
	    }
	  if (((search (x, l, 1) || search (x, l, 2)) || search (x, l, 3))
	      || search (x, l, 4))
	    result++;
	  else
	    {
	      result = -1;
	      return;
	    }
	}
    }
}

void
clearAndPrint (void)
{
  int i;
  int h;
  char buf[102];
  scanf ("%d %d", &kk, &cas);
  gets (buf);
  for (i = 0; i < kk; ++i)
    {
      gets (buf);
      for (h = 0; h < cas; ++h)
	{
	  switch (buf[h])
	    {
	    case '.':
	      cell[i][h] = 0;
	      break;
	    case '^':
	      cell[i][h] = 1;
	      break;
	    case 'v':
	      cell[i][h] = 2;
	      break;
	    case '<':
	      cell[i][h] = 3;
	      break;
	    case '>':
	      cell[i][h] = 4;
	      break;
	    default:
	      fprintf (stderr, "input error\n");
	    }
	}
    }
  result = 0;
  clear ();
  if (result < 0)
    printf ("IMPOSSIBLE\n");
  else
    printf ("%d\n", result);
}

int
Main (void)
{
  int datasetNum;
  int caseNo;
  scanf ("%d", &datasetNum);
  for (caseNo = 1; caseNo <= datasetNum; ++caseNo)
    {
      printf ("Case #%d: ", caseNo);
      clearAndPrint ();
    }
  return 0;
}
