#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
void do_test(int t)
{
  int first_iteration;
  int n;
  int i;
  int heights[5000] = {0};
  scanf("%d", &n);
  for (i = 0; i < (((2 * n) - 1) * n); i++)
  {
    int h;
    scanf("%d", &h);
    heights[h] ^= 1;
  }

  printf("Case #%d:", t + 1);
  for (i = 0; i < 5000; i++)
    if (heights[i])
    printf(" %d", i);


  printf("\n");
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


