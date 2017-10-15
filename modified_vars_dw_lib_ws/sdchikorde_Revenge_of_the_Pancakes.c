#include <stdio.h>
#include <string.h>
#include <malloc.h>
void
Main ()
{
  int first_iteration;
  int cases;
  scanf ("%d", &cases);
  int d = 0;
  int len;
  char *string = (char *) malloc ((sizeof (char)) * 102);
  char *tmp;
  int result;
  while (d < cases)
    {
      result = 0;
      d++;
      printf ("Case #%d: ", d);
      scanf ("%s", string);
      len = (int) strlen (string);
      tmp = &string[len - 1];
      if ((*tmp) == '-')
	{
	  result++;
	}
      while (tmp > string)
	{
	  tmp--;
	  if ((*tmp) != (*(tmp + 1)))
	    {
	      result++;
	    }
	}
      printf ("%d\n", result);
    }
}
