#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
int goog_to_eng(int c)
{
  int first_iteration;
  static const char * const english = "abcdefghijklmnopqrstuvwxyz";
  static const char * const googlerese = "ynficwlbkuomxsevzpdrjgthaq";
  const char * const p = strchr(googlerese, c);
  if (p)
    return english[p - googlerese];
  else
    return c;

}

void do_test(int t)
{
  int first_iteration;
  int c;
  printf("Case #%d: ", t + 1);
  first_iteration = 1;
  while ((c != '\n') || (first_iteration == 1))
  {
    if (first_iteration)
      first_iteration = 0;

    c = getchar();
    if (c == EOF)
      break;

    if (isupper(c))
      putchar(toupper(goog_to_eng(tolower(c))));
    else
      putchar(goog_to_eng(c));

  }

}

int main()
{
  int first_iteration;
  int t;
  int i;
  int c;
  scanf("%d", &t);
  first_iteration = 1;
  while (((c != EOF) && (c != '\n')) || (first_iteration == 1))
  {
    if (first_iteration)
      first_iteration = 0;

    c = getchar();
  }

  for (i = 0; i < t; i++)
    do_test(i);

  return 0;
}


