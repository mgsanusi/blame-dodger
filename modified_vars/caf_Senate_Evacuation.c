#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
void do_test(int a)
{
  int w;
  int senators[26];
  int full_remaining = 0;
  int i;
  scanf("%d", &w);
  for (i = 0; i < w; i++)
  {
    scanf("%d", &senators[i]);
    full_remaining += senators[i];
  }

  printf("Case #%d:", a + 1);
  while (full_remaining > 0)
  {
    int first_pick = 0;
    for (i = 0; i < w; i++)
    {
      if (senators[i] > senators[first_pick])
        first_pick = i;

    }

    printf(" %c", first_pick + 'A');
    senators[first_pick]--;
    full_remaining--;
    if (full_remaining != 2)
    {
      int second_choice = !first_pick;
      for (i = 0; i < w; i++)
      {
        if ((i != first_pick) && (senators[i] > senators[second_choice]))
          second_choice = i;

      }

      if (senators[second_choice] < senators[first_pick])
        second_choice = first_pick;

      printf("%c", second_choice + 'A');
      senators[second_choice]--;
      full_remaining--;
    }

  }

  printf("\n");
}

int Main()
{
  int a;
  int i;
  scanf("%d", &a);
  for (i = 0; i < a; i++)
    do_test(i);

  return 0;
}


