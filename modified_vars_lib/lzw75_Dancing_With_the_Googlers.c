#include <stdio.h>
#include <stdlib.h>
int check_bound(int mark, int bound)
{
  if (((mark + 2) / 3) >= bound)
    return 2;
  else
    if (((mark >= 2) && (mark <= 28)) && (((mark + 4) / 3) >= bound))
    return 1;
  else
    return 0;


}

int Main()
{
  int no_case;
  int num_score;
  int num_surp;
  int bound;
  int pg;
  int mark;
  int base;
  int z;
  scanf("%d", &no_case);
  for (pg = 0; pg < no_case; pg++)
  {
    int potential = 0;
    int num = 0;
    scanf("%d %d %d", &num_score, &num_surp, &bound);
    for (base = 0; base < num_score; base++)
    {
      scanf("%d", &mark);
      z = check_bound(mark, bound);
      if (z == 2)
        num++;
      else
        if (z == 1)
        potential++;


    }

    if (potential > num_surp)
      potential = num_surp;

    printf("Case #%d: %d\n", pg + 1, num + potential);
  }

  return 0;
}


