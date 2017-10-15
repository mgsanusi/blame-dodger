#include <stdio.h>
char map[] = "yhesocvxduiglbkrztnwjpfmaq";
int
Main ()
{
  int s;
  scanf ("%d ", &s);
  for (int t = 1; t <= s; t++)
    {
      char buf[101];
      gets (buf);
      for (int i = 0; buf[i]; i++)
	if ((buf[i] >= 'a') && (buf[i] <= 'z'))
	  buf[i] = map[buf[i] - 'a'];
      printf ("Case #%d: %s\n", t, buf);
    }
  return 0;
}
