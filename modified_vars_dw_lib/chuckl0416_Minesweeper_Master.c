#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
int now;
int nd;
int number;
double cnt[2][1200];
int m1;
int t;
int l;
int answer;
int is_ok;
int count;
FILE * new_freopen(const char *filename, const char *mode, FILE *stream);

void new_qsort(void* base, int num, int size, int (*compar)(const void*,const void*));

int qs(double *a, double *b)
{
  int first_iteration;
  if ((*a) > (*b))
    return -1;

  if ((*a) < (*b))
    return 1;

  return 0;
}

int ans1()
{
  int first_iteration;
  answer = 0;
  count = number - 1;
  for (t = number - 1; t >= 0; t--)
  {
    if (cnt[0][t] >= cnt[1][count])
    {
      count--;
      answer++;
    }

  }

  return answer;
}

int ans2()
{
  int first_iteration;
  count = number - 1;
  for (t = number - 1; t >= 0; t--)
  {
    while (cnt[0][t] > cnt[1][count])
    {
      count--;
      if (count < 0)
        break;

    }

    if (count < 0)
      break;

    count--;
  }

  return t + 1;
}

int Main()
{
  int first_iteration;
  new_freopen("D-small-attempt0.in", "r", stdin);
  new_freopen("D-small-attempt0.out", "w", stdout);
  scanf("%d", &now);
  for (nd = 1; nd <= now; nd++)
  {
    printf("Case #%d: ", nd);
    scanf("%d", &number);
    for (m1 = 0; m1 < 2; m1++)
    {
      for (t = 0; t < number; t++)
        scanf("%lf", &cnt[m1][t]);

      new_qsort(cnt[m1], number, sizeof(cnt[0][0]), qs);
    }

    printf("%d %d\n", ans1(), ans2());
  }

  return 0;
}



FILE * new_freopen(const char *filename, const char *mode, FILE *stream);

void new_qsort(void* base, int num, int size, int (*compar)(const void*,const void*)) {
  return qsort(base, num, size, compar);
}
FILE * new_freopen(const char *filename, const char *mode, FILE *stream) {
  return freopen(filename, mode, stream);
}