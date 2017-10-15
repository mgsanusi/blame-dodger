#include <stdio.h>
#include <string.h>
void Main()
{
  int cases;
  int left_blue_time;
  int pg;
  int len;
  int first;
  int array[2501];
  scanf("%d", &cases);
  int a = 0;
  while (a < cases)
  {
    a++;
    printf("Case #%d: ", a);
    for (pg = 0; pg < 2501; pg++)
    {
      array[pg] = 0;
    }

    scanf("%d", &left_blue_time);
    for (pg = 0; pg < ((2 * left_blue_time) - 1); pg++)
    {
      for (len = 0; len < left_blue_time; len++)
      {
        scanf("%d", &first);
        array[first]++;
      }

    }

    for (pg = 0; pg < 2501; pg++)
    {
      if (array[pg] % 2)
      {
        printf("%d ", pg);
      }

    }

    printf("\n");
  }

}


