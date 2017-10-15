#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char ru[26] =
  { 'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k',
'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q' };
int
Main ()
{
  freopen ("out.txt", "w", stdout);
  freopen ("A-small-attempt0.in", "r", stdin);
  int k;
  int o;
  int no;
  char ins[120];
  char out[120];
  scanf ("%d%*c", &k);
  for (o = 1; o <= k; o++)
    {
      gets (ins);
      no = strlen (ins);
      out[no] = 0;
      while (no--)
	{
	  if (isalpha (ins[no]))
	    out[no] = ru[ins[no] - 'a'];
	  else
	    out[no] = ' ';
	}
      printf ("Case #%d: %s\n", o, out);
    }
  return 0;
}
