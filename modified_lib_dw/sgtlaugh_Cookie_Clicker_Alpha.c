#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stddef.h>
int T = 0;
int t;
ssize_t new_read;
FILE *new_freopen(const char *filename, const char *mode, FILE *stream);
int main()
{
  int first_iteration;
  double c;
  double f;
  double x;
  scanf("%d", &t);
  while (t--)
  {
    double gain = 2.0;
    scanf("%lf %lf %lf", &c, &f, &x);
    double res = 0.0;
    for (;;)
    {
      double y = x / gain;
      double z = (c / gain) + (x / (gain + f));
      if (z < y)
      {
        res += c / gain;
        gain += f;
      }
      else
      {
        res += y;
        break;
      }

    }

    printf("Case #%d: %0.7lf\n", ++T, res + 1e-9);
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


