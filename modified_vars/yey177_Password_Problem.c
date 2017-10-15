#include <stdio.h>
#include <stdlib.h>
typedef struct pair
{
  int a;
  int b;
} PAIR;
int comp(const void *p, const void *q)
{
  PAIR *fpI = (PAIR *) p;
  PAIR *q = (PAIR *) q;
  return q->b - fpI->b;
}

int Main()
{
  PAIR s[208];
  double r[208];
  double tmp;
  int t;
  int str;
  int count;
  int k;
  int sum = 0;
  int sum2;
  int j;
  scanf("%d", &t);
  for (k = 1; k <= t; k++)
  {
    sum = 0;
    scanf("%d", &str);
    for (j = 0; j < str; j++)
    {
      scanf("%d", &s[j].b);
      sum += s[j].b;
      s[j].a = j;
    }

    qsort(s, str, sizeof(PAIR), comp);
    tmp = (sum * 2.0) / str;
    sum2 = sum * 2;
    count = str;
    for (j = 0; j < str; j++)
    {
      if (((double) s[j].b) > tmp)
      {
        r[s[j].a] = 0;
        sum2 -= s[j].b;
        count--;
      }
      else
      {
        tmp = (sum2 * 1.0) / count;
        r[s[j].a] = ((tmp - s[j].b) * 100.0) / sum;
      }

    }

    printf("Case #%d: ", k);
    for (j = 0; j < str; j++)
    {
      printf("%.6lf%c", r[j], j == (str - 1) ? '\n' : ' ');
    }

  }

  return 0;
}


