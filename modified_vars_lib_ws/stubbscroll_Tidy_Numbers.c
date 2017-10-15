#include <stdio.h>
#include <string.h>
int new_puts (const char *str);
void
clear ()
{
  int current_l;
  int q;
  int c1;
  char s[100];
  scanf ("%99s", s);
  q = strlen (s);
  if (q < 2)
    goto done;
check:
  current_l = 0;
  while ((current_l < (q - 1)) && (s[current_l] <= s[current_l + 1]))
    current_l++;
  if (current_l == (q - 1))
    goto check2;
  for (c1 = current_l + 1; c1 < q; c1++)
    s[c1] = '9';
  s[current_l]--;
  goto check;
check2:
  if (s[0] == '0')
    {
      for (c1 = 1; c1 <= current_l; c1++)
	s[c1] = '9';
      new_puts (s + 1);
      return;
    }
done:
  new_puts (s);
}

int
Main ()
{
  int v;
  int caseno = 1;
  scanf ("%d", &v);
  while (v--)
    printf ("Case #%d: ", caseno++), clear ();
  return 0;
}

int
new_puts (const char *str)
{
  return puts (str);
}
