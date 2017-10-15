#include <stdio.h>
int result;
int u;
int maxr[128];
int maxc[128];
int sn[128][128];
void readstuff(void)
{
  int r;
  int mask;
  scanf("%d %d", &result, &u);
  for (r = 0; r < result; r++)
  {
    for (mask = 0; mask < u; mask++)
      scanf("%d", &sn[r][mask]);

  }

}

void maximums(void)
{
  int r;
  int mask;
  for (r = 0; r < result; r++)
    maxr[r] = 0;

  for (mask = 0; mask < u; mask++)
    maxc[mask] = 0;

  for (r = 0; r < result; r++)
  {
    for (mask = 0; mask < u; mask++)
    {
      if (maxc[mask] < sn[r][mask])
        maxc[mask] = sn[r][mask];

      if (maxr[r] < sn[r][mask])
        maxr[r] = sn[r][mask];

    }

  }

}

int min(a, b)
{
  return a < b ? a : b;
}

int simpleht(void)
{
  int r;
  int mask;
  for (r = 0; r < result; r++)
  {
    for (mask = 0; mask < u; mask++)
    {
      if (sn[r][mask] != min(maxc[mask], maxr[r]))
        return 0;

    }

  }

  return 1;
}

int lawn(void)
{
  readstuff();
  maximums();
  return simpleht();
}

int Main(int argc, char **argv)
{
  int j;
  int p_hit;
  scanf("%d", &p_hit);
  for (j = 1; j <= p_hit; j++)
  {
    printf("Case #%d: %s\n", j, lawn() ? "YES" : "NO");
  }

  return 0;
}


