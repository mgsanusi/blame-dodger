#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
int vz;
int a;
int car;
char car[120][120];
char visit[130];
int batch[120];
int use[120];
int i;
int t;
int b;
int j;
int result;
char last;
FILE * new_freopen(const char *filename, const char *mode, FILE *stream);

int dfs(int level)
{
  if (level == car)
  {
    int i;
    int t;
    last = car[batch[0]][0];
    memset(visit, 0, sizeof(visit));
    visit[last] = 1;
    for (i = 0; i < car; i++)
    {
      j = strlen(car[batch[i]]);
      for (t = 0; t < j; t++)
      {
        if (car[batch[i]][t] == last)
          continue;

        if (visit[car[batch[i]][t]])
          return;

        visit[car[batch[i]][t]] = 1;
        last = car[batch[i]][t];
      }

    }

    result++;
    return;
  }

  int i;
  for (i = 0; i < car; i++)
    if (!use[i])
  {
    use[i] = 1;
    batch[level] = i;
    dfs(level + 1);
    use[i] = 0;
  }


}

int Main()
{
  new_freopen("B-small-attempt0.in", "r", stdin);
  new_freopen("B-small-attempt0.out", "w", stdout);
  scanf("%d", &vz);
  for (a = 1; a <= vz; a++)
  {
    printf("Case #%d: ", a);
    scanf("%d", &car);
    for (i = 0; i < car; i++)
      scanf("%s", car[i]);

    result = 0;
    dfs(0);
    printf("%d\n", result);
  }

  return 0;
}



FILE * new_freopen(const char *filename, const char *mode, FILE *stream) {
  return freopen(filename, mode, stream);
}