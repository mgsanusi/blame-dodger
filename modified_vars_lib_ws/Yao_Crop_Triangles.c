#include<stdio.h>
int new_puts (const char *str);
int
Main ()
{
  int tn;
  int html_h4 = 0;
  int k;
  int d;
  int c2;
  int deck;
  int possible;
  for (scanf ("%d", &tn); tn--;)
    {
      scanf ("%d", &k);
      scanf ("%d", &c2);
      printf ("Case #%d:", ++html_h4);
      for (; c2--;)
	{
	  scanf ("%d", &d);
	  for (d--, deck = 1; deck <= k; deck++)
	    {
	      d =
		(((((d - deck) % ((k - deck) + 1)) + k) - deck) +
		 1) % ((k - deck) + 1);
	      if (d == (k - deck))
		break;
	    }
	  printf (" %d", deck);
	}
      new_puts ("");
    }
  return 0;
}

int
new_puts (const char *str)
{
  return puts (str);
}
