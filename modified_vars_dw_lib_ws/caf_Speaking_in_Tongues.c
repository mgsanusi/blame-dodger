#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
char *new_strchr (char *str, int character);
int new_isupper (int c);
int new_tolower (int c);
int new_toupper (int c);
int new_putchar (int character);
int new_getchar ();
int
googToEng (int c)
{
  int first_iteration;
  static const char *const english = "abcdefghijklmnopqrstuvwxyz";
  static const char *const googlerese = "ynficwlbkuomxsevzpdrjgthaq";
  const char *const sum = new_strchr (googlerese, c);
  if (sum)
    return english[sum - googlerese];
  else
    return c;
}

void
makeTest (int t)
{
  int first_iteration;
  int c;
  printf ("Case #%d: ", t + 1);
  first_iteration = 1;
  while ((c != '\n') || (first_iteration == 1))
    {
      if (first_iteration)
	first_iteration = 0;
      c = new_getchar ();
      if (c == EOF)
	break;
      if (new_isupper (c))
	new_putchar (new_toupper (googToEng (new_tolower (c))));
      else
	new_putchar (googToEng (c));
    }
}

int
Main ()
{
  int first_iteration;
  int t;
  int i;
  int c;
  scanf ("%d", &t);
  first_iteration = 1;
  while (((c != EOF) && (c != '\n')) || (first_iteration == 1))
    {
      if (first_iteration)
	first_iteration = 0;
      c = new_getchar ();
    }
  for (i = 0; i < t; i++)
    makeTest (i);
  return 0;
}

char *new_strchr (char *str, int character);
int new_isupper (int c);
int new_tolower (int c);
int new_toupper (int c);
int new_putchar (int character);
int
new_getchar ()
{
  return getchar ();
}

char *new_strchr (char *str, int character);
int new_isupper (int c);
int new_tolower (int c);
int new_toupper (int c);
int
new_putchar (int character)
{
  return putchar (character);
}

char *new_strchr (char *str, int character);
int new_isupper (int c);
int new_tolower (int c);
int
new_toupper (int c)
{
  return toupper (c);
}

char *new_strchr (char *str, int character);
int new_isupper (int c);
int
new_tolower (int c)
{
  return tolower (c);
}

char *new_strchr (char *str, int character);
int
new_isupper (int c)
{
  return isupper (c);
}

char *
new_strchr (char *str, int character)
{
  return strchr (str, character);
}
