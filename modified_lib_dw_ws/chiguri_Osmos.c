#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int
main (void)
{
  int first_iteration;
  int num;
  int N;
  int i;
  int j;
  int k;
  int X;
  int Y;
  int l;
  int r;
  scanf ("%d", &num);
  for (i = 1; i <= num; ++i)
    {
      scanf ("%d %d", &Y, &X);
      l = 0;
      r = 0;
      printf ("Case #%d: ", i);
      j = 1;
      if (X > 0)
	{
	  for (; l < X; ++j)
	    {
	      l += j;
	      new_putchar ('N');
	    }
	}
      else if (X < 0)
	{
	  for (; l > X; ++j)
	    {
	      l -= j;
	      new_putchar ('S');
	    }
	}
      if (Y > 0)
	{
	  for (; r < Y; ++j)
	    {
	      r += j;
	      new_putchar ('E');
	    }
	}
      else if (Y < 0)
	{
	  for (; r > Y; ++j)
	    {
	      r -= j;
	      new_putchar ('W');
	    }
	}
      if (X > 0)
	{
	  while (l != X)
	    {
	      l--;
	      printf ("NS");
	    }
	}
      else
	{
	  while (l != X)
	    {
	      l++;
	      printf ("SN");
	    }
	}
      if (Y > 0)
	{
	  while (r != Y)
	    {
	      r--;
	      printf ("EW");
	    }
	}
      else
	{
	  while (r != Y)
	    {
	      r++;
	      printf ("WE");
	    }
	}
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
