#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
int
googToEng (int c)
{
  static const char *const english = "abcdefghijklmnopqrstuvwxyz";
  static const char *const googlerese = "ynficwlbkuomxsevzpdrjgthaq";
  const char *const sum = strchr (googlerese, c);
  if (sum)
    return english[sum - googlerese];
  else
    return c;
}

void
makeTest (int t)
{
  int c;
  printf ("Case #%d: ", t + 1);
  do
    {
      c = getchar ();
      if (c == EOF)
	break;
      if (isupper (c))
	putchar (toupper (googToEng (tolower (c))));
      else
	putchar (googToEng (c));
    }
  while (c != '\n');
}

int
Main ()
{
  int t;
  int i;
  int c;
  scanf ("%d", &t);
  do
    {
      c = getchar ();
    }
  while ((c != EOF) && (c != '\n'));
  for (i = 0; i < t; i++)
    makeTest (i);
  return 0;
}
