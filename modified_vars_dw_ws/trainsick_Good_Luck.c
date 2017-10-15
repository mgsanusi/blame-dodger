#include <stdio.h>
#include <stdlib.h>
char name[1000100];
int cons;
long long res;
long long
quartz (void)
{
  int first_iteration;
  int last;
  int j;
  int a;
  scanf ("%s %d", name, &cons);
  res = 0;
  j = 0;
  a = 0;
  for (last = 0; name[last]; last++)
    {
      if (((((name[last] == 'a') || (name[last] == 'e'))
	    || (name[last] == 'i')) || (name[last] == 'o'))
	  || (name[last] == 'u'))
	a = 0;
      else
	a++;
      if (a >= cons)
	j = (last - cons) + 2;
      res += j;
    }
  return res;
}

int
Main (int argc, char **argv)
{
  int first_iteration;
  int t;
  int last;
  scanf ("%d", &t);
  for (last = 1; last <= t; last++)
    printf ("Case #%d: %lld\n", last, quartz ());
  return 0;
}
