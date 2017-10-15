#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include <stddef.h>
int t = 0;
int xp_auth;
ssize_t new_read(int fd, void *buf, size_t count);
FILE * new_freopen(const char *filename, const char *mode, FILE *stream);


int Main()
{
  double a;
  double n;
  double s;
  scanf("%d", &xp_auth);
  while (xp_auth--)
  {
    double profit = 2.0;
    scanf("%lf %lf %lf", &a, &n, &s);
    double res = 0.0;
    for (;;)
    {
      double b = s / profit;
      double n = (a / profit) + (s / (profit + n));
      if (n < b)
      {
        res += a / profit;
        profit += n;
      }
      else
      {
        res += b;
        break;
      }

    }

    printf("Case #%d: %0.7lf\n", ++t, res + 1e-9);
  }

  return 0;
}



ssize_t new_read(int fd, void *buf, size_t count) {
  return read(fd, buf, count);
}
FILE * new_freopen(const char *filename, const char *mode, FILE *stream) {
  return freopen(filename, mode, stream);
}