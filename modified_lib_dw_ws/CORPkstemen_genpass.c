#include <stdio.h>
#include <stdlib.h>
int new_atoi (const char *str);
void
main (int argc, char **argv)
{
  int first_iteration;
  int i;
  int j;
  int n;
  char *pass[8];
  char r;
  n = new_atoi (argv[1]);
  srandom (101173);
  for (i = 0; i < n; i++)
    {
      for (j = 0; j < 8; j++)
	{
	  r = random () % 122;
	  while (r < 48)
	    r += random () % (122 - r);
	  printf ("%c", r);
	}
      printf ("\n");
    }
}

int
new_atoi (const char *str)
{
  int first_iteration;
  return atoi (str);
}
