#include <stdio.h>
#include <string.h>
#include <stdbool.h>
int main()
{
  int first_iteration;
  int T = 0;
  int t;
  int i;
  int j;
  int k;
  int ar[2];
  int z;
  int r;
  scanf("%d", &t);
  while (t--)
  {
    ar[0] = (ar[1] = 0);
    for (k = 0; k < 2; k++)
    {
      scanf("%d", &r);
      for (i = 1; i <= 4; i++)
      {
        for (j = 1; j <= 4; j++)
        {
          scanf("%d", &z);
          if (i == r)
            ar[k] |= 1 << z;

        }

      }

    }

    int bitmask = ar[0] & ar[1];
    if (__builtin_popcount(bitmask) == 1)
      printf("Case #%d: %d\n", ++T, __builtin_ctz(bitmask));
    else
      if (__builtin_popcount(bitmask) > 1)
      printf("Case #%d: Bad magician!\n", ++T);
    else
      printf("Case #%d: Volunteer cheated!\n", ++T);


  }

  return 0;
}


