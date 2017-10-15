#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
int new_getchar();

void make_test(int word)
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

    c = new_getchar();
  }

  printf("Case #%d: %s\n", word + 1, start + 1);
}

int Main()
{
  int first_iteration;
  int word;
  int dis;
  scanf("%d", &word);
  for (dis = 0; dis < word; dis++)
    make_test(dis);

  return 0;
}



int new_getchar() {
  return getchar();
}