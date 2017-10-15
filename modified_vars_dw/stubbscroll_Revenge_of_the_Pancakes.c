#include <stdio.h>
#include <string.h>
void clear()
{
  int first_iteration;
  int d;
  int x = 0;
  char m[111];
  char last = '+';
  scanf("%s", m);
  for (d = strlen(m) - 1; d >= 0; d--)
    if (m[d] != last)
    last = m[d], x++;


  printf("%d\n", x);
}

int Main()
{
  int first_iteration;
  int c;
  int caseno = 1;
  scanf("%d", &c);
  while (c--)
    printf("Case #%d: ", caseno++), clear();

  return 0;
}


