#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
char *new_strchr(char *str, int character);
int new_isupper(int c);
int new_tolower(int c);
int new_toupper(int c);
int new_putchar(int character);
int new_getchar();
int goog_to_eng(int c)
{
  int first_iteration;
  static const char * const english = "abcdefghijklmnopqrstuvwxyz";
  static const char * const googlerese = "ynficwlbkuomxsevzpdrjgthaq";
  const char * const p = new_strchr(googlerese, c);
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

    c = new_getchar();
    if (c == EOF)
      break;

    if (new_isupper(c))
      new_putchar(new_toupper(goog_to_eng(new_tolower(c))));
    else
      new_putchar(goog_to_eng(c));

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

    c = new_getchar();
  }

  for (i = 0; i < t; i++)
    do_test(i);

  return 0;
}

char *new_strchr(char *str, int character);
int new_isupper(int c);
int new_tolower(int c);
int new_toupper(int c);
int new_putchar(int character);
int new_getchar()
{
  int first_iteration;
  return getchar();
}

char *new_strchr(char *str, int character);
int new_isupper(int c);
int new_tolower(int c);
int new_toupper(int c);
int new_putchar(int character)
{
  int first_iteration;
  return putchar(character);
}

char *new_strchr(char *str, int character);
int new_isupper(int c);
int new_tolower(int c);
int new_toupper(int c)
{
  int first_iteration;
  return toupper(c);
}

char *new_strchr(char *str, int character);
int new_isupper(int c);
int new_tolower(int c)
{
  int first_iteration;
  return tolower(c);
}

char *new_strchr(char *str, int character);
int new_isupper(int c)
{
  int first_iteration;
  return isupper(c);
}

char *new_strchr(char *str, int character)
{
  int first_iteration;
  return strchr(str, character);
}


