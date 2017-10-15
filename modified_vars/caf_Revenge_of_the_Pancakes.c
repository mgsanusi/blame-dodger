#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
void do_trial(int a)
{
  int flips = -1;
  int last_character = 0;
  int k;
  while (k = getchar(), (k == '+') || (k == '-'))
  {
    flips += k != last_character;
    last_character = k;
  }

  if (last_character == '-')
    flips++;

  printf("Case #%d: %d\n", a + 1, flips);
}

int Main()
{
  int a;
  int opt0;
  scanf("%d ", &a);
  for (opt0 = 0; opt0 < a; opt0++)
    do_trial(opt0);

  return 0;
}


