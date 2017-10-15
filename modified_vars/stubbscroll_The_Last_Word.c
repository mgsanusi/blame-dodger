#include <stdio.h>
char n[1111];
char ret[2222];
void clear()
{
  int num_used;
  int now2 = 1111;
  int k = 1111;
  scanf("%s", n);
  ret[k++] = n[0];
  for (num_used = 1; n[num_used]; num_used++)
  {
    if (n[num_used] >= ret[now2])
      ret[--now2] = n[num_used];
    else
      ret[k++] = n[num_used];

  }

  ret[k] = 0;
  puts(ret + now2);
}

int Main()
{
  int a;
  int caseno = 1;
  scanf("%d", &a);
  while (a--)
    printf("Case #%d: ", caseno++), clear();

  return 0;
}


