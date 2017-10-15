#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int d;
int p;
int w;
int c;
int r[12345];
double ans[12345];
double y[12345];
int letter;
int ang;
double dis;
int new_rand();

double new_sqrt(double x);

int new_puts(const char *str);

double dis(double ans, double y, double tmp, double b)
{
  return new_sqrt(((ans - tmp) * (ans - tmp)) + ((y - b) * (y - b)));
}

int count;
int train;
int Main()
{
  int d;
  int Case = 0;
  int now;
  int j;
  int num_queries;
  scanf("%d", &d);
  while (d--)
  {
    scanf("%d %d %d", &p, &w, &c);
    for (now = 0; now < p; ++now)
    {
      scanf("%d", &r[now]);
    }

    num_queries = 0;
    count = w * 100;
    train = c * 100;
    while (num_queries == 0)
    {
      for (now = 0; now < p; ++now)
      {
        ans[now] = ((double) (((new_rand() % 100000) * (new_rand() % 100000)) % count)) / 100;
        y[now] = ((double) (((new_rand() % 100000) * (new_rand() % 100000)) % train)) / 100;
      }

      for (now = 0, num_queries = 1; (now < p) && num_queries; ++now)
      {
        for (j = now + 1; (j < p) && num_queries; ++j)
        {
          dis = ((int) dis(ans[now], y[now], ans[j], y[j])) + 1;
          if (dis < (r[now] + r[j]))
            num_queries = 0;

        }

      }

    }

    printf("Case #%d:", ++Case);
    for (now = 0; now < p; ++now)
    {
      printf(" %.2lf %.2lf", ans[now], y[now]);
    }

    new_puts("");
  }

  return 0;
}



int new_rand();

double new_sqrt(double x);

int new_puts(const char *str) {
  return puts(str);
}
int new_rand();

double new_sqrt(double x) {
  return sqrt(x);
}
int new_rand() {
  return rand();
}