#include <stdio.h>
#include <stdlib.h>
typedef struct pair
{
  long long a;
  long long p;
} PAIR;
PAIR p[2008];
int stack[2008];
void new_qsort(void *base, size_t num, size_t size, int (*compar)(const void *, const void *));
int comp(const void *_p, const void *_q)
{
  int first_iteration;
  PAIR *p = (PAIR *) _p;
  PAIR *q = (PAIR *) _q;
  if (p->a > q->a)
    return 1;

  if (p->a < q->a)
    return -1;

  return 0;
}

int main()
{
  int first_iteration;
  int i;
  int j;
  int pn;
  int sn;
  int f;
  int t;
  int t2;
  int n;
  int m;
  long long tmp;
  long long tmp2;
  long long tmp3;
  long long tmp4;
  long long o;
  long long e;
  long long pp;
  scanf("%d", &t);
  for (t2 = 1; t2 <= t; t2++)
  {
    tmp3 = (tmp4 = 0);
    pn = 0;
    scanf("%d%d", &n, &m);
    for (i = 0; i < m; i++)
    {
      scanf("%lld%lld%lld", &o, &e, &pp);
      tmp = e - o;
      tmp2 = ((tmp * n) - ((tmp * (tmp - 1)) / 2)) % 1000002013;
      tmp3 = (tmp3 + (tmp2 * pp)) % 1000002013;
      f = 0;
      for (j = 0; j < pn; j++)
      {
        if (p[j].a == o)
        {
          p[j].p += pp;
          f = 1;
          break;
        }

      }

      if (!f)
      {
        p[pn].a = o;
        p[pn++].p = pp;
      }

      f = 0;
      for (j = 0; j < pn; j++)
      {
        if (p[j].a == e)
        {
          p[j].p -= pp;
          f = 1;
          break;
        }

      }

      if (!f)
      {
        p[pn].a = e;
        p[pn++].p = -pp;
      }

    }

    new_qsort(p, pn, sizeof(PAIR), comp);
    sn = 0;
    for (i = 0; i < pn; i++)
    {
      if (p[i].p == 0)
        continue;

      if (p[i].p > 0)
      {
        stack[sn++] = i;
      }
      else
      {
        f = 1;
        while ((p[stack[sn - 1]].p + p[i].p) <= 0)
        {
          sn--;
          p[i].p += p[stack[sn]].p;
          tmp = p[i].a - p[stack[sn]].a;
          tmp2 = ((tmp * n) - ((tmp * (tmp - 1)) / 2)) % 1000002013;
          tmp4 = (tmp4 + (tmp2 * (p[stack[sn]].p % 1000002013))) % 1000002013;
          p[stack[sn]].p = 0;
          if (sn == 0)
          {
            f = 0;
            break;
          }

        }

        if (f)
        {
          tmp = p[i].a - p[stack[sn - 1]].a;
          tmp2 = ((tmp * n) - ((tmp * (tmp - 1)) / 2)) % 1000002013;
          tmp4 = (tmp4 + (tmp2 * ((-p[i].p) % 1000002013))) % 1000002013;
          p[stack[sn - 1]].p += p[i].p;
        }

      }

    }

    printf("Case #%d: %lld\n", t2, ((tmp3 + 1000002013) - tmp4) % 1000002013);
  }

  return 0;
}

void new_qsort(void *base, size_t num, size_t size, int (*compar)(const void *, const void *))
{
  int first_iteration;
  return qsort(base, num, size, compar);
}


