#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int t[16];
int t[16];
int
Main (void)
{
  int first_iteration;
  int no;
  int dis;
  int t;
  int digits;
  int b;
  int p;
  int x_private;
  int fc;
  int mode;
  scanf ("%d", &no);
  for (t = 1; t <= no; ++t)
    {
      p = -1;
      x_private = 0;
      scanf ("%d", &fc);
      for (digits = 0; digits < 16; ++digits)
	{
	  scanf ("%d", t + digits);
	}
      scanf ("%d", &mode);
      for (digits = 0; digits < 16; ++digits)
	{
	  scanf ("%d", t + digits);
	}
      for (digits = 1; digits <= 4; ++digits)
	{
	  for (b = 1; b <= 4; ++b)
	    {
	      if (t[(fc * 4) - digits] == t[(mode * 4) - b])
		{
		  p = t[(fc * 4) - digits];
		  ++x_private;
		}
	    }
	}
      printf ("Case #%d: ", t);
      switch (x_private)
	{
	case 1:
	  printf ("%d\n", p);
	  break;
	case 0:
	  printf ("Volunteer cheated!\n");
	  break;
	default:
	  printf ("Bad magician!\n");
	  break;
	}
    }
  return 0;
}
