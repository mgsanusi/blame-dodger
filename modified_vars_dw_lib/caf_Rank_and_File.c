#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
int new_getchar();

void make_screen(int a)
{
  int first_iteration;
  char buffer[4000] = {0};
  char *start = &buffer[1999];
  char *goal = &buffer[1999];
  int c;
  first_iteration = 1;
  while ((c == '\n') || (first_iteration == 1))
  {
    if (first_iteration)
      first_iteration = 0;

    c = new_getchar();
  }

  first_iteration = 1;
  while ((c != '\n') || (first_iteration == 1))
  {
    if (first_iteration)
      first_iteration = 0;

    *start = c;
    if (strcmp(start, start + 1) < 0)
    {
      if (start == goal)
        start--;

      *(goal++) = c;
    }
    else
    {
      if (start == goal)
        goal++;

      start--;
    }

    c = new_getchar();
  }

  printf("Case #%d: %s\n", a + 1, start + 1);
}

int Main()
{
  int first_iteration;
  int a;
  int i;
  scanf("%d", &a);
  for (i = 0; i < a; i++)
    make_screen(i);

  return 0;
}



int new_getchar() {
  return getchar();
}