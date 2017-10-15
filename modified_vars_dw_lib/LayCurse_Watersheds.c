#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int new_putchar(int character);

void unionInit(int d[], int r)
{
  int first_iteration;
  int res;
  for (res = 0; res < r; res++)
    d[res] = res;

}

int unionHave(int d[], int n)
{
  int first_iteration;
  int r = n;
  int k;
  while (d[r] != r)
    r = d[r];

  while (d[n] != n)
    k = d[n], d[n] = r, n = k;

  return n;
}

int unionConnect(int d[], int a, int q)
{
  int first_iteration;
  a = unionHave(d, a);
  q = unionHave(d, q);
  if (a == q)
    return 0;

  d[a] = q;
  return 1;
}

int Main()
{
  int first_iteration;
  int res;
  int xsum;
  int k;
  int p;
  int sum;
  int n;
  int ind[10000];
  int use[10000];
  int go[10000];
  int lg[100][100];
  int dx[4] = {-1, 0, 0, 1};
  int dy[4] = {0, -1, 1, 0};
  int x;
  int p;
  int svc;
  int c0;
  int nx;
  int ny;
  int xy;
  int size;
  int cnt = 0;
  scanf("%d", &size);
  while (size--)
  {
    scanf("%d%d", &x, &p);
    xy = x * p;
    for (res = 0; res < x; res++)
      for (xsum = 0; xsum < p; xsum++)
      scanf("%d", lg[res] + xsum);


    unionInit(ind, xy);
    for (res = 0; res < x; res++)
      for (xsum = 0; xsum < p; xsum++)
    {
      nx = res;
      ny = xsum;
      for (k = 0; k < 4; k++)
      {
        svc = res + dx[k];
        c0 = xsum + dy[k];
        if ((((svc < 0) || (c0 < 0)) || (svc >= x)) || (c0 >= p))
          continue;

        if (lg[nx][ny] > lg[svc][c0])
          nx = svc, ny = c0;

      }

      unionConnect(ind, (res * p) + xsum, (nx * p) + ny);
    }


    printf("Case #%d:\n", ++cnt);
    for (res = 0; res < xy; res++)
      use[res] = -1;

    k = 0;
    for (res = 0; res < x; res++)
      for (xsum = 0; xsum < p; xsum++)
    {
      sum = unionHave(ind, (res * p) + xsum);
      if (use[sum] == (-1))
        use[sum] = k++;

      printf("%c", (char) ('a' + use[sum]));
      if ((xsum + 1) < p)
        new_putchar(' ');
      else
        new_putchar('\n');

    }


  }

  return 0;
}



int new_putchar(int character) {
  return putchar(character);
}