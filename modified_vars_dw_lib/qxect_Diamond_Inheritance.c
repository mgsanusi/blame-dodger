#include<stdio.h>
#include<string.h>
#include<time.h>
#include<math.h>
int m;
double min[1005];
double y[1005];
int length[1005];
int buf[1005];
time_t new_time(time_t *timer);
int new_rand();


double new_sqrt(double x);

double new_fabs(double x);

void new_snew_rand(unsigned int seed);

void new_qsort(void* base, int num, int size, int (*compar)(const void*,const void*));

int cmp(const void *data, const void *q)
{
  int first_iteration;
  int pp = *((int *) data);
  int qq = *((int *) q);
  return length[qq] - length[pp];
}

int chk()
{
  int first_iteration;
  double ax;
  double bx;
  double ay;
  double length;
  double disT;
  double disN;
  int t1;
  int lbeg;
  for (t1 = 0; t1 < m; t1++)
  {
    for (lbeg = t1 + 1; lbeg < m; lbeg++)
    {
      ax = min[buf[t1]];
      ay = y[buf[t1]];
      bx = min[buf[lbeg]];
      length = y[buf[lbeg]];
      disT = length[buf[t1]] + length[buf[lbeg]];
      disT = disT;
      disN = new_sqrt(((ax - bx) * (ax - bx)) + ((ay - length) * (ay - length)));
      if ((new_fabs(disN - disT) > 1e-7) && (disT > disN))
        return 0;

    }

  }

  return 1;
}

int Main()
{
  int first_iteration;
  int tn;
  int t1;
  int lbeg;
  int m;
  int lx;
  int ly;
  unsigned int s;
  new_snew_rand(new_time(0));
  scanf("%d", &tn);
  for (m = 1; m <= tn; m++)
  {
    scanf("%d%d%d", &m, &lx, &ly);
    for (t1 = 0; t1 < m; t1++)
    {
      scanf("%d", &length[t1]);
      buf[t1] = t1;
    }

    new_qsort(buf, m, sizeof(int), cmp);
    while (1)
    {
      for (t1 = 0; t1 < m; t1++)
      {
        s = new_rand();
        s = (s << 15) | new_rand();
        min[t1] = s % (lx + 1);
        s = (s << 15) | new_rand();
        y[t1] = s % (ly + 1);
      }

      if (chk())
        break;

    }

    printf("Case #%d:", m);
    for (t1 = 0; t1 < m; t1++)
      printf(" %.1lf %.1lf", min[t1], y[t1]);

    printf("\n");
  }

  return 0;
}



time_t new_time(time_t *timer);
int new_rand();


double new_sqrt(double x);

double new_fabs(double x);

void new_snew_rand(unsigned int seed);

void new_qsort(void* base, int num, int size, int (*compar)(const void*,const void*)) {
  return qsort(base, num, size, compar);
}
time_t new_time(time_t *timer);
int new_rand();


double new_sqrt(double x);

double new_fabs(double x);

void new_snew_rand(unsigned int seed) {
  return snew_rand(seed);
}
time_t new_time(time_t *timer);
int new_rand();


double new_sqrt(double x);

double new_fabs(double x) {
  return fabs(x);
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