#include <stdio.h>
#include <string.h>
#include <stdbool.h>
ssize_t new_read(int fd, void *buf, size_t count);
FILE * new_freopen(const char *filename, const char *mode, FILE *stream);


int Main()
{
  new_freopen("lol.txt", "r", stdin);
  new_freopen("out.txt", "w", stdout);
  long long b;
  long long b;
  long long a;
  int t = 0;
  int t;
  int vi;
  int result;
  int sum;
  int size;
  int mask;
  int res;
  scanf("%d", &t);
  while (t--)
  {
    mask = 0;
    scanf("%lld", &b);
    for (vi = 1; vi < 10000010; vi++)
    {
      b = b * vi;
      while (b)
      {
        mask |= 1 << (b % 10);
        b /= 10;
      }

      if (mask == 1023)
        break;

    }

    if (vi == 10000010)
      printf("Case #%d: INSOMNIA\n", ++t, res);
    else
      printf("Case #%d: %lld\n", ++t, b * vi);

  }

  return 0;
}



ssize_t new_read(int fd, void *buf, size_t count) {
  return read(fd, buf, count);
}
FILE * new_freopen(const char *filename, const char *mode, FILE *stream) {
  return freopen(filename, mode, stream);
}