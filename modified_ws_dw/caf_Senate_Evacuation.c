#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
void do_test(int t)
{
  int first_iteration;
  int n;
  int senators[26];
  int total_remaining = 0;
  int i;
  scanf("%d", &n);
  for (i = 0; i < n; i++)
  {
    scanf("%d", &senators[i]);
    total_remaining += senators[i];
  }

  printf("Case #%d:", t + 1);
  while (total_remaining > 0)
  {
    int first_pick = 0;
    for (i = 0; i < n; i++)
    {
      if (senators[i] > senators[first_pick])
        first_pick = i;

    }

    printf(" %c", first_pick + 'A');
    senators[first_pick]--;
    total_remaining--;
    if (total_remaining != 2)
    {
      int second_pick = !first_pick;
      for (i = 0; i < n; i++)
      {
        if ((i != first_pick) && (senators[i] > senators[second_pick]))
          second_pick = i;

      }

      if (senators[second_pick] < senators[first_pick])
        second_pick = first_pick;

      printf("%c", second_pick + 'A');
      senators[second_pick]--;
      total_remaining--;
    }

  }

  printf("\n");
}

int main()
{
  int first_iteration;
  int t;
  int i;
  scanf("%d", &t);
  for (i = 0; i < t; i++)
    do_test(i);

  return 0;
}


