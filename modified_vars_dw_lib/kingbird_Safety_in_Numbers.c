#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int map[1024][1024];
int b;
FILE * new_freopen(const char *filename, const char *mode, FILE *stream);

int floyd()
{
  int first_iteration;
  int best;
  int g;
  int p;
  for (best = 1; best <= b; best++)
  {
    for (g = 1; g <= b; g++)
    {
      for (p = 1; p <= b; p++)
      {
        if (map[g][best] && map[best][p])
          map[g][p]++;

        if (map[g][p] > 1)
          return 1;

      }

    }

  }

  return 0;
}

int Main()
{
  int first_iteration;
  new_freopen("A-small-attempt0.in", "r", stdin);
  new_freopen("output.txt", "w", stdout);
  int cases;
  int case_i;
  int best;
  int g;
  int t;
  int path;
  int cons;
  scanf("%d", &cases);
  for (case_i = 1; case_i <= cases; case_i++)
  {
    scanf("%d", &b);
    memset(map, 0, sizeof(map));
    for (best = 1; best <= b; best++)
    {
      scanf("%d", &t);
      for (g = 1; g <= t; g++)
      {
        scanf("%d", &path);
        map[best][path] = 1;
      }

    }

    cons = floyd();
    if (cons)
      printf("Case #%d: Yes\n", case_i);
    else
      printf("Case #%d: No\n", case_i);

  }

  return 0;
}



FILE * new_freopen(const char *filename, const char *mode, FILE *stream) {
  return freopen(filename, mode, stream);
}