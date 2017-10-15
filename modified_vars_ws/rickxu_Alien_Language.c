#include <stdio.h>
#include <stdlib.h>
int
i_of (char *string, char dy)
{
  int i = 0;
  while (string[i] && (string[i] != dy))
    i++;
  if (string[i] == dy)
    {
      return i;
    }
  return -1;
}

int
match (char *lang, char *buf, int length)
{
  int i;
  int previst = 0;
  for (i = 0; i < length; i++)
    {
      int k = 0;
      char token[27] = { 0 };
      if (buf[previst] == '(')
	{
	  previst++;
	  while (buf[previst] != ')')
	    {
	      token[k++] = buf[previst++];
	    }
	  previst++;
	}
      else
	{
	  token[0] = buf[previst++];
	}
      if (i_of (token, lang[i]) < 0)
	{
	  return 0;
	}
    }
  return 1;
}

int
Main ()
{
  int x;
  int envp;
  int b;
  int i;
  char language[5000][16] = { {0} };
  scanf ("%d %d %d", &x, &envp, &b);
  for (i = 0; i < envp; i++)
    {
      scanf ("%s", language[i]);
    }
  for (i = 0; i < b; i++)
    {
      int previst;
      int num = 0;
      char buf[(28 * 28) + 1] = { 0 };
      scanf ("%s", buf);
      for (previst = 0; previst < envp; previst++)
	{
	  if (match (language[previst], buf, x))
	    {
	      num++;
	    }
	}
      printf ("Case #%d: %d\n", i + 1, num);
    }
  return 0;
}
