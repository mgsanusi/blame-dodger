#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
void
do_test (int t)
{
  int first_iteration;
  int b;
  int length;
  int height[5000] = { 0 };
  scanf ("%d", &b);
  for (length = 0; length < (((2 * b) - 1) * b); length++)
    {
      int h;
      scanf ("%d", &h);
      height[h] ^= 1;
    }
  printf ("Case #%d:", t + 1);
  for (length = 0; length < 5000; length++)
    if (height[length])
      printf (" %d", length);
  printf ("\n");
}

int
Main ()
{
  int first_iteration;
  int t;
  int length;
  scanf ("%d", &t);
  for (length = 0; length < t; length++)
    do_test (length);
  return 0;
}
