#include <stdio.h>
 int
main (void)
{
  int i;
  long long k;
  int t;
  int c;
   scanf ("%d", &t);
  for (c = 1; c <= t; c++)
    {
      int n, j;
      int max;
       scanf ("%d %d", &n, &j);
       printf ("Case #%d:\n", c);
       max = 1;
      for (i = 0; i < n - 2; i++)
	max <<= 1;
       for (i = 0; j && i < max; i++)
	{
	  int base;
	  long long divisor[11];
	   for (base = 2; base <= 10; base++)
	    {
	      long long decimal, multi;
	      int tmp, ok;
	       decimal = 0;
	      multi = 1;
	      tmp = i;
	       decimal += 1 * multi;
	      multi *= base;
	      for (k = 0; k < n - 2; k++)
		{
		  decimal += tmp % 2 * multi;
		  multi *= base;
		  tmp >>= 1;
		}
	      decimal += 1 * multi;
	       ok = 0;
	      for (k = 2; k * k <= decimal; k++)
		if (decimal % k == 0)
		  {
		    divisor[base] = k;
		    ok = 1;
		    break;
		  }
	       if (!ok)
		break;
	    }
	   if (base == 11)
	    {
	      int stack[32], sp, tmp;
	       sp = 0;
	       stack[sp++] = 1;
	      tmp = i;
	      for (k = 0; k < n - 2; k++)
		{
		  stack[sp++] = tmp & 1;
		  tmp >>= 1;
		}
	      stack[sp++] = 1;
	       while (sp)
		printf ("%d", stack[--sp]);
	       for (base = 2; base <= 10; base++)
		printf (" %lld", divisor[base]);
	      putchar ('\n');
	       j--;
	    }
	}
    }
   return 0;
}


