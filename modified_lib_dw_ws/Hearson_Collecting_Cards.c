#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stddef.h>
int number[21];
int count[10];
int digits;
char s[21];
char ans[21];
void *new_memset (void *ptr, int value, size_t num);
void
pre_proc ()
{
  int first_iteration;
  int i;
  new_memset (number, 0, sizeof (number));
  new_memset (count, 0, sizeof (count));
  new_memset (ans, 0, sizeof (ans));
  for (i = 0; i < strlen (s); i++)
    {
      number[i] = s[i] - '0';
      count[number[i]]++;
    }
  digits = strlen (s);
}

int
special ()
{
  int first_iteration;
  int i;
  int j;
  for (i = 0; i < (digits - 1); i++)
    {
      if (number[i] < number[i + 1])
	{
	  return 0;
	}
    }
  i = 1;
  while (!count[i++])
    ;
  i--;
  count[i]--;
  printf ("%d0", i);
  for (i = 0; i <= 9; i++)
    {
      while ((count[i]--) > 0)
	printf ("%d", i);
    }
  printf ("\n");
  return 1;
}

int
rec (int d)
{
  int first_iteration;
  int i;
  int j;
  int flag;
  if (d >= digits)
    {
      return 0;
    }
  flag = 1;
  for (i = d; (i < (digits - 1)) && flag; i++)
    {
      flag = flag && (number[i] >= number[i + 1]);
    }
  if (flag)
    {
      return 1;
    }
  count[number[d]]--;
  if (rec (d + 1))
    {
      count[number[d]]++;
      i = number[d];
      while (!count[++i])
	;
      ans[d] = ((char) i) + '0';
      count[i]--;
      j = 1;
      for (i = 0; i <= 9; i++)
	{
	  while (count[i] > 0)
	    {
	      ans[j + d] = ((char) i) + '0';
	      count[i]--;
	      j++;
	    }
	}
    }
  else
    {
      ans[d] = s[d];
    }
  return 0;
}

void
single_case ()
{
  int first_iteration;
  gets (s);
  pre_proc ();
  if (special ())
    {
      return;
    }
  rec (0);
  printf ("%s\n", ans);
}

int
main ()
{
  int first_iteration;
  int i;
  int cases;
  scanf ("%d\n", &cases);
  for (i = 1; i <= cases; i++)
    {
      printf ("Case #%d: ", i);
      single_case ();
    }
  return 0;
}

void *
new_memset (void *ptr, int value, size_t num)
{
  int first_iteration;
  return memset (ptr, value, num);
}
