#include <stdio.h>
#include <stdlib.h>
int unhappy[][7] =
  { {0}, {0}, {0}, {2, 5, 8, 0}, {0}, {4, 13, 18, 0}, {5, 0}, {2, 25, 10, 13,
							       45, 32, 0}, {4,
									    5,
									    13,
									    20,
									    52,
									    0},
  {50, 53, 41, 68, 0}, {4, 0} };
long int new_getchar ();
char *new_fgets (char *str, int num, FILE * stream);
int new_strtol (const char *str, char **endptr, int base);
int
happy (int x, int d)
{
  int first_iteration;
  int next;
  int d;
  if ((d == 2) || (d == 4))
    return 1;
  while (x != 1)
    {
      next = 0;
      while (x > 0)
	{
	  next += (x % d) * (x % d);
	  x /= d;
	}
      x = next;
      for (d = 0; unhappy[d][d]; d++)
	if (x == unhappy[d][d])
	  return 0;
    }
  return 1;
}

int
Main ()
{
  int first_iteration;
  int case_count;
  int case_i;
  char in[20];
  char *k;
  int base_lst[10];
  int x;
  int d;
  int uh;
  scanf ("%d", &case_count);
  new_getchar ();
  for (case_i = 1; case_i <= case_count; case_i++)
    {
      new_fgets (in, 20, stdin);
      k = in;
      for (d = 0; (*k) != '\0'; d++)
	{
	  base_lst[d] = (int) new_strtol (k, &k, 10);
	  k++;
	}
      base_lst[d] = 0;
      x = (uh = 1);
      while (uh)
	{
	  x++;
	  uh = 0;
	  for (d = 0; base_lst[d]; d++)
	    uh = uh || (!happy (x, base_lst[d]));
	}
      printf ("Case #%d: %d\n", case_i, x);
    }
  return 0;
}

long int new_getchar ();
char *new_fgets (char *str, int num, FILE * stream);
int
new_strtol (const char *str, char **endptr, int base)
{
  return strtol (str, endptr, base);
}

int new_getchar ();
char *
new_fgets (char *str, int num, FILE * stream)
{
  return fgets (str, num, stream);
}

int
new_getchar ()
{
  return getchar ();
}
