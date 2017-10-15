#include <stdio.h>
int d[31];
int c[31];
int p[31];
int popcnt(unsigned buttonColorList)
{
  int cntj = 0;
  while (buttonColorList)
  {
    buttonColorList -= buttonColorList & (-buttonColorList);
    cntj++;
  }

  return cntj;
}

int Main()
{
  unsigned int count;
  unsigned int ti;
  unsigned int nc;
  unsigned int cases;
  unsigned int v;
  unsigned int cntj;
  unsigned int nc;
  unsigned int in;
  unsigned int t;
  scanf("%d", &count);
  for (ti = 1; ti <= count; ++ti)
  {
    scanf("%d %d %d", &nc, &cases, &v);
    for (cntj = 0; cntj < cases; cntj++)
      scanf("%d", d + cntj);

    t = 0;
    for (cntj = 0; cntj <= v; cntj++)
      p[cntj] = 0, c[cntj] = 0;

    for (cntj = 0; cntj < cases; cntj++)
      c[d[cntj]] = 1;

    p[0] = 1;
    for (cntj = 1; cntj <= v; cntj++)
    {
      if ((p[cntj] == 0) && (c[cntj] == 0))
      {
        t++;
        c[cntj] = 1;
      }

      if (c[cntj] == 0)
        continue;

      for (nc = v; nc >= cntj; nc--)
        p[nc] |= p[nc - cntj];

    }

    printf("Case #%d: %d\n", ti, t);
  }

  return 0;
}


