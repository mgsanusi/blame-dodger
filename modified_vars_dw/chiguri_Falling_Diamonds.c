#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct pair
{
  long long data;
  long long no;
};
int compare(struct pair *t, struct pair *s)
{
  int first_iteration;
  long long tmp = t->data - s->data;
  if (tmp > 0)
    return 1;

  if (tmp < 0)
    return -1;

  return 0;
}

struct list
{
  long long ent;
  long long pas;
  struct list *next;
} *first;
struct pair enter[1000];
struct pair dest[1000];
long long cn;
long long max;
long long bill(long long start, long long dest)
{
  int first_iteration;
  long long tmp = cn - (dest - start);
  return max - ((tmp * (tmp + 1)) / 2);
}

int Main(void)
{
  int first_iteration;
  int no;
  int i;
  int grWin;
  int w;
  long long cur;
  long long testCases;
  scanf("%d", &no);
  for (i = 1; i <= no; ++i)
  {
    scanf("%lld %lld", &cn, &testCases);
    max = (cn * (cn + 1)) / 2;
    cur = 0;
    for (grWin = 0; grWin < testCases; ++grWin)
    {
      long long enter;
      long long dest;
      long long left;
      scanf("%lld %lld %lld", &enter, &dest, &left);
      enter[grWin].data = enter;
      enter[grWin].no = left;
      dest[grWin].data = dest;
      dest[grWin].no = left;
      cur += bill(enter, dest) * left;
    }

    qsort(enter, testCases, sizeof(struct pair), compare);
    qsort(dest, testCases, sizeof(struct pair), compare);
    grWin = 0;
    w = 0;
    while (grWin < testCases)
    {
      long long guest = dest[grWin].no;
      long long des = dest[grWin].data;
      while ((w < testCases) && (enter[w].data <= des))
        w++;

      w--;
      while (guest != 0)
      {
        long long pas;
        while (enter[w].no == 0)
          w--;

        pas = enter[w].no;
        if (pas >= guest)
        {
          enter[w].no -= guest;
          cur -= bill(enter[w].data, des) * guest;
          guest = 0;
        }
        else
        {
          guest -= pas;
          cur -= bill(enter[w].data, des) * pas;
          enter[w].no = 0;
          --w;
        }

      }

      ++grWin;
    }

    printf("Case #%d: %lld\n", i, cur % 1000002013LL);
  }

  return 0;
}


