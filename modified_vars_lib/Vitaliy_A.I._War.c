#include "stdio.h"
#include "memory.h"
#include "assert.h"
int n;
int result[500][500];
int mul[500][500];
int e[500][500];
int c[500];
int lawn[500];
void new_assert(int expression);

int new_abs(int x);

int poisk(int v, int a)
{
  new_assert(v != 1);
  if (result[v][a] >= 0)
    return result[v][a];

  int cc = 0;
  int i;
  for (i = 0; i < n; i++)
    if (e[v][i] && (v != i))
  {
    cc++;
  }


  if (e[v][1])
  {
    result[v][a] = cc;
    return cc;
  }

  int bi = -n;
  for (i = 0; i < n; i++)
    if (e[v][i] && (c[i] == (c[v] - 1)))
  {
    int mp;
    int min = (-2) - mul[v][i];
    if (a < n)
      min -= mul[a][i] - 1;

    min += poisk(i, v);
    if (min > bi)
      bi = min;

  }


  new_assert(bi > (-n));
  result[v][a] = bi + cc;
  return result[v][a];
}

int Main()
{
  int tn;
  scanf("%d\n", &tn);
  int i;
  int tt;
  for (tt = 0; tt < tn; tt++)
  {
    int plus;
    scanf("%d %d", &n, &plus);
    for (i = 0; i < n; i++)
    {
      lawn[i] = 0;
      c[i] = n + 1;
    }

    int mp;
    for (i = 0; i <= n; i++)
      for (mp = 0; mp <= n; mp++)
    {
      e[i][mp] = 0;
      result[i][mp] = -1;
      mul[i][mp] = 0;
    }


    for (i = 0; i < plus; i++)
    {
      int a;
      int a;
      scanf("%d,%d", &a, &a);
      e[a][a] = 1;
      e[a][a] = 1;
    }

    c[1] = 0;
    for (i = 0; i < n; i++)
    {
      int bb = n;
      int bi = -1;
      int mp;
      for (mp = 0; mp < n; mp++)
        if ((!lawn[mp]) && (bb > c[mp]))
      {
        bi = mp;
        bb = c[mp];
      }


      new_assert(bi >= 0);
      if (bi == 0)
        break;

      lawn[bi] = 1;
      for (mp = 0; mp < n; mp++)
        if (((!lawn[mp]) && e[bi][mp]) && (c[mp] > (bb + 1)))
      {
        c[mp] = bb + 1;
      }


    }

    new_assert(c[0] <= n);
    for (i = 0; i < n; i++)
      for (mp = 0; mp < n; mp++)
      if (((i < mp) && (new_abs(c[i] - c[mp]) > 0)) && (new_abs(c[i] - c[mp]) <= 2))
    {
      int a;
      for (a = 0; a < n; a++)
        if ((((a != i) && (a != mp)) && e[a][i]) && e[a][mp])
      {
        mul[i][mp]++;
      }


      mul[mp][i] = mul[i][mp];
    }



    printf("Case #%d: %d %d\n", tt + 1, c[0] - 1, poisk(0, n));
  }

  return 0;
}



void new_assert(int expression);

int new_abs(int x) {
  return abs(x);
}
void new_assert(int expression) {
  return assert(expression);
}