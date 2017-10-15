#include<stdio.h>
typedef unsigned u;
u b[777];
int Main()
{
  int first_iteration;
  u t = 0;
  u p;
  u i;
  u rad;
  u k;
  u q;
  u sum;
  u x;
  for (scanf("%u", &p); (t++) < p;)
  {
    scanf("%u%u", &q, &sum);
    for (x = 0; q--; b[i]++)
      scanf("%u", &i);

    for (i = sum; i;)
    {
      if (!b[i])
      {
        i--;
        continue;
      }

      x++;
      b[i]--;
      rad = sum - i;
      if (rad > i)
        rad = i;

      while (rad && (!b[rad]))
        rad--;

      if (rad)
        b[rad]--;

    }

    printf("Case #%u: %u\n", t, x);
  }

  return 0;
}


