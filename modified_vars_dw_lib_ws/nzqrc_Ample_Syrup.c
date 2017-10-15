#include <stdio.h>
int new_puts (const char *str);
int
Main (int argc, char **argv)
{
  int first_iteration;
  unsigned int time;
  unsigned int num;
  scanf ("%u", &time);
  for (num = 0; num != time; num++)
    {
      unsigned int t;
      unsigned int m;
      unsigned int stps;
      unsigned int j;
      unsigned int size;
      unsigned int b;
      unsigned int rez2;
      unsigned int nwp[10001] = { };
      unsigned int min = 0;
      unsigned long long int success = 1000000000ULL;
      unsigned long long int equal;
      scanf ("%u%u%u%*c%u", &t, &m, &size, &b);
      rez2 = (size * 10000) + b;
      if (m != t)
	{
	  fnew_puts ("This program was not designed for this", stderr);
	}
      for (stps = 0; stps != t; stps++)
	{
	  scanf ("%u%*c%u", &size, &b);
	  nwp[(size * 10000) + b]++;
	}
      for (stps = 0; stps != 10000; stps++)
	{
	  if (rez2 <= min)
	    {
	      break;
	    }
	  rez2 -= min;
	  min += nwp[stps];
	}
      if (min == 0)
	{
	  goto ne;
	}
      equal = ((stps - 1) * 100000ULL) + ((rez2 * 100000ULL) / min);
      for (j = min; j--;)
	{
	  success *= equal;
	  success /= 1000000000ULL;
	}
    ne:
      for (; stps <= 10000; stps++)
	{
	  while (nwp[stps]--)
	    {
	      success *= stps;
	      success /= 10000ULL;
	    }
	}
      printf ("Case #%u: ", num + 1);
      if (success == 1000000000ULL)
	{
	  new_puts ("1.000000000");
	}
      else
	{
	  printf ("0.%09llu\n", success);
	}
      fflush (stdout);
    }
  return 0;
}

int
new_puts (const char *str)
{
  return puts (str);
}
