#include <stdio.h>
int
Main (void)
{
  int ar_stat;
  int node;
  int dy;
  int n;
  scanf ("%d", &dy);
  for (n = 1; n <= dy; n++)
    {
      char s[101];
      int result;
      scanf ("%s", s);
      result = 0;
      for (ar_stat = 0; s[ar_stat]; ar_stat = node)
	{
	  for (node = ar_stat + 1; s[ar_stat] == s[node]; node++)
	    ;
	  if (s[node])
	    result++;
	  else
	    result += s[ar_stat] == '-';
	}
      printf ("Case #%d: %d\n", n, result);
    }
  return 0;
}
