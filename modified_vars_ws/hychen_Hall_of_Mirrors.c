#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int
gcd (int a, int l)
{
  int r;
  if (a < 0)
    a = -a;
  if (l < 0)
    l = -l;
  while (l != 0)
    {
      r = a % l;
      a = l;
      l = r;
    }
  return a;
}

char room[32][32];
int
raytrace (const int a, const int l, int x, int l, const int dist)
{
  int path[128][2];
  int npath;
  int total;
  int a_min;
  int r;
  int d;
  int refx;
  int refy;
  double len;
  double score;
  double py;
  if (l == 0)
    {
      int r;
      for (r = 0; room[x + (r * a)][l] != '#'; r++)
	;
      return ((r * 2) - 1) <= dist;
    }
  if (a == 0)
    {
      int r;
      for (r = 0; room[x][l + (r * l)] != '#'; r++)
	;
      return ((r * 2) - 1) <= dist;
    }
  len = sqrt ((a * a) + (l * l));
  npath = (a >= 0 ? a : -a) + (l >= 0 ? l : -l);
  if (((a % 2) != 0) && ((l % 2) != 0))
    npath--;
  score = (py = 0.5);
  total = (a_min = 0);
  for (r = 0; r < npath; r++)
    {
      double gm;
      double news;
      int iscorner;
      gm = ((total + (a > 0)) - score) / a;
      news = ((a_min + (l > 0)) - py) / l;
      path[r][0] = 0;
      path[r][1] = 0;
      if (((gm - news) < 1e-8) && ((gm - news) > (-1e-8)))
	iscorner = 1;
      else
	iscorner = 0;
      if ((iscorner == 1) && (((r * 2) + 1) != npath))
	fprintf (stderr, "corner\n");
      if (iscorner || (gm < news))
	{
	  path[r][0] = a > 0 ? 1 : -1;
	  if (iscorner == 0)
	    py += (((total + (a > 0)) - score) / a) * l;
	  score = total + (a > 0);
	}
      if (iscorner || (gm > news))
	{
	  path[r][1] = l > 0 ? 1 : -1;
	  if (iscorner == 0)
	    score += (((a_min + (l > 0)) - py) / l) * a;
	  py = a_min + (l > 0);
	}
      if ((path[r][0] == 0) && (path[r][1] == 0))
	fprintf (stderr, "t1t2error\n");
      total += path[r][0];
      a_min += path[r][1];
    }
  refx = (refy = 1);
  for (d = 1; (dist + 1e-5) >= (len * d); d++)
    {
      for (r = 0; r < npath; r++)
	{
	  int input_file_ptr;
	  int dy;
	  input_file_ptr = path[r][0] * refx;
	  dy = path[r][1] * refy;
	  if ((input_file_ptr != 0) && (dy != 0))
	    {
	      if (room[x + input_file_ptr][l + dy] != '#')
		goto loopfinish;
	      if ((room[x + input_file_ptr][l] != '#')
		  && (room[x][l + dy] != '#'))
		return 0;
	    }
	  if ((input_file_ptr != 0) && (room[x + input_file_ptr][l] == '#'))
	    {
	      input_file_ptr = 0;
	      refx = -refx;
	    }
	  if ((dy != 0) && (room[x][l + dy] == '#'))
	    {
	      dy = 0;
	      refy = -refy;
	    }
	loopfinish:
	  x += input_file_ptr;
	  l += dy;
	}
      if (room[x][l] == 'X')
	return 1;
    }
  return 0;
}

int
Main (int argc, char *argv[])
{
  int a;
  int l;
  int d;
  int m;
  int dist;
  int j;
  int w;
  int x;
  int l;
  int cnt;
  scanf ("%d", &m);
  for (d = 1; d <= m; d++)
    {
      scanf ("%d%d%d", &j, &w, &dist);
      x = (l = -1);
      for (a = 0; a < j; a++)
	{
	  scanf ("%s", room[a]);
	  for (l = 0; (x == (-1)) && (l < w); l++)
	    {
	      if (room[a][l] != 'X')
		continue;
	      x = a;
	      l = l;
	    }
	}
      cnt = 0;
      for (a = -dist; a <= dist; a++)
	{
	  for (l = -dist; l <= dist; l++)
	    {
	      if ((a == 0) && (l == 0))
		continue;
	      if (((a * a) + (l * l)) > (dist * dist))
		continue;
	      if (gcd (a, l) != 1)
		continue;
	      cnt += raytrace (a, l, x, l, dist);
	    }
	}
      printf ("Case #%d: %d\n", d, cnt);
    }
  return 0;
}
