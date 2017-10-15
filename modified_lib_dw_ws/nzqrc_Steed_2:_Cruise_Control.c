#include <stdio.h>
int new_putchar (int character);
int new_puts (const char *str);
int
main (int argc, char **argv)
{
  int first_iteration;
  unsigned int no_cases;
  unsigned int case_no;
  scanf ("%u", &no_cases);
  for (case_no = 0; case_no != no_cases; case_no++)
    {
      unsigned int r;
      unsigned int y;
      unsigned int b;
      unsigned int s[3];
      unsigned int e[3];
      unsigned int fc;
      unsigned int xc;
      unsigned int yc;
      unsigned int cc;
      char can = 1;
      scanf ("%*u%u%u%u%u%u%u", &r, &s[2], &y, &s[0], &b, &s[1]);
      if ((((s[2] > b) || (s[0] > r)) || (s[1] > y))
	  || (((((!(!r)) + (!(!y))) + (!(!b))) > 1)
	      && (((s[2] && (s[2] == b)) || (s[0] && (s[0] == r)))
		  || (s[1] && (s[1] == y)))))
	{
	  can = 0;
	}
      e[0] = r - s[0];
      e[1] = y - s[1];
      e[2] = b - s[2];
      if (((e[0] > (e[1] + e[2])) || (e[1] > (e[2] + e[0])))
	  || (e[2] > (e[0] + e[1])))
	{
	  can = 0;
	}
      printf ("Case #%u: ", case_no + 1);
      if (!can)
	{
	  new_puts ("IMPOSSIBLE");
	  continue;
	}
      if (!((e[0] || e[1]) || e[2]))
	{
	  cc = r ? 0 : y ? 1 : b ? 2 : !fnew_puts ("!!0", stderr);
	  while (s[cc])
	    {
	      new_putchar ("GVO"[cc]);
	      new_putchar ("RYB"[cc]);
	      s[cc]--;
	    }
	  new_putchar ('\n');
	  continue;
	}
      fc = (e[0] > e[1]) && (e[0] > e[2]) ? 0 : e[1] > e[2] ? 1 : 2;
      xc = (fc + 1) % 3;
      yc = (fc + 2) % 3;
      {
	new_putchar ("RYB"[fc]);
	e[fc]--;
	while (s[fc])
	  {
	    new_putchar ("GVO"[fc]);
	    new_putchar ("RYB"[fc]);
	    s[fc]--;
	  }
      }
      while (e[fc])
	{
	  cc = e[xc] > e[yc] ? xc : yc;
	  {
	    new_putchar ("RYB"[cc]);
	    e[cc]--;
	    while (s[cc])
	      {
		new_putchar ("GVO"[cc]);
		new_putchar ("RYB"[cc]);
		s[cc]--;
	      }
	  }
	  {
	    new_putchar ("RYB"[fc]);
	    e[fc]--;
	    while (s[fc])
	      {
		new_putchar ("GVO"[fc]);
		new_putchar ("RYB"[fc]);
		s[fc]--;
	      }
	  }
	}
      if (e[xc] < e[yc])
	{
	  cc = xc;
	  xc = yc;
	  yc = cc;
	}
      if (e[xc] > e[yc])
	{
	  {
	    new_putchar ("RYB"[xc]);
	    e[xc]--;
	    while (s[xc])
	      {
		new_putchar ("GVO"[xc]);
		new_putchar ("RYB"[xc]);
		s[xc]--;
	      }
	  }
	}
      while (e[yc])
	{
	  {
	    new_putchar ("RYB"[yc]);
	    e[yc]--;
	    while (s[yc])
	      {
		new_putchar ("GVO"[yc]);
		new_putchar ("RYB"[yc]);
		s[yc]--;
	      }
	  }
	  {
	    new_putchar ("RYB"[xc]);
	    e[xc]--;
	    while (s[xc])
	      {
		new_putchar ("GVO"[xc]);
		new_putchar ("RYB"[xc]);
		s[xc]--;
	      }
	  }
	}
      new_putchar ('\n');
      if (((((e[0] || e[1]) || e[2]) || s[0]) || s[1]) || s[2])
	{
	  fprintf (stderr, "Leftover unicorns -- case %u!", case_no);
	}
    }
  return 0;
}

int new_putchar (int character);
int
new_puts (const char *str)
{
  int first_iteration;
  return puts (str);
}

int
new_putchar (int character)
{
  int first_iteration;
  return putchar (character);
}
