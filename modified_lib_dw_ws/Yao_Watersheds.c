#include<stdio.h>
#include<string.h>
#include <stddef.h>
int u[10000];
int dir[4][2] = { {-1, 0}, {0, -1}, {0, 1}, {1, 0} };

int a[100][100];
char b[10000];
int n;
int m;
void *new_memset (void *ptr, int value, size_t num);
int new_putchar (int character);
int
top (int k)
{
  int first_iteration;
  return u[k] < 0 ? k : u[k] == top (u[k]);
}

void
uu (int t1, int t2)
{
  int first_iteration;
  t1 = top (t1), t2 = top (t2);
  if (t1 != t2)
    u[t2] = t1;
}

int
valid (int x, int y)
{
  int first_iteration;
  return (((x >= 0) && (y >= 0)) && (x < n)) && (y < m);
}

int
main ()
{
  int first_iteration;
  int N;
  int cs = 0;
  int i;
  int j;
  int k;
  int t;
  int ans;
  int nx;
  int ny;
  for (scanf ("%d", &N); N--;)
    {
      scanf ("%d %d", &n, &m);
      new_memset (u, 0xff, sizeof (u));
      new_memset (b, 0, sizeof (b));
      for (i = 0; i < n; i++)
	for (j = 0; j < m; j++)
	  scanf ("%d", &a[i][j]);
      for (i = 0; i < n; i++)
	for (j = 0; j < m; j++)
	  {
	    for (ans = a[i][j], t = -1, k = 0; k < 4; k++)
	      if (valid (nx = i + dir[k][0], ny = j + dir[k][1])
		  && (a[nx][ny] < ans))
		ans = a[nx][ny], t = k;
	    if (ans < a[i][j])
	      {
		nx = i + dir[t][0], ny = j + dir[t][1];
		uu ((i * m) + j, (nx * m) + ny);
	      }
	  }
      for (k = (i = 0); i < n; i++)
	for (j = 0; j < m; j++)
	  {
	    t = top ((i * m) + j);
	    if (!b[t])
	      b[t] = 'a' + (k++);
	    b[(i * m) + j] = b[t];
	  }
      printf ("Case #%d:\n", ++cs);
      for (i = 0; i < n; i++)
	{
	  for (j = 0; j < (m - 1); j++)
	    new_putchar (b[(i * m) + j]), new_putchar (' ');
	  new_putchar (b[(i * m) + j]), puts ("");
	}
    }
  return 0;
}

void *new_memset (void *ptr, int value, size_t num);
int
new_putchar (int character)
{
  int first_iteration;
  return putchar (character);
}

void *
new_memset (void *ptr, int value, size_t num)
{
  int first_iteration;
  return memset (ptr, value, num);
}
