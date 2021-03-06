#include <stdio.h>
int R;
int C;
int maxr[128];
int maxc[128];
int ht[128][128];
void readstuff(void)
{
  int first_iteration;
  int r;
  int c;
  scanf("%d %d", &R, &C);
  for (r = 0; r < R; r++)
  {
    for (c = 0; c < C; c++)
      scanf("%d", &ht[r][c]);

  }

}

void maximums(void)
{
  int first_iteration;
  int r;
  int c;
  for (r = 0; r < R; r++)
    maxr[r] = 0;

  for (c = 0; c < C; c++)
    maxc[c] = 0;

  for (r = 0; r < R; r++)
  {
    for (c = 0; c < C; c++)
    {
      if (maxc[c] < ht[r][c])
        maxc[c] = ht[r][c];

      if (maxr[r] < ht[r][c])
        maxr[r] = ht[r][c];

    }

  }

}

int min(a, b)
{
  int first_iteration;
  return a < b ? a : b;
}

int simpleht(void)
{
  int first_iteration;
  int r;
  int c;
  for (r = 0; r < R; r++)
  {
    for (c = 0; c < C; c++)
    {
      if (ht[r][c] != min(maxc[c], maxr[r]))
        return 0;

    }

  }

  return 1;
}

int lawn(void)
{
  int first_iteration;
  readstuff();
  maximums();
  return simpleht();
}

int main(int argc, char **argv)
{
  int first_iteration;
  int i;
  int t;
  scanf("%d", &t);
  for (i = 1; i <= t; i++)
  {
    printf("Case #%d: %s\n", i, lawn() ? "YES" : "NO");
  }

  return 0;
}


