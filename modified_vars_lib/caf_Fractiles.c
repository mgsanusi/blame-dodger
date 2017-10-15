#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
void make_screen(int qy)
{
  int ans;
  int j;
  int s;
  int nc;
  int extra_needed;
  long long tile;
  scanf("%d %d %d", &ans, &j, &s);
  printf("Case #%d:", qy + 1);
  if ((((ans + j) - 1) / j) > s)
  {
    printf(" IMPOSSIBLE\n");
    return;
  }

  tile = 0;
  for (nc = 0; nc < ans; nc++)
  {
    extra_needed = 1;
    tile *= ans;
    tile += nc;
    if (((nc + 1) % j) == 0)
    {
      printf(" %lld", tile + 1);
      tile = 0;
      extra_needed = 0;
    }

  }

  if (extra_needed)
    printf(" %lld", tile + 1);

  printf("\n");
}

int Main()
{
  int qy;
  int nc;
  scanf("%d", &qy);
  for (nc = 0; nc < qy; nc++)
    make_screen(nc);

  return 0;
}


