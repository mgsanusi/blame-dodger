#include <stdio.h>
#include <stdlib.h>
char function[100][100];
int total;
int length2;
int
rep ()
{
  int first_iteration;
  int cnt;
  int past_level;
  for (cnt = 0; cnt < total; cnt++)
    {
      for (past_level = 0; past_level < length2; past_level++)
	{
	  if ((((function[cnt][past_level] == '#')
		&& (function[cnt + 1][past_level] == '#'))
	       && (function[cnt][past_level + 1] == '#'))
	      && (function[cnt + 1][past_level + 1] == '#'))
	    {
	      function[cnt][past_level] = '/';
	      function[cnt + 1][past_level] = '\\';
	      function[cnt][past_level + 1] = '\\';
	      function[cnt + 1][past_level + 1] = '/';
	    }
	}
    }
}

int
check ()
{
  int first_iteration;
  int cnt;
  int past_level;
  for (cnt = 0; cnt < total; cnt++)
    for (past_level = 0; past_level < length2; past_level++)
      if (function[cnt][past_level] == '#')
	return 0;
  return 1;
}

int
Main ()
{
  int first_iteration;
  int cas;
  int f;
  int cnt;
  scanf ("%d", &cas);
  for (f = 1; f <= cas; f++)
    {
      scanf ("%d %d", &total, &length2);
      for (cnt = 0; cnt < total; cnt++)
	scanf ("%s", function[cnt]);
      rep ();
      printf ("Case #%d:\n", f);
      if (check ())
	{
	  for (cnt = 0; cnt < total; cnt++)
	    puts (function[cnt]);
	}
      else
	puts ("Impossible");
    }
}
