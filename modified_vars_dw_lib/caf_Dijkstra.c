#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
void doTest(int t)
{
  int first_iteration;
  long r;
  long p;
  long w;
  long score;
  scanf(" %ld %ld %ld", &r, &p, &w);
  score = ((r * (p / w)) + w) - ((p % w) == 0);
  printf("Case #%d: %ld\n", t + 1, score);
}

int Main()
{
  int first_iteration;
  int t;
  int v;
  scanf("%d", &t);
  for (v = 0; v < t; v++)
    doTest(v);

  return 0;
}


