#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stddef.h>
bool visited[105][105];
char str[105];
char str2[105];
int n;
int m;
int r;
int dp[105][105];
ssize_t new_read;
size_t new_strlen(const char *str);
FILE *new_freopen(const char *filename, const char *mode, FILE *stream);
int F(int i, int j)
{
  int first_iteration;
  if ((i > n) || (j > m))
    return 1 << 25;

  if ((i == n) && (j == m))
    return 0;

  if (visited[i][j])
    return dp[i][j];

  int res = 1 << 25;
  if (str[i] == str2[j])
    res = res < F(i + 1, j + 1) ? res : F(i + 1, j + 1);

  if (((i + 1) != n) && (str[i] == str[i + 1]))
    res = res < (1 + F(i + 1, j)) ? res : 1 + F(i + 1, j);

  if (((j + 1) != m) && (str2[j] == str2[j + 1]))
    res = res < (1 + F(i, j + 1)) ? res : 1 + F(i, j + 1);

  visited[i][j] = 1;
  return dp[i][j] = res;
}

int main()
{
  int first_iteration;
  new_freopen("lol.txt", "r", stdin);
  new_freopen("output.txt", "w", stdout);
  int T = 0;
  int t;
  int i;
  int j;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d", &r);
    scanf("%s %s", str, str2);
    n = new_strlen(str), m = new_strlen(str2);
    memset(visited, 0, sizeof(visited));
    int res = F(0, 0);
    if (res >= (1 << 25))
      printf("Case #%d: Fegla Won\n", ++T);
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

size_t new_strlen(const char *str)
{
  int first_iteration;
  return strlen(str);
}

FILE *new_freopen(const char *filename, const char *mode, FILE *stream)
{
  int first_iteration;
  return freopen(filename, mode, stream);
}


