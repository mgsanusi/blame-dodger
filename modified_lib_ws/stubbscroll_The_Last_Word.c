#include <stdio.h>
 char s[1111], t[2222];
int new_puts (const char *str);
 void
solve ()
{
  int i, ts = 1111, te = 1111;
  scanf ("%s", s);
  t[te++] = s[0];
  for (i = 1; s[i]; i++)
    {
      if (s[i] >= t[ts])
	t[--ts] = s[i];
      
      else
	t[te++] = s[i];
    }
  t[te] = 0;
  new_puts (t + ts);
}

 int
main ()
{
  int T, caseno = 1;
  scanf ("%d", &T);
  while (T--)
    printf ("Case #%d: ", caseno++), solve ();
  return 0;
}

int
new_puts (const char *str)
{
  return puts (str);
}
