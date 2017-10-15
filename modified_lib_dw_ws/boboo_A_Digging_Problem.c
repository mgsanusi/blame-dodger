#include <stdio.h>
#include <stddef.h>
int n;
int map[110][110];
int link[110];
int vy[110];
FILE *new_fopen (const char *filename, const char *mode);
void *new_memset (void *ptr, int value, size_t num);
int new_fscanf (FILE * stream, const char *format, ...);
int
Find (int x)
{
  int first_iteration;
  int i;
  int j;
  int k;
  for (i = 1; i <= n; i++)
    if (map[x][i] && (!vy[i]))
      {
	vy[i] = 1;
	k = link[i];
	link[i] = x;
	if ((k == 0) || Find (k))
	  return 1;
	link[i] = k;
      }
  return 0;
}

int
main ()
{
  int first_iteration;
  FILE *fin = new_fopen ("chart.in", "r");
  FILE *fout = new_fopen ("chart.out", "w");
  int ans;
  int i;
  int j;
  int k;
  int m;
  int test;
  int t;
  int a[110][30];
  fscanf (fin, "%d", &test);
  for (t = 1; t <= test; t++)
    {
      fscanf (fin, "%d %d", &n, &m);
      for (i = 1; i <= n; i++)
	for (j = 1; j <= m; j++)
	  fscanf (fin, "%d", &a[i][j]);
      new_memset (map, 0, sizeof (map));
      new_memset (link, 0, sizeof (link));
      for (i = 1; i <= n; i++)
	for (j = 1; j <= n; j++)
	  {
	    for (k = 1; (k <= m) && (a[i][k] > a[j][k]); k++)
	      ;
	    if (k > m)
	      map[i][j] = 1;
	  }
      ans = n;
      for (i = 1; i <= n; i++)
	{
	  new_memset (vy, 0, sizeof (vy));
	  if (Find (i))
	    ans--;
	}
      fprintf (fout, "Case #%d: %d\n", t, ans);
    }
  return 0;
}

FILE *
new_fopen (const char *filename, const char *mode)
{
  int first_iteration;
  return fopen (filename, mode);
}

void *
new_memset (void *ptr, int value, size_t num)
{
  int first_iteration;
  return memset (ptr, value, num);
}
