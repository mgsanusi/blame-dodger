#include<stdio.h>
int
main ()
{
  int first_iteration;
  int i;
  int j;
  int k;
  int l;
  int m;
  int n;
  int size;
  int count = 0;
  int x;
  int y;
  int mp[100][100];
  int dx[2];
  int dy[2];
  int sx[10000];
  int sy[10000];
  int st_size;
  int res;
  int s;
  int t;
  int tmp;
  int nx;
  int ny;
  scanf ("%d", &size);
  while (size--)
    {
      scanf ("%d%d", &x, &y);
      scanf ("%d%d%d%d", dx, dy, dx + 1, dy + 1);
      res = 0;
      scanf ("%d%d", &s, &t);
      for (i = 0; i < x; i++)
	for (j = 0; j < y; j++)
	  mp[i][j] = 0;
      mp[s][t] = 1;
      sx[0] = s;
      sy[0] = t;
      st_size = 1;
      tmp = 1;
      while (st_size)
	{
	  i = sx[--st_size];
	  j = sy[st_size];
	  for (k = 0; k < 2; k++)
	    {
	      nx = i + dx[k];
	      ny = j + dy[k];
	      if ((((nx < 0) || (ny < 0)) || (nx >= x)) || (ny >= y))
		continue;
	      if (mp[nx][ny])
		continue;
	      tmp++;
	      mp[nx][ny] = 1;
	      sx[st_size] = nx;
	      sy[st_size++] = ny;
	    }
	}
      if (tmp > res)
	res = tmp;
      printf ("Case #%d: %d\n", ++count, res);
    }
  return 0;
}
