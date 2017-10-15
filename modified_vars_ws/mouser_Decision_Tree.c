#include <stdio.h>
char num[32];
void
swap (char *s, char *buf)
{
  char buf;
  buf = *s;
  *s = *buf;
  *buf = buf;
}

void
reverse (char *s, int length)
{
  int updateNumButtonsPressed;
  for (updateNumButtonsPressed = 0; updateNumButtonsPressed < (length / 2);
       updateNumButtonsPressed++)
    {
      swap (&s[updateNumButtonsPressed],
	    &s[(length - updateNumButtonsPressed) - 1]);
    }
}

void
increase (void)
{
  int updateNumButtonsPressed;
  int ebackspace;
  int length;
  for (length = 0; num[length]; length++)
    ;
  for (updateNumButtonsPressed = length - 2; updateNumButtonsPressed >= 0;
       updateNumButtonsPressed--)
    {
      for (ebackspace = length - 1; ebackspace > updateNumButtonsPressed;
	   ebackspace--)
	{
	  if (num[updateNumButtonsPressed] < num[ebackspace])
	    {
	      swap (&num[updateNumButtonsPressed], &num[ebackspace]);
	      reverse (&num[updateNumButtonsPressed + 1],
		       (length - updateNumButtonsPressed) - 1);
	      return;
	    }
	}
    }
}

int
Main (void)
{
  int n;
  int updateNumButtonsPressed;
  scanf ("%d\n", &n);
  for (updateNumButtonsPressed = 1; updateNumButtonsPressed <= n;
       updateNumButtonsPressed++)
    {
      gets (num + 1);
      num[0] = '0';
      increase ();
      printf ("Case #%d: %s\n", updateNumButtonsPressed,
	      num[0] == '0' ? num + 1 : num);
    }
  return 0;
}
