#include <stdio.h>
int Main()
{
  int score;
  int k;
  int x;
  int elapsed;
  int base;
  int c;
  scanf("%d", &k);
  for (score = 1; score <= k; score++)
  {
    scanf("%d %d %d", &x, &elapsed, &base);
    if (x == 1)
      c = 1;

    if (x == 2)
      c = !((elapsed & base) & 1);

    if (x == 3)
      c = (((elapsed % 3) == 0) || ((base % 3) == 0)) && ((base > 1) && (elapsed > 1));

    if (x == 4)
    {
      if (elapsed < base)
        elapsed ^= base, base ^= elapsed, elapsed ^= base;

      if (elapsed < 4)
        c = 0;
      else
        if (base < 3)
        c = 0;
      else
        c = 1;


    }

    printf("Case #%d: %s\n", score, c ? "GABRIEL" : "RICHARD");
  }

  return 0;
}


