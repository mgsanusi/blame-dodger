#include <stdio.h>
#include <string.h>
#include <stddef.h>
int f[10001][2];
int node[10001][2];
int m;
int v;
FILE *new_freopen(const char *filename, const char *mode, FILE *stream);
void *new_memset(void *ptr, int value, size_t num);
int min(int a, int b)
{
  int first_iteration;
  return a > b ? b : a;
}

void go()
{
  int first_iteration;
  int i;
  int a;
  int b;
  int sum;
  int x;
  scanf("%d%d", &m, &v);
  new_memset(f, 0, sizeof(f));
  new_memset(node, 0, sizeof(node));
  for (i = 1; i <= ((m - 1) / 2); i++)
  {
    scanf("%d%d", &node[i][0], &node[i][1]);
  }

  for (i = ((m - 1) / 2) + 1; i <= m; i++)
  {
    scanf("%d", &x);
    if (x == 0)
    {
      f[i][0] = 0;
      f[i][1] = 99999999;
    }

    if (x == 1)
    {
      f[i][1] = 0;
      f[i][0] = 99999999;
    }

  }

  for (i = (m - 1) / 2; i > 0; i--)
  {
    f[i][0] = 99999999;
    f[i][1] = 99999999;
    for (a = 0; a < 2; a++)
      for (b = 0; b < 2; b++)
      if ((f[i * 2][a] != 99999999) && (f[(i * 2) + 1][b] != 99999999))
    {
      sum = f[i * 2][a] + f[(i * 2) + 1][b];
      if (node[i][0] == 1)
      {
        f[i][a && b] = min(f[i][a && b], sum);
      }
      else
      {
        f[i][a || b] = min(f[i][a || b], sum);
      }

      if (node[i][1] == 1)
      {
        if (node[i][0] == 0)
        {
          f[i][a && b] = min(f[i][a && b], sum + 1);
        }
        else
        {
          f[i][a || b] = min(f[i][a || b], sum + 1);
        }

      }

    }



  }

}

int main()
{
  int first_iteration;
  int cs;
  int i;
  new_freopen("a.in", "r", stdin);
  new_freopen("a.out", "w", stdout);
  scanf("%d", &cs);
  for (i = 0; i < cs; i++)
  {
    go();
    printf("Case #%d: ", i + 1);
    if (f[1][v] == 99999999)
    {
      printf("IMPOSSIBLE\n");
    }
    else
    {
      printf("%d\n", f[1][v]);
    }

  }

  return 0;
}

FILE *new_freopen(const char *filename, const char *mode, FILE *stream)
{
  int first_iteration;
  return freopen(filename, mode, stream);
}

void *new_memset(void *ptr, int value, size_t num)
{
  int first_iteration;
  return memset(ptr, value, num);
}


