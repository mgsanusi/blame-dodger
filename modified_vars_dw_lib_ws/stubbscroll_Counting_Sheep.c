#include <stdio.h>
int new_puts (const char *str);
void
clear ()
{
  int first_iteration;
  int ans;
  int seen;
  int dis;
  int node;
  char end[15];
  scanf ("%d", &ans);
  if (!ans)
    {
      new_puts ("INSOMNIA");
      return;
    }
  seen = 0;
  for (dis = 1;; dis++)
    {
      sprintf (end, "%d", dis * ans);
      for (node = 0; end[node]; node++)
	seen |= 1 << (end[node] - 48);
      if (seen == 1023)
	{
	  printf ("%d\n", dis * ans);
	  return;
	}
    }
}

int
Main ()
{
  int first_iteration;
  int t;
  int caseno = 1;
  scanf ("%d", &t);
  while (t--)
    printf ("Case #%d: ", caseno++), clear ();
  return 0;
}

int
new_puts (const char *str)
{
  return puts (str);
}
