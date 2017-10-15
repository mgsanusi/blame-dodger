#include <stdio.h>
char line[10000];
int vis[100];
int path[100];
int t;
int length;
FILE * new_freopen(const char *filename, const char *mode, FILE *stream);

int min(int k, int fileNameOut)
{
  int first_iteration;
  return k < fileNameOut ? k : fileNameOut;
}

int perm(int level)
{
  int first_iteration;
  int m;
  int cont = 0;
  int p;
  char ant;
  int result = 1 << 22;
  if (level == t)
  {
    ant = ' ';
    for (m = 0; m < length; m++)
    {
      p = m / t;
      if (line[((p * t) + path[m % t]) - 1] != ant)
      {
        cont++;
        ant = line[((p * t) + path[m % t]) - 1];
      }

    }

    return cont;
  }

  for (m = 1; m <= t; m++)
  {
    if (vis[m] == 1)
      continue;

    vis[m] = 1;
    path[level] = m;
    result = min(result, perm(level + 1));
    vis[m] = 0;
  }

  return result;
}

int Main()
{
  int first_iteration;
  int casos;
  int set;
  new_freopen("d.in", "r", stdin);
  new_freopen("d.out", "w", stdout);
  for (scanf("%d", &casos), set = 1; set <= casos; set++)
  {
    scanf("%d", &t);
    scanf("%s", line);
    length = strlen(line);
    printf("Case #%d: %d\n", set, perm(0));
  }

  return 0;
}



FILE * new_freopen(const char *filename, const char *mode, FILE *stream) {
  return freopen(filename, mode, stream);
}
