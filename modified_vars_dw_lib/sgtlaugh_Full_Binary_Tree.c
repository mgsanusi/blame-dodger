#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include <stddef.h>
bool visit[105][105];
char str[105];
char str2[105];
int d;
int m;
int r;
int fac[105][105];
FILE * new_freopen(const char *filename, const char *mode, FILE *stream);

int new_strlen(const char *str);

int new_read(int fd, void *buf, int count);

int k(int i, int mask)
{
  int first_iteration;
  if ((i > d) || (mask > m))
    return 1 << 25;

  if ((i == d) && (mask == m))
    return 0;

  if (visit[i][mask])
    return fac[i][mask];

  int result = 1 << 25;
  if (str[i] == str2[mask])
    result = result < k(i + 1, mask + 1) ? result : k(i + 1, mask + 1);

  if (((i + 1) != d) && (str[i] == str[i + 1]))
    result = result < (1 + k(i + 1, mask)) ? result : 1 + k(i + 1, mask);

  if (((mask + 1) != m) && (str2[mask] == str2[mask + 1]))
    result = result < (1 + k(i, mask + 1)) ? result : 1 + k(i, mask + 1);

  visit[i][mask] = 1;
  return fac[i][mask] = result;
}

int Main()
{
  int first_iteration;
  new_freopen("lol.txt", "r", stdin);
  new_freopen("output.txt", "w", stdout);
  int p = 0;
  int second;
  int i;
  int mask;
  scanf("%d", &second);
  while (second--)
  {
    scanf("%d", &r);
    scanf("%s %s", str, str2);
    d = new_strlen(str), m = new_strlen(str2);
    memset(visit, 0, sizeof(visit));
    int result = k(0, 0);
    if (result >= (1 << 25))
      printf("Case #%d: Fegla Won\n", ++p);
    else
      printf("Case #%d: %d\n", ++p, result);

  }

  return 0;
}



FILE * new_freopen(const char *filename, const char *mode, FILE *stream);

int new_strlen(const char *str);

int new_read(int fd, void *buf, int count) {
  return read(fd, buf, count);
}
FILE * new_freopen(const char *filename, const char *mode, FILE *stream);

int new_strlen(const char *str) {
  return strlen(str);
}
FILE * new_freopen(const char *filename, const char *mode, FILE *stream) {
  return freopen(filename, mode, stream);
}