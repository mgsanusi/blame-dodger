#include <stdio.h>
#include <string.h>
#include <stdbool.h>
int Main()
{
  int t = 0;
  int t;
  int i;
  int n1;
  int length;
  int ar[2];
  int cs;
  int needX;
  scanf("%d", &t);
  while (t--)
  {
    ar[0] = (ar[1] = 0);
    for (length = 0; length < 2; length++)
    {
      scanf("%d", &needX);
      for (i = 1; i <= 4; i++)
      {
        for (n1 = 1; n1 <= 4; n1++)
        {
          scanf("%d", &cs);
          if (i == needX)
            ar[length] |= 1 << cs;

        }

      }

    }

    int bitmask = ar[0] & ar[1];
    if (__builtin_popcount(bitmask) == 1)
      printf("Case #%d: %d\n", ++t, __builtin_ctz(bitmask));
    else
      if (__builtin_popcount(bitmask) > 1)
      printf("Case #%d: Bad magician!\n", ++t);
    else
      printf("Case #%d: Volunteer cheated!\n", ++t);


  }

  return 0;
}


