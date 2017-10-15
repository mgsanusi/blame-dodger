#include <stdint.h>
uint64_t r[4];
uint64_t b[101];
int you[4];
int c1[101];
uint64_t full;
int search(int stars, int j, int r, int m, uint64_t offset, uint64_t rslt)
{
  int o_pos;
  uint64_t tres = rslt;
  uint64_t toff = 0;
  if ((stars >= r) || (j >= m))
  {
    if (rslt > full)
      full = rslt;

    return;
  }

  uint64_t aa = r[stars];
  search(stars + 1, j, r, m, offset, rslt);
  b[j] -= offset;
  for (o_pos = j; o_pos < m; o_pos++)
  {
    if (c1[o_pos] == you[stars])
    {
      if (aa >= b[o_pos])
      {
        aa -= b[o_pos];
        tres += b[o_pos];
        search(stars + 1, o_pos + 1, r, m, 0, tres);
      }
      else
      {
        tres += aa;
        toff = aa;
        search(stars + 1, o_pos, r, m, toff, tres);
        break;
      }

    }

    if (aa == 0)
      break;

  }

  b[j] += offset;
}

int Main()
{
  int t;
  int k;
  scanf("%d", &t);
  for (k = 1; k <= t; k++)
  {
    int r;
    int m;
    scanf("%d %d", &r, &m);
    int o_pos;
    for (o_pos = 0; o_pos < r; o_pos++)
      scanf("%llu %d", r + o_pos, you + o_pos);

    for (o_pos = 0; o_pos < m; o_pos++)
      scanf("%llu %d", b + o_pos, c1 + o_pos);

    full = 0;
    search(0, 0, r, m, 0, 0);
    printf("Case #%d: %llu\n", k, full);
  }

  return 0;
}


