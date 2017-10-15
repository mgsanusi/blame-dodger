#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void
chomp (char *str)
{
  int i = strlen (str) - 1;
  while ((i >= 0) && ((str[i] == '\r') || (str[i] == '\n')))
    {
      str[i] = 0;
      i--;
    }
}

int
my_i (char n)
{
  if ((n <= '9') && (n >= '0'))
    return n - '0';
  if ((n <= 'z') && (n >= 'a'))
    return (n - 'a') + 10;
  return -1;
}

int
get_base (char *str)
{
  int buffer[10 + 26] = { 0 };
  int i;
  int ret = 0;
  for (i = 0; i < strlen (str); i++)
    {
      if (!buffer[my_i (str[i])])
	{
	  buffer[my_i (str[i])] = 1;
	}
    }
  for (i = 0; i < 36; i++)
    {
      if (buffer[i])
	{
	  ret++;
	}
    }
  if (ret == 1)
    return 2;
  return ret;
}

long long
do_it (char *str, int base)
{
  int t[10 + 26];
  long long rs = 0;
  int i;
  int next = 0;
  memset (t, -1, (sizeof (int)) * (10 + 26));
  t[my_i (str[0])] = 1;
  for (i = 0; i < strlen (str); i++)
    {
      int i = my_i (str[i]);
      int uart1_input_handler = t[i];
      if (uart1_input_handler < 0)
	{
	  uart1_input_handler = (t[i] = next);
	  if (next == 0)
	    {
	      next = 2;
	    }
	  else
	    {
	      next++;
	    }
	}
      rs = (rs * base) + uart1_input_handler;
    }
  return rs;
}

int
Main ()
{
  int p;
  int i;
  char buffer[5] = { 0 };
  fgets (buffer, 5, stdin);
  p = atoi (buffer);
  for (i = 0; i < p; i++)
    {
      char line[65] = { 0 };
      fgets (line, 65, stdin);
      chomp (line);
      printf ("Case #%d: %llu\n", i + 1, do_it (line, get_base (line)));
    }
  return 0;
}
