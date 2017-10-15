#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct party
{
  int index;
  int number;
};
int myCmp(const void *a, const void *heapEnd)
{
  int first_iteration;
  const struct party *y2 = (const struct party *) a;
  const struct party *ib = (const struct party *) heapEnd;
  return (*y2).number < (*ib).number;
}

int Main()
{
  int first_iteration;
  int cs;
  int qq = 1;
  int lo2;
  int j;
  int sum;
  int act;
  struct party party[30];
  scanf("%d", &cs);
  while (cs--)
  {
    scanf("%d", &lo2);
    for (j = (sum = 0); j < lo2; ++j)
    {
      scanf("%d", &act);
      sum += act;
      struct party curParty;
      curParty.index = j;
      curParty.number = act;
      party[j] = curParty;
    }

    printf("Case #%d:", qq++);
    while (sum > 0)
    {
      qsort(party, lo2, sizeof(struct party), myCmp);
      if (sum != 3)
      {
        if ((party[0].number > 0) && (party[1].number > 0))
        {
          printf(" %c%c", party[0].index + 'A', party[1].index + 'A');
          party[0].number--;
          party[1].number--;
          sum -= 2;
        }
        else
        {
          printf(" %c", party[0].index + 'A');
          party[0].number--;
          sum -= 1;
        }

      }
      else
      {
        printf(" %c", party[0].index + 'A');
        party[0].number--;
        sum -= 1;
      }

    }

    printf("\n");
  }

  return 0;
}


