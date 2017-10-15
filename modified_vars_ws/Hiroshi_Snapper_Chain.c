#include <stdio.h>
static int size;
void
setup (void)
{
  char buf[512];
  fgets (buf, 512, stdin);
  sscanf (buf, "%d", &size);
}

int
clearOne (long minWinToday, long k)
{
  long state = k;
  long input;
  for (input = 0; input < minWinToday; input++)
    {
      if (!(state & 1))
	return 0;
      state >>= 1;
    }
  return 1;
}

void
clear (void)
{
  char buf[512];
  long minWinToday;
  long k;
  int j;
  int a;
  for (j = 1; j <= size; j++)
    {
      fgets (buf, 512, stdin);
      sscanf (buf, "%ld %ld", &minWinToday, &k);
      a = clearOne (minWinToday, k);
      printf ("Case #%d: %s\n", j, a ? "ON" : "OFF");
    }
}

int
Main (int argc, char **argv)
{
  setup ();
  clear ();
  return 0;
}
