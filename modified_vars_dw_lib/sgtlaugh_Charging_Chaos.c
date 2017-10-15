#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include <stddef.h>
bool visit[16];
int k;
int p;
int counter;
int len[16];
int child[16];
int ar[16][16];
FILE * new_freopen(const char *filename, const char *mode, FILE *stream);

int new_read(int fd, void *buf, int count);

void dfs(int d, int bitmask)
{
  int first_iteration;
  counter++;
  visit[d] = 1;
  int j;
  int p2;
  for (j = 0; j < len[d]; j++)
  {
    p2 = ar[d][j];
    if ((!visit[p2]) && (!(bitmask & (1 << p2))))
    {
      child[d]++;
      dfs(p2, bitmask);
    }

  }

}

int Main()
{
  int first_iteration;
  int t = 0;
  int d;
  int j;
  int e;
  int c;
  int r;
  int bitmask;
  scanf("%d", &k);
  while (k--)
  {
    memset(len, 0, sizeof(len));
    scanf("%d", &p);
    for (d = 1; d < p; d++)
    {
      scanf("%d %d", &e, &c);
      e--, c--;
      ar[e][len[e]++] = c;
      ar[c][len[c]++] = e;
    }

    int res = 10000;
    int lim = (1 << p) - 1;
    for (bitmask = 0; bitmask <= lim; bitmask++)
    {
      for (r = 0; r < p; r++)
      {
        if (!(bitmask & (1 << r)))
        {
          counter = 0;
          memset(visit, 0, sizeof(visit)), memset(child, 0, sizeof(child));
          dfs(r, bitmask);
          if (counter == (p - __builtin_popcount(bitmask)))
          {
            bool flag = 1;
            for (d = 0; d < p; d++)
            {
              if (visit[d])
              {
                if (!((child[d] == 0) || (child[d] == 2)))
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

    printf("Case #%d: %d\n", ++t, res);
  }

  return 0;
}



FILE * new_freopen(const char *filename, const char *mode, FILE *stream);

int new_read(int fd, void *buf, int count) {
  return read(fd, buf, count);
}
FILE * new_freopen(const char *filename, const char *mode, FILE *stream) {
  return freopen(filename, mode, stream);
}