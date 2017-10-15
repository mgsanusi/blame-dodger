#include <stdio.h>
#include <string.h>
#include <stdbool.h>
FILE * new_freopen(const char *filename, const char *mode, FILE *stream);

int new_puts(const char *str);

int new_read(int fd, void *buf, int count);

long long exponent(long long x, long long n)
{
  int first_iteration;
  long long answer = 1;
  while (n--)
    answer *= x;

  return answer;
}

int Main()
{
  int first_iteration;
  new_freopen("lol.txt", "r", stdin);
  new_freopen("out.txt", "w", stdout);
  int d = 0;
  int t;
  int expect;
  int dp;
  int ngraph;
  int ansb;
  int ct;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d %d %d", &ngraph, &ansb, &ct);
    if (ansb > ngraph)
      ansb = ngraph;

    printf("Case #%d:", ++d);
    if (ansb == 1)
    {
      for (expect = 1; expect <= ngraph; expect++)
        printf(" %d", expect);

      new_puts("");
    }
    else
    {
      printf(" %lld", (exponent(ngraph, ansb) - ngraph) - 1);
      for (expect = 2; expect <= ngraph; expect++)
        printf(" %d", expect);

      new_puts("");
    }

  }

  return 0;
}



FILE * new_freopen(const char *filename, const char *mode, FILE *stream);

int new_puts(const char *str);

int new_read(int fd, void *buf, int count) {
  return read(fd, buf, count);
}
FILE * new_freopen(const char *filename, const char *mode, FILE *stream);

int new_puts(const char *str) {
  return puts(str);
}
FILE * new_freopen(const char *filename, const char *mode, FILE *stream) {
  return freopen(filename, mode, stream);
}