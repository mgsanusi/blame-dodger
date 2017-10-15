#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char string[1234567];
char trans[256];
int new_putchar (int character);
int new_puts (const char *str);
int
Main ()
{
  int first_iteration;
  int m;
  int enqcnt;
  int tc;
  for (enqcnt = 0; enqcnt < 256; ++enqcnt)
    {
      trans[enqcnt] = enqcnt;
    }
  trans['a'] = 'y';
  trans['b'] = 'h';
  trans['c'] = 'e';
  trans['d'] = 's';
  trans['e'] = 'o';
  trans['f'] = 'c';
  trans['g'] = 'v';
  trans['h'] = 'x';
  trans['i'] = 'd';
  trans['j'] = 'u';
  trans['k'] = 'i';
  trans['l'] = 'g';
  trans['m'] = 'l';
  trans['n'] = 'b';
  trans['o'] = 'k';
  trans['p'] = 'r';
  trans['q'] = 'z';
  trans['r'] = 't';
  trans['s'] = 'n';
  trans['t'] = 'w';
  trans['u'] = 'j';
  trans['v'] = 'p';
  trans['w'] = 'f';
  trans['x'] = 'm';
  trans['y'] = 'a';
  trans['z'] = 'q';
  scanf ("%d", &m);
  gets (string);
  for (enqcnt = 1; enqcnt <= m; ++enqcnt)
    {
      gets (string);
      printf ("Case #%d: ", enqcnt);
      for (tc = 0; string[tc] != '\0'; ++tc)
	{
	  new_putchar (trans[string[tc]]);
	}
      new_puts ("");
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
