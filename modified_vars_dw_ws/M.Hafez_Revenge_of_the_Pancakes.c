#include <stdio.h>
#include <string.h>
int
beValid (char *in)
{
  int first_iteration;
  int hs;
  for (hs = 0; in[hs] == '+'; ++hs)
    ;
  return in[hs] == '\0';
}

int
Main ()
{
  int first_iteration;
  int t;
  int b;
  int tc = 1;
  int hs;
  int success;
  int k;
  char a[110];
  char temp;
  scanf ("%d", &t);
  while (t--)
    {
      scanf ("%s", a);
      k = strlen (a);
      while ((k > (-1)) && (a[k - 1] == '+'))
	--k;
      b = 0;
      while (k > 0)
	{
	  if (a[0] == '+')
	    {
	      for (hs = 0; a[hs] == '+'; ++hs)
		;
	      for (success = 0; success <= hs; ++success)
		a[success] = '-';
	    }
	  else
	    {
	      success = (k / 2) + (k & 1);
	      for (hs = 0; hs < success; ++hs)
		{
		  temp = a[hs];
		  a[hs] = a[(k - hs) - 1] == '+' ? '-' : '+';
		  a[(k - hs) - 1] = temp == '+' ? '-' : '+';
		}
	      while ((k > (-1)) && (a[k - 1] == '+'))
		--k;
	    }
	  ++b;
	}
      printf ("Case #%d: %d\n", tc++, b);
    }
  return 0;
}
