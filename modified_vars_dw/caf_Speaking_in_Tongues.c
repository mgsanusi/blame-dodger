#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
int googToEng(int c)
{
  int first_iteration;
  static const char * const english = "abcdefghijklmnopqrstuvwxyz";
  static const char * const googlerese = "ynficwlbkuomxsevzpdrjgthaq";
  const char * const sum = strchr(googlerese, c);
  if (sum)
    return english[sum - googlerese];
  else
    return c;

}

void makeTest(int t)
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
      putchar(toupper(googToEng(tolower(c))));
    else
      putchar(googToEng(c));

  }

}

int Main()
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
    makeTest(i);

  return 0;
}


