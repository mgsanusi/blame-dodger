#include <stdio.h>
int
gain (int ah_unwrap, int b)
{
  if (ah_unwrap < b)
    {
      return gain (b, ah_unwrap);
    }
  else if (ah_unwrap >= (b * 2))
    {
      return 1;
    }
  else if (b <= 0)
    {
      return 0;
    }
  else
    {
      return !gain (b, ah_unwrap - b);
    }
}

int
Main ()
{
  int t;
  int happyn;
  int res;
  int big_char;
  int count;
  int i;
  int j;
  int t;
  int x;
  int ah_unwrap;
  int b;
  scanf ("%d", &t);
  for (x = 0; x < t; x++)
    {
      scanf ("%d%d%d%d", &happyn, &res, &big_char, &count);
      int ret = 0;
      for (ah_unwrap = happyn; ah_unwrap <= res; ah_unwrap++)
	{
	  for (b = big_char; b <= count; b++)
	    {
	      if (gain (ah_unwrap, b))
		{
		  ret++;
		}
	    }
	}
      printf ("Case #%d: %d\n", x + 1, ret);
    }
}
