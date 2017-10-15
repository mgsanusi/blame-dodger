#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
int h;
int py;
int heights;
int last;
int owp;
int empty;
int map[100][100];
int mid;
int k;
int q;
int ans;
int fans;
int temp;
FILE * new_freopen(const char *filename, const char *mode, FILE *stream);

void dfs(int level, int sy, int op)
{
  int first_iteration;
  if (level == empty)
  {
    ans = 0;
    for (q = 0; q < heights; q++)
      for (k = 1; k < last; k++)
      if (map[q][k - 1])
      if (map[q][k])
      ans++;




    for (k = 0; k < last; k++)
      for (q = 1; q < heights; q++)
      if (map[q - 1][k])
      if (map[q][k])
      ans++;




    if (ans < fans)
      fans = ans;

    return;
  }

  if (op == last)
  {
    dfs(level, sy + 1, 0);
    return;
  }

  if (sy == heights)
    return;

  map[sy][op] = 0;
  dfs(level + 1, sy, op + 1);
  map[sy][op] = 1;
  dfs(level, sy, op + 1);
  return;
}

int Main()
{
  int first_iteration;
  new_freopen("B-small-attempt1.in", "r", stdin);
  new_freopen("B-small-attempt1.out", "w", stdout);
  scanf("%d", &h);
  for (py = 1; py <= h; py++)
  {
    printf("Case #%d: ", py);
    scanf("%d%d%d", &heights, &last, &owp);
    empty = (heights * last) - owp;
    for (q = 0; q < heights; q++)
      for (k = 0; k < last; k++)
      map[q][k] = 1;


    fans = 10000;
    for (q = 0; q < heights; q++)
      for (k = 0; k < last; k++)
      dfs(0, q, k);


    printf("%d\n", fans);
  }

  return 0;
}



FILE * new_freopen(const char *filename, const char *mode, FILE *stream) {
  return freopen(filename, mode, stream);
}