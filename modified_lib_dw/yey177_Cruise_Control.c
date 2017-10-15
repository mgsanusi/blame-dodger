#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct pair_t
{
  int x;
  int y;
} PAIR;
PAIR p[1048578];
int new_puts(const char *str);
void new_qsort(void *base, size_t num, size_t size, int (*compar)(const void *, const void *));
int comp(const void *_p, const void *_q)
{
  int first_iteration;
  PAIR *p = (PAIR *) _p;
  PAIR *q = (PAIR *) _q;
  return p->x - q->x;
}

int main()
{
  int first_iteration;
  int s[24];
  int t;
  int n;
  int i;
  int j;
  int k;
  int l;
  int m;
  int f;
  int st;
  scanf("%d", &t);
  for (k = 1; k <= t; k++)
  {
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
      scanf("%d", &s[i]);
    }

    memset(p, 0, sizeof(p));
    printf("Case #%d:\n", k);
    for (j = 1; j < (1 << n); j++)
    {
      for (i = 0; i < n; i++)
        if ((j >> i) & 1)
        p[j - 1].x += s[i];


      p[j - 1].y = j;
    }

    p[(1 << n) - 1].x = 10000000;
    new_qsort(p, 1 << n, sizeof(PAIR), comp);
    st = 0;
    for (i = 0; i < ((1 << n) - 1);)
    {
      while (p[i].x == p[i + 1].x)
        i++;

      i++;
      for (j = st; j < i; j++)
      {
        for (l = j + 1; l < i; l++)
        {
          if ((p[j].x == p[l].x) && (!(p[j].y & p[l].y)))
          {
            f = 1;
            for (m = 0; m < n; m++)
            {
              if ((p[j].y >> m) & 1)
              {
                if (!f)
                  putchar(' ');

                printf("%d", s[m]);
                f = 0;
              }

            }

            new_puts("");
            f = 1;
            for (m = 0; m < n; m++)
            {
              if ((p[l].y >> m) & 1)
              {
                if (!f)
                  putchar(' ');

                printf("%d", s[m]);
                f = 0;
              }

            }

            goto END;
          }

        }

      }

      st = i;
    }

    printf("Impossible");
    END:
    new_puts("");

  }

  return 0;
}

int new_puts(const char *str);
void new_qsort(void *base, size_t num, size_t size, int (*compar)(const void *, const void *))
{
  int first_iteration;
  return qsort(base, num, size, compar);
}

int new_puts(const char *str)
{
  int first_iteration;
  return puts(str);
}


