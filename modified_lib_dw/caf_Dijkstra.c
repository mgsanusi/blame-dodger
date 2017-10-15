#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
void do_test(int t)
{
  int first_iteration;
  long r;
  long c;
  long w;
  long score;
  scanf(" %ld %ld %ld", &r, &c, &w);
  score = ((r * (c / w)) + w) - ((c % w) == 0);
  printf("Case #%d: %ld\n", t + 1, score);
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


