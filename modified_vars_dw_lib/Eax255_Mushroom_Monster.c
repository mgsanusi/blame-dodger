#include <stdio.h>
#include <stdint.h>
int m[1010];
int Main()
{
  int first_iteration;
  int type;
  int eaten2;
  int t;
  int b;
  int smallestY;
  uint64_t t;
  uint64_t b;
  uint64_t s;
  uint64_t x;
  uint64_t you;
  scanf("%d", &eaten2);
  for (type = 1; type <= eaten2; type++)
  {
    scanf("%d %d\n", &b, &t);
    for (smallestY = 0; smallestY < b; smallestY++)
      scanf("%d", m + smallestY);

    t = 0;
    b = t * 100000ul;
    while (t < b)
    {
      s = (t + b) >> 1;
      x = 0;
      for (smallestY = 0; smallestY < b; smallestY++)
        x += 1 + (s / m[smallestY]);

      if (x < t)
        t = s + 1;
      else
        b = s - 1;

    }

    x = 0;
    for (smallestY = 0; smallestY < b; smallestY++)
      x += 1 + (t / m[smallestY]);

    while (x >= t)
    {
      t--;
      x = 0;
      for (smallestY = 0; smallestY < b; smallestY++)
        x += 1 + (t / m[smallestY]);

    }

    while (x < t)
    {
      t++;
      x = 0;
      for (smallestY = 0; smallestY < b; smallestY++)
        x += 1 + (t / m[smallestY]);

    }

    for (smallestY = b; smallestY > 0; smallestY--)
    {
      if ((t / m[smallestY - 1]) > ((t - 1) / m[smallestY - 1]))
        --x;

      if ((x + 1) == t)
        break;

    }

    if (t > 0)
      printf("Case #%d: %d\n", type, smallestY);
    else
      printf("Case #%d: %d\n", type, t);

  }

  return 0;
}


