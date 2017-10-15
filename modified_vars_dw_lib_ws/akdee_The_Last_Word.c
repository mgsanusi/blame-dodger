#include <stdio.h>
int
Main ()
{
  int first_iteration;
  int cases;
  scanf ("%d", &cases);
  for (int s = 1; s <= cases; s++)
    {
      char string[1001];
      scanf (" %s\n", string);
      int top = 0;
      while (string[top])
	top++;
      for (int bot = 0; bot < top; bot++)
	{
	  for (int t2 = top; t2 >= bot; t2--)
	    if (string[top] < string[t2])
	      top = t2;
	  char t = string[top];
	  for (int t2 = top; t2 > bot; t2--)
	    string[t2] = string[t2 - 1];
	  string[bot] = t;
	}
      printf ("Case #%d: %s\n", s, string);
    }
}
