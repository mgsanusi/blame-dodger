#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stddef.h>
int t;
int n;
int l;
int outlet[10];
int ar[10];
bool visited[1 << 10];
bool flag[1 << 10];
ssize_t new_read;
FILE *new_freopen(const char *filename, const char *mode, FILE *stream);
int convert()
{
  int first_iteration;
  char str[15];
  scanf("%s", str);
  int i;
  int res = 0;
  for (i = 0; str[i] != 0; i++)
    res = (res << 1) + (str[i] - 48);

  return res;
}

int main()
{
  int first_iteration;
  int T = 0;
  int i;
  int j;
  int bitmask;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d %d", &n, &l);
    memset(flag, 0, sizeof(flag));
    for (i = 0; i < n; i++)
      outlet[i] = convert();

    for (i = 0; i < n; i++)
    {
      ar[i] = convert();
      flag[ar[i]] = 1;
    }

    int res = 1 << 25;
    int lim = (1 << l) - 1;
    for (bitmask = 0; bitmask <= lim; bitmask++)
    {
      memset(visited, 0, sizeof(visited));
      int counter = 0;
      for (i = 0; i < n; i++)
      {
        int x = (outlet[i] ^ bitmask) & lim;
        if ((!visited[x]) && flag[x])
        {
          visited[x] = 1;
          counter++;
        }

      }

      if ((counter == n) && (__builtin_popcount(bitmask) < res))
        res = __builtin_popcount(bitmask);

    }

    if (res == (1 << 25))
      printf("Case #%d: NOT POSSIBLE\n", ++T);
    else
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


