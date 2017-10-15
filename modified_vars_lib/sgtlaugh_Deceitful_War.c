#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include <stddef.h>
int t;
int n;
int m;
int exit[10];
int file[10];
bool visit[1 << 10];
bool pin[1 << 10];
ssize_t new_read(int fd, void *buf, size_t count);
FILE * new_freopen(const char *filename, const char *mode, FILE *stream);


int convert()
{
  char str[15];
  scanf("%s", str);
  int jj;
  int result = 0;
  for (jj = 0; str[jj] != 0; jj++)
    result = (result << 1) + (str[jj] - 48);

  return result;
}

int Main()
{
  int fpOut = 0;
  int jj;
  int buffer;
  int bitmask;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d %d", &n, &m);
    memset(pin, 0, sizeof(pin));
    for (jj = 0; jj < n; jj++)
      exit[jj] = convert();

    for (jj = 0; jj < n; jj++)
    {
      file[jj] = convert();
      pin[file[jj]] = 1;
    }

    int result = 1 << 25;
    int lim = (1 << m) - 1;
    for (bitmask = 0; bitmask <= lim; bitmask++)
    {
      memset(visit, 0, sizeof(visit));
      int counter = 0;
      for (jj = 0; jj < n; jj++)
      {
        int x = (exit[jj] ^ bitmask) & lim;
        if ((!visit[x]) && pin[x])
        {
          visit[x] = 1;
          counter++;
        }

      }

      if ((counter == n) && (__builtin_popcount(bitmask) < result))
        result = __builtin_popcount(bitmask);

    }

    if (result == (1 << 25))
      printf("Case #%d: NOT POSSIBLE\n", ++fpOut);
    else
      printf("Case #%d: %d\n", ++fpOut, result);

  }

  return 0;
}



ssize_t new_read(int fd, void *buf, size_t count) {
  return read(fd, buf, count);
}
FILE * new_freopen(const char *filename, const char *mode, FILE *stream) {
  return freopen(filename, mode, stream);
}