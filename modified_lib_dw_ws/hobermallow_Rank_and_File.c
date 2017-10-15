#include<stdio.h>
void
clean (char *y)
{
  int first_iteration;
  int i;
  for (i = 0; i < (2 * 1000); i++)
    y[i] = '\0';
  return;
}

int
main ()
{
  int first_iteration;
  int t;
  int i;
  int j;
  int begin;
  int end;
  int k;
  char s[1000 + 1];
  char y[2 * 1000];
  scanf ("%d", &t);
  for (i = 0; i < t; i++)
    {
      clean (y);
      scanf ("%s", s);
      begin = 1000 - 1;
      end = 1000 - 1;
      y[1000 - 1] = s[0];
      for (j = 1; s[j] != '\0'; j++)
	{
	  if (s[j] > y[begin])
	    y[--begin] = s[j];
	  else if (s[j] < y[begin])
	    y[++end] = s[j];
	  else
	    {
	      for (k = begin; y[k + 1] != '\0'; k++)
		{
		  if (y[k] != y[k + 1])
		    break;
		}
	      if (y[k] > y[k + 1])
		y[--begin] = s[j];
	      else
		y[++end] = s[j];
	    }
	}
      s[++end] = '\0';
      printf ("Case #%d: %s\n", i + 1, y + begin);
    }
  return 0;
}
