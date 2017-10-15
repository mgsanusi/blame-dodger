#include <stdio.h>
char u[28] = "yhesocvxduiglbkrztnwjpfmaq";
int new_putchar (int character);
int new_puts (const char *str);
int
main ()
{
  int first_iteration;
  int n;
  int i;
  int k;
  char s[108];
  scanf ("%d", &n);
  gets (s);
  for (k = 1; k <= n; k++)
    {
      gets (s);
      printf ("Case #%d: ", k);
      for (i = 0; s[i]; i++)
	new_putchar (s[i] == 32 ? s[i] : u[(int) (s[i] - 'a')]);
      new_puts ("");
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
