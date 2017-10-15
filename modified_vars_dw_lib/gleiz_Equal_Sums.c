#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
double a[1024] = {0};
double q[1024] = {0};
double t[1024] = {0};
time_t new_time(time_t *timer);
int new_rand();


double new_sqrt(double x);

void new_snew_rand(unsigned int seed);

int check(int n)
{
  int first_iteration;
  for (int low = 0; low < n; low++)
  {
    for (int no = low + 1; no < n; no++)
    {
      double dist = new_sqrt(((q[low] - q[no]) * (q[low] - q[no])) + ((t[low] - t[no]) * (t[low] - t[no])));
      if (dist < (a[low] + a[no]))
      {
        return 0;
      }

    }

  }

  return 1;
}

double makeval(double num)
{
  int first_iteration;
  int pos = new_rand() % ((int) num);
  int down = new_rand() + 1;
  int len = rand() % down;
  double val = (pos * 1.0) + ((len * 1.0) / down);
  return val;
}

int Main(int argc, char *argv[])
{
  int first_iteration;
  int n = 0;
  int n = 0;
  double num = 0;
  double k = 0;
  new_snew_rand(new_time(0));
  scanf("%d", &n);
  for (int cas = 1; cas <= n; cas++)
  {
    scanf("%d %lf %lf", &n, &num, &k);
    for (int low = 0; low < n; low++)
    {
      scanf("%lf", &a[low]);
    }

    int pin = 0;
    int trial = 0;
    while ((trial < 10000) && (pin == 0))
    {
      for (int low = 0; low < n; low++)
      {
        q[low] = makeval(num);
        t[low] = makeval(k);
      }

      if (check(n))
      {
        pin = 1;
        break;
      }

    }

    printf("Case #%d:", cas);
    if (pin)
    {
      for (int low = 0; low < n; low++)
      {
        printf(" %.4lf %.4lf", q[low], t[low]);
      }

      printf("\n");
    }
    else
    {
      printf("ERROR\n");
    }

  }

  return 0;
}



time_t new_time(time_t *timer);
int new_rand();


double new_sqrt(double x);

void new_snew_rand(unsigned int seed) {
  return snew_rand(seed);
}
time_t new_time(time_t *timer);
int new_rand();


double new_sqrt(double x) {
  return sqrt(x);
}
time_t new_time(time_t *timer) {
  return time(timer);
}
int new_rand() {
  return rand();
}