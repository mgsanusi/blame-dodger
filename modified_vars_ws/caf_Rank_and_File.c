#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
void
make_screen (int a)
{
  char buffer[4000] = { 0 };
  char *start = &buffer[1999];
  char *goal = &buffer[1999];
  int c;
  do
    {
      c = getchar ();
    }
  while (c == '\n');
  do
    {
      *start = c;
      if (strcmp (start, start + 1) < 0)
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
      c = getchar ();
    }
  while (c != '\n');
  printf ("Case #%d: %s\n", a + 1, start + 1);
}

int
Main ()
{
  int a;
  int i;
  scanf ("%d", &a);
  for (i = 0; i < a; i++)
    make_screen (i);
  return 0;
}
