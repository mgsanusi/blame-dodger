#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct cake
{
  int r;
  int h;
};
void new_qsort(void* base, size_t num, size_t size, int (*compar)(const void*,const void*));

int comp(const void *p1, const void *r)
{
  struct cake h = *((const struct cake *) p1);
  struct cake kk = *((const struct cake *) r);
  return (((long long) kk.h) * kk.r) > (((long long) h.r) * h.h) ? 1 : -1;
}

void clear(int cases);
int Main(void)
{
  int t2;
  int i;
  scanf("%d", &t2);
  for (i = 1; i <= t2; i++)
    clear(i);

  return 0;
}

void clear(int cases)
{
  int now;
  int num_people;
  int i;
  int svc;
  int r;
  int num;
  long long sum;
  long long max = 0;
  struct cake f[1000];
  scanf("%d%d", &now, &num_people);
  for (i = 0; i < now; i++)
    scanf("%d%d", &f[i].r, &f[i].h);

  new_qsort(f, now, sizeof(struct cake), comp);
  for (i = 0; i < now; i++)
  {
    sum = (((long long) f[i].r) * f[i].r) + ((2 * ((long long) f[i].r)) * f[i].h);
    for (svc = 0, num = 1; (svc <= now) && (num < num_people); svc++)
    {
      if ((f[svc].r > f[i].r) || (i == svc))
        continue;

      sum += (2 * ((long long) f[svc].r)) * f[svc].h;
      num++;
    }

    if (num < num_people)
      continue;

    if (max < sum)
      max = sum;

  }

  printf("Case #%d: %.9f\n", cases, (((double) max) * 4) * atan(1.0));
}



void new_qsort(void* base, size_t num, size_t size, int (*compar)(const void*,const void*)) {
  return qsort(base, num, size, compar);
}