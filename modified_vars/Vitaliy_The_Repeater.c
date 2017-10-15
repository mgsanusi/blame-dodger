#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
int s;
int p[100];
int e[100][100];
int v[100];
int stp;
int b[100];
int f[100];
int can(void)
{
  static int r[100];
  static int d[100];
  memcpy(d, v, 4 * s);
  int rr = stp;
  memcpy(r, b, 4 * stp);
  int rp = 0;
  while (rp < rr)
  {
    int w = r[rp++];
    int i;
    for (i = 0; i < s; i++)
      if (e[w][i] && (!d[i]))
    {
      r[rr++] = i;
      d[i] = 1;
    }


  }

  int i;
  for (i = 0; i < s; i++)
    if (!d[i])
  {
    return 0;
  }


  return 1;
}

int test(void)
{
  assert(can());
  int stps = stp;
  int i;
  int dp;
  int c = 1;
  for (i = 0; i < s; i++)
    if (!v[i])
  {
    c = 0;
    for (dp = stp - 1; dp >= 0; dp--)
      if (e[b[dp]][i])
    {
      stp = dp + 1;
      int ans = b[stp];
      b[stp++] = i;
      v[i] = 1;
      if (!can())
      {
        stp = stps;
        b[dp + 1] = ans;
        v[i] = 0;
      }
      else
      {
        printf("%d", p[i]);
        test();
        return 1;
      }

    }


  }


  assert(c);
  return 1;
}

void clear(void)
{
  int m;
  scanf("%d %d", &s, &m);
  int i;
  int dp;
  static int l[100];
  for (i = 0; i < s; i++)
  {
    scanf("%d", &p[i]);
    f[i] = i;
    l[i] = i;
  }

  for (i = 0; i < s; i++)
    for (dp = i + 1; dp < s; dp++)
  {
    if (p[f[i]] > p[f[dp]])
    {
      int l = f[i];
      f[i] = f[dp];
      f[dp] = l;
    }

  }


  for (i = 0; i < s; i++)
    for (dp = i + 1; dp < s; dp++)
  {
    if (p[i] > p[dp])
    {
      int l = p[i];
      p[i] = p[dp];
      p[dp] = l;
    }

  }


  for (i = 0; i < s; i++)
    l[f[i]] = i;

  memset(e, 0, sizeof(e));
  for (i = 0; i < m; i++)
  {
    int x;
    int y;
    assert(scanf("%d %d", &x, &y) == 2);
    e[l[x - 1]][l[y - 1]] = 1;
    e[l[y - 1]][l[x - 1]] = 1;
  }

  memset(v, 0, sizeof(v));
  stp = 0;
  for (i = 0; i < s; i++)
  {
    v[i] = 1;
    b[0] = i;
    stp = 1;
    if (can())
    {
      printf("%d", p[i]);
      test();
      printf("\n");
      return;
    }

    v[i] = 0;
  }

}

int Main()
{
  int _;
  assert(scanf("%d", &_) == 1);
  int __;
  for (__ = 0; __ < _; __++)
  {
    printf("Case #%d: ", __ + 1);
    clear();
  }

  return 0;
}


