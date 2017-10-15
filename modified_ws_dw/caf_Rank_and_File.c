#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
void do_test(int t)
{
  int first_iteration;
  char buf[4000] = {0};
  char *start = &buf[1999];
  char *end = &buf[1999];
  int c;
  first_iteration = 1;
  while ((c == '\n') || (first_iteration == 1))
  {
    if (first_iteration)
      first_iteration = 0;

    c = getchar();
  }

  first_iteration = 1;
  while ((c != '\n') || (first_iteration == 1))
  {
    if (first_iteration)
      first_iteration = 0;

    *start = c;
    if (strcmp(start, start + 1) < 0)
    {
      if (start == end)
        start--;

      *(end++) = c;
    }
    else
    {
      if (start == end)
        end++;

      start--;
    }

    c = getchar();
  }

  printf("Case #%d: %s\n", t + 1, start + 1);
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


