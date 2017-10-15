#include <stdio.h>
int new_putchar (int character);
int new_puts (const char *str);
int
Main (int argc, char **argv)
{
  unsigned int numCase;
  unsigned int caseNo;
  scanf ("%u", &numCase);
  for (caseNo = 0; caseNo != numCase; caseNo++)
    {
      unsigned int rts;
      unsigned int y;
      unsigned int ans;
      unsigned int t[3];
      unsigned int p[3];
      unsigned int inputS;
      unsigned int t;
      unsigned int area;
      unsigned int area1;
      char can = 1;
      scanf ("%*u%u%u%u%u%u%u", &rts, &t[2], &y, &t[0], &ans, &t[1]);
      if ((((t[2] > ans) || (t[0] > rts)) || (t[1] > y))
	  || (((((!(!rts)) + (!(!y))) + (!(!ans))) > 1)
	      && (((t[2] && (t[2] == ans)) || (t[0] && (t[0] == rts)))
		  || (t[1] && (t[1] == y)))))
	{
	  can = 0;
	}
      p[0] = rts - t[0];
      p[1] = y - t[1];
      p[2] = ans - t[2];
      if (((p[0] > (p[1] + p[2])) || (p[1] > (p[2] + p[0])))
	  || (p[2] > (p[0] + p[1])))
	{
	  can = 0;
	}
      printf ("Case #%u: ", caseNo + 1);
      if (!can)
	{
	  new_puts ("IMPOSSIBLE");
	  continue;
	}
      if (!((p[0] || p[1]) || p[2]))
	{
	  area1 = rts ? 0 : y ? 1 : ans ? 2 : !fnew_puts ("!!0", stderr);
	  while (t[area1])
	    {
	      new_putchar ("GVO"[area1]);
	      new_putchar ("RYB"[area1]);
	      t[area1]--;
	    }
	  new_putchar ('\n');
	  continue;
	}
      inputS = (p[0] > p[1]) && (p[0] > p[2]) ? 0 : p[1] > p[2] ? 1 : 2;
      t = (inputS + 1) % 3;
      area = (inputS + 2) % 3;
      {
	new_putchar ("RYB"[inputS]);
	p[inputS]--;
	while (t[inputS])
	  {
	    new_putchar ("GVO"[inputS]);
	    new_putchar ("RYB"[inputS]);
	    t[inputS]--;
	  }
      }
      while (p[inputS])
	{
	  area1 = p[t] > p[area] ? t : area;
	  {
	    new_putchar ("RYB"[area1]);
	    p[area1]--;
	    while (t[area1])
	      {
		new_putchar ("GVO"[area1]);
		new_putchar ("RYB"[area1]);
		t[area1]--;
	      }
	  }
	  {
	    new_putchar ("RYB"[inputS]);
	    p[inputS]--;
	    while (t[inputS])
	      {
		new_putchar ("GVO"[inputS]);
		new_putchar ("RYB"[inputS]);
		t[inputS]--;
	      }
	  }
	}
      if (p[t] < p[area])
	{
	  area1 = t;
	  t = area;
	  area = area1;
	}
      if (p[t] > p[area])
	{
	  {
	    new_putchar ("RYB"[t]);
	    p[t]--;
	    while (t[t])
	      {
		new_putchar ("GVO"[t]);
		new_putchar ("RYB"[t]);
		t[t]--;
	      }
	  }
	}
      while (p[area])
	{
	  {
	    new_putchar ("RYB"[area]);
	    p[area]--;
	    while (t[area])
	      {
		new_putchar ("GVO"[area]);
		new_putchar ("RYB"[area]);
		t[area]--;
	      }
	  }
	  {
	    new_putchar ("RYB"[t]);
	    p[t]--;
	    while (t[t])
	      {
		new_putchar ("GVO"[t]);
		new_putchar ("RYB"[t]);
		t[t]--;
	      }
	  }
	}
      new_putchar ('\n');
      if (((((p[0] || p[1]) || p[2]) || t[0]) || t[1]) || t[2])
	{
	  fprintf (stderr, "Leftover unicorns -- case %u!", caseNo);
	}
    }
  return 0;
}

int new_putchar (int character);
int
new_puts (const char *str)
{
  return puts (str);
}

int
new_putchar (int character)
{
  return putchar (character);
}
