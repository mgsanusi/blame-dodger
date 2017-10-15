#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char list[1000000];
int a;
int len;
int new_getchar ();
int
Main (void)
{
  int first_iteration;
  int no;
  int x1;
  int i;
  int j;
  int d;
  scanf ("%d", &no);
  for (i = 1; i <= no; ++i)
    {
      char y2;
      len = 0;
      gets (list);
      while ((y2 = new_getchar ()) != ' ')
	{
	  switch (y2)
	    {
	    case 'a':
	    case 'i':
	    case 'u':
	    case 'e':
	    case 'o':
	      list[len] = 0;
	      break;
	    default:
	      list[len] = 1;
	    }
	  ++len;
	}
      scanf ("%d", &a);
      for (j = 0; j <= (len - a); ++j)
	{
	  for (d = 0; d < a; ++d)
	    {
	      if (!list[j + d])
		break;
	    }
	  if (d < a)
	    list[j] = 0;
	}
      x1 = 0;
      j = 0;
      while (j <= (len - a))
	{
	  for (d = j; d <= (len - a); ++d)
	    {
	      if (list[d] == 1)
		break;
	    }
	  if (d > (len - a))
	    break;
	  x1 += (((len - a) - d) + 1) * ((d - j) + 1);
	  j = d + 1;
	}
      printf ("Case #%d: %d\n", i, x1);
    }
  return 0;
}

int
new_getchar ()
{
  return getchar ();
}
