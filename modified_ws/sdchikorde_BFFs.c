#include <stdio.h>
#include <string.h>
#include <malloc.h>
void
main ()
{
  int cases;
  scanf ("%d", &cases);
  int n = 0;
  int i;
  int arr[26] = { 0 };
  int ans[10] = { 0 };
  char str[2001];
  while (n < cases)
    {
      n++;
      printf ("Case #%d: ", n);
      scanf ("%s", str);
      for (i = 0; i < 26; i++)
	arr[i] = 0;
      for (i = 0; i < 10; i++)
	ans[i] = 0;
      for (i = 0; i < strlen (str); i++)
	{
	  arr[str[i] - 'A']++;
	}
      if (arr['Z' - 'A'] > 0)
	{
	  ans[0] += arr['Z' - 'A'];
	  arr['E' - 'A'] -= arr['Z' - 'A'];
	  arr['O' - 'A'] -= arr['Z' - 'A'];
	  arr['R' - 'A'] -= arr['Z' - 'A'];
	  arr['Z' - 'A'] = 0;
	}
      if (arr['W' - 'A'] > 0)
	{
	  ans[2] += arr['W' - 'A'];
	  arr['T' - 'A'] -= arr['W' - 'A'];
	  arr['O' - 'A'] -= arr['W' - 'A'];
	  arr['W' - 'A'] = 0;
	}
      if (arr['U' - 'A'] > 0)
	{
	  ans[4] += arr['U' - 'A'];
	  arr['F' - 'A'] -= arr['U' - 'A'];
	  arr['O' - 'A'] -= arr['U' - 'A'];
	  arr['R' - 'A'] -= arr['U' - 'A'];
	  arr['U' - 'A'] = 0;
	}
      if (arr['X' - 'A'] > 0)
	{
	  ans[6] += arr['X' - 'A'];
	  arr['S' - 'A'] -= arr['X' - 'A'];
	  arr['I' - 'A'] -= arr['X' - 'A'];
	  arr['X' - 'A'] = 0;
	}
      if (arr['G' - 'A'] > 0)
	{
	  ans[8] += arr['G' - 'A'];
	  arr['E' - 'A'] -= arr['G' - 'A'];
	  arr['I' - 'A'] -= arr['G' - 'A'];
	  arr['H' - 'A'] -= arr['G' - 'A'];
	  arr['T' - 'A'] -= arr['G' - 'A'];
	  arr['G' - 'A'] = 0;
	}

      if (arr['O' - 'A'] > 0)
	{
	  ans[1] += arr['O' - 'A'];
	  arr['E' - 'A'] -= arr['O' - 'A'];
	  arr['N' - 'A'] -= arr['O' - 'A'];
	}
      if (arr['H' - 'A'] > 0)
	{
	  ans[3] += arr['H' - 'A'];
	}
      if (arr['F' - 'A'] > 0)
	{
	  ans[5] += arr['F' - 'A'];
	}
      if (arr['S' - 'A'] > 0)
	{
	  ans[7] += arr['S' - 'A'];
	  arr['N' - 'A'] -= arr['S' - 'A'];
	}
      if (arr['N' - 'A'] > 0)
	{
	  ans[9] += arr['N' - 'A'] / 2;
	}
      int j;
      for (i = 0; i < 10; i++)
	{
	  for (j = 0; j < ans[i]; j++)
	    {
	      printf ("%d", i);
	    }
	}
      printf ("\n");
    }
}
