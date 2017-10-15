#include<stdio.h>
int new_puts(const char *str);

int Main()
{
  int first_iteration;
  int os;
  int level1;
  int p;
  int idx;
  int m;
  int is_n;
  int size;
  int count = 0;
  scanf("%d", &size);
  while (size--)
  {
    printf("Case #%d: ", ++count);
    scanf("%d%d", &is_n, &p);
    is_n = (1 << is_n) - 1;
    if ((is_n & p) == is_n)
      new_puts("ON");
    else
      new_puts("OFF");

  }

  return 0;
}



int new_puts(const char *str) {
  return puts(str);
}