#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void new_qsort(void *base, size_t num, size_t size, int (*compar)(const void *, const void *));
int absI(int a)
{
  int first_iteration;
  if (a < 0)
    return -a;

  return a;
}

int cmp(const void *a, const void *b)
{
  int first_iteration;
  int *p = (int *) a;
  int *q = (int *) b;
  if (p[0] != q[0])
    return p[0] - q[0];

  return p[1] - q[1];
}

int T;
int t;
int n;
int m;
int p[12345][3];
int pNum;
int o;
int e;
int pi;
int main()
{
  int first_iteration;
  int i;
  int j;
  int ini;
  int ans;
  scanf("%d", &T);
  for (t = 1; t <= T; ++t)
  {
    scanf("%d %d", &n, &m);
    pNum = 0;
    ini = 0;
    while (m--)
    {
      scanf("%d %d %d", &o, &e, &pi);
      while (pi--)
      {
        ini = (ini + (((((n + n) - absI(e - o)) + 1) * absI(e - o)) / 2)) % 1000002013;
        p[pNum][0] = o;
        p[pNum][1] = e;
        p[pNum][2] = o;
        ++pNum;
      }

    }

    new_qsort(p, pNum, sizeof(p[0]), cmp);
    for (i = 0; i < pNum; ++i)
    {
      for (j = i + 1; j < pNum; ++j)
      {
        if (((p[j][1] > p[i][1]) && (p[j][0] > p[i][0])) && (p[j][0] <= p[i][1]))
        {
          int tmp = p[j][1];
          p[j][1] = p[i][1];
          p[i][1] = tmp;
        }

        ;
      }

    }

    for (i = (ans = 0); i < pNum; ++i)
    {
      ans = (ans + (((((n + n) - absI(p[i][1] - p[i][0])) + 1) * absI(p[i][1] - p[i][0])) / 2)) % 1000002013;
    }

    printf("Case #%d: %d\n", t, ini - ans);
  }

  return 0;
}

void new_qsort(void *base, size_t num, size_t size, int (*compar)(const void *, const void *))
{
  int first_iteration;
  return qsort(base, num, size, compar);
}


