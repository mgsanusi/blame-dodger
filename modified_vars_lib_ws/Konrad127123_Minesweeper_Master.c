#include<stdio.h>
int dy;
int t;
int k;
int count;
int to;
int output;
int m;
int k;
int
Main ()
{
  scanf ("%d", &t);
  for (dy = 1; dy <= t; dy++)
    {
      printf ("Case #%d: \n", dy);
      scanf ("%d", &to);
      scanf ("%d", &output);
      scanf ("%d", &m);
      if (output == 1)
	{
	  printf ("c\n");
	  for (k = 2; k <= ((to * output) - m); k++)
	    printf (".\n");
	  for (; k <= to; k++)
	    printf ("*\n");
	}
      else if (to == 1)
	{
	  printf ("c");
	  for (k = 2; k <= ((to * output) - m); k++)
	    printf (".");
	  for (; k <= output; k++)
	    printf ("*");
	  printf ("\n");
	}
      else if (((to * output) - m) <= 1)
	{
	  for (k = 1; k <= to; k++)
	    {
	      for (k = 1; k <= output; k++)
		{
		  if (((k == 1) && (k == 1)) && (((to * output) - m) == 1))
		    printf ("c");
		  else
		    printf ("*");
		}
	      printf ("\n");
	    }
	}
      else if (((to * output) - m) == 2)
	{
	  printf ("Impossible\n");
	}
      else if (to == 2)
	{
	  if ((((to * output) - m) % 2) == 1)
	    printf ("Impossible\n");
	  else
	    {
	      printf ("c");
	      for (k = 2; k <= (((to * output) - m) / 2); k++)
		printf (".");
	      for (; k <= output; k++)
		printf ("*");
	      printf ("\n");
	      for (k = 1; k <= (((to * output) - m) / 2); k++)
		printf (".");
	      for (; k <= output; k++)
		printf ("*");
	      printf ("\n");
	    }
	}
      else if (output == 2)
	{
	  if ((((to * output) - m) % 2) == 1)
	    printf ("Impossible\n");
	  else
	    {
	      printf ("c.\n");
	      for (k = 2; k <= (((to * output) - m) / 2); k++)
		printf ("..\n");
	      for (; k <= to; k++)
		printf ("**\n");
	    }
	}
      else if (((to * output) - m) <= ((2 * output) + 1))
	{
	  if (((((to * output) - m) == 3) || (((to * output) - m) == 5))
	      || (((to * output) - m) == 7))
	    printf ("Impossible\n");
	  else
	    {
	      if ((((to * output) - m) % 2) == 0)
		{
		  printf ("c");
		  for (k = 2; k <= (((to * output) - m) / 2); k++)
		    printf (".");
		  for (; k <= output; k++)
		    printf ("*");
		  printf ("\n");
		  for (k = 1; k <= (((to * output) - m) / 2); k++)
		    printf (".");
		  for (; k <= output; k++)
		    printf ("*");
		  printf ("\n");
		  for (k = 3; k <= to; k++)
		    {
		      for (k = 1; k <= output; k++)
			printf ("*");
		      printf ("\n");
		    }
		}
	      else
		{
		  printf ("c");
		  for (k = 2; k <= ((((to * output) - m) - 3) / 2); k++)
		    printf (".");
		  for (; k <= output; k++)
		    printf ("*");
		  printf ("\n");
		  for (k = 1; k <= ((((to * output) - m) - 3) / 2); k++)
		    printf (".");
		  for (; k <= output; k++)
		    printf ("*");
		  printf ("\n");
		  for (k = 1; k <= 3; k++)
		    printf (".");
		  for (; k <= output; k++)
		    printf ("*");
		  printf ("\n");
		  for (k = 4; k <= to; k++)
		    {
		      for (k = 1; k <= output; k++)
			printf ("*");
		      printf ("\n");
		    }
		}
	    }
	}
      else if ((((output * to) - m) % output) == 1)
	{
	  m += 2;
	  count = 1;
	  printf ("c");
	  for (k = 2; k <= output; k++)
	    {
	      printf (".");
	      count++;
	    }
	  printf ("\n");
	  for (k = 2; (k <= to) && (count < ((output * to) - m)); k++)
	    {
	      for (k = 1; k <= output; k++)
		if (count < ((output * to) - m))
		  {
		    printf (".");
		    count++;
		  }
		else
		  {
		    printf ("*");
		  }
	      printf ("\n");
	    }
	  printf ("..");
	  for (k = 3; k <= output; k++)
	    {
	      printf ("*");
	    }
	  k++;
	  printf ("\n");
	  for (; k <= to; k++)
	    {
	      for (k = 1; k <= output; k++)
		if (count < ((output * to) - m))
		  {
		    printf (".");
		    count++;
		  }
		else
		  {
		    printf ("*");
		  }
	      printf ("\n");
	    }
	}
      else
	{
	  count = 1;
	  printf ("c");
	  for (k = 2; k <= output; k++)
	    {
	      printf (".");
	      count++;
	    }
	  printf ("\n");
	  for (k = 2; k <= to; k++)
	    {
	      for (k = 1; k <= output; k++)
		if (count < ((output * to) - m))
		  {
		    printf (".");
		    count++;
		  }
		else
		  {
		    printf ("*");
		  }
	      printf ("\n");
	    }
	}
    }
  return 0;
}
