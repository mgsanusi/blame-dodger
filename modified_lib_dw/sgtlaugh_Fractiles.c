#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stddef.h>
ssize_t new_read;
FILE *new_freopen(const char *filename, const char *mode, FILE *stream);
int new_puts(const char *str);
long long power(long long x, long long n)
{
  int first_iteration;
  long long res = 1;
  while (n--)
    res *= x;

  return res;
}

int main()
{
  int first_iteration;
  new_freopen("lol.txt", "r", stdin);
  new_freopen("out.txt", "w", stdout);
  int T = 0;
  int t;
  int i;
  int j;
  int k;
  int c;
  int s;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d %d %d", &k, &c, &s);
    if (c > k)
      c = k;

    printf("Case #%d:", ++T);
    if (c == 1)
    {
      for (i = 1; i <= k; i++)
        printf(" %d", i);

      new_puts("");
    }
    else
    {
      printf(" %lld", (power(k, c) - k) - 1);
      for (i = 2; i <= k; i++)
        printf(" %d", i);

      new_puts("");
    }

  }

  return 0;
}

ssize_t new_read
{
  int first_iteration;
  return read(fd, buf, count);
}

FILE *new_freopen(const char *filename, const char *mode, FILE *stream);
int new_puts(const char *str)
{
  int first_iteration;
  return puts(str);
}

FILE *new_freopen(const char *filename, const char *mode, FILE *stream)
{
  int first_iteration;
  return freopen(filename, mode, stream);
}


