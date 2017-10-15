#include <stdio.h>
#include <stdlib.h>
typedef struct 
{
  int r;
  int cs;
} student;
int new_puts(const char *str);

void new_qsort(void* base, size_t num, size_t size, int (*compar)(const void*,const void*));

int cmp(const void *sum, const void *u)
{
  return ((student *) u)->r - ((student *) sum)->r;
}

int maximal(int sum, int u)
{
  if (sum > u)
  {
    return sum;
  }
  else
  {
    return u;
  }

}

int Main()
{
  int nb;
  int cs;
  int foo;
  int sum[1000][2];
  student num[1000];
  scanf("%d", &nb);
  for (cs = 0; cs < nb; cs++)
  {
    int c;
    int x;
    int l;
    int c;
    scanf("%d %d %d", &c, &x, &l);
    for (foo = 0; foo < c; foo++)
    {
      scanf("%d", &num[foo].r);
      num[foo].cs = foo;
      sum[foo][0] = (sum[foo][1] = -1);
    }

    new_qsort(num, c, sizeof(student), cmp);
    foo = 0;
    c = -num[0].r;
    while (1)
    {
      int now = -num[foo].r;
      int tmp = c;
      for (; foo < c; foo++)
      {
        if ((now + num[foo].r) > l)
        {
          c = tmp;
          break;
        }

        sum[num[foo].cs][0] = maximal(c + num[foo].r, 0);
        sum[num[foo].cs][1] = now + num[foo].r;
        tmp = maximal(tmp, c + (num[foo].r * 2));
        now = now + (num[foo].r * 2);
      }

      if (foo == c)
        break;

    }

    printf("Case #%d:", cs + 1);
    for (foo = 0; foo < c; foo++)
      printf(" %d %d", sum[foo][0], sum[foo][1]);

    new_puts("");
  }

  return 0;
}



int new_puts(const char *str);

void new_qsort(void* base, size_t num, size_t size, int (*compar)(const void*,const void*)) {
  return qsort(base, num, size, compar);
}
int new_puts(const char *str) {
  return puts(str);
}