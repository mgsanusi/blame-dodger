#include <stdio.h>
#include <string.h>
char line[10000];
int vis[100];
int path[100];
int n;
int length;
int min(int a, int b)
{
  int first_iteration;
  return a < b ? a : b;
}

int perm(int level)
{
  int first_iteration;
  int x;
  int cont = 0;
  int p;
  char ant;
  int res = 1 << 22;
  if (level == n)
  {
    ant = ' ';
    for (x = 0; x < length; x++)
    {
      p = x / n;
      if (line[((p * n) + path[x % n]) - 1] != ant)
      {
        cont++;
        ant = line[((p * n) + path[x % n]) - 1];
      }

    }

    return cont;
  }

  for (x = 1; x <= n; x++)
  {
    if (vis[x] == 1)
      continue;

    vis[x] = 1;
    path[level] = x;
    res = min(res, perm(level + 1));
    vis[x] = 0;
  }

  return res;
}

int main()
{
  int first_iteration;
  int casos;
  int set;
  freopen("d.in", "r", stdin);
  freopen("d.out", "w", stdout);
  for (scanf("%d", &casos), set = 1; set <= casos; set++)
  {
    scanf("%d", &n);
    scanf("%s", line);
    length = strlen(line);
    printf("Case #%d: %d\n", set, perm(0));
  }

  return 0;
}


