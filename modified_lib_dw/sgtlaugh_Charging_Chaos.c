#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stddef.h>
bool visited[16];
int t;
int n;
int counter;
int len[16];
int children[16];
int ar[16][16];
ssize_t new_read;
FILE *new_freopen(const char *filename, const char *mode, FILE *stream);
void dfs(int i, int bitmask)
{
  int first_iteration;
  counter++;
  visited[i] = 1;
  int j;
  int x;
  for (j = 0; j < len[i]; j++)
  {
    x = ar[i][j];
    if ((!visited[x]) && (!(bitmask & (1 << x))))
    {
      children[i]++;
      dfs(x, bitmask);
    }

  }

}

int main()
{
  int first_iteration;
  int T = 0;
  int i;
  int j;
  int a;
  int b;
  int r;
  int bitmask;
  scanf("%d", &t);
  while (t--)
  {
    memset(len, 0, sizeof(len));
    scanf("%d", &n);
    for (i = 1; i < n; i++)
    {
      scanf("%d %d", &a, &b);
      a--, b--;
      ar[a][len[a]++] = b;
      ar[b][len[b]++] = a;
    }

    int res = 10000;
    int lim = (1 << n) - 1;
    for (bitmask = 0; bitmask <= lim; bitmask++)
    {
      for (r = 0; r < n; r++)
      {
        if (!(bitmask & (1 << r)))
        {
          counter = 0;
          memset(visited, 0, sizeof(visited)), memset(children, 0, sizeof(children));
          dfs(r, bitmask);
          if (counter == (n - __builtin_popcount(bitmask)))
          {
            bool flag = 1;
            for (i = 0; i < n; i++)
            {
              if (visited[i])
              {
                if (!((children[i] == 0) || (children[i] == 2)))
                {
                  flag = 0;
                  break;
                }

              }

            }

            if (flag && (__builtin_popcount(bitmask) < res))
              res = __builtin_popcount(bitmask);

          }

        }

      }

    }

    printf("Case #%d: %d\n", ++T, res);
  }

  return 0;
}

ssize_t new_read
{
  int first_iteration;
  return read(fd, buf, count);
}

FILE *new_freopen(const char *filename, const char *mode, FILE *stream)
{
  int first_iteration;
  return freopen(filename, mode, stream);
}


