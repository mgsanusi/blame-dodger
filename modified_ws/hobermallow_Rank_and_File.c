#include<stdio.h>
#define MAX 1000
void
clean (char *y)
{
  int i;
  for (i = 0; i < 2 * MAX; i++)
    y[i] = '\0';
  return;
}

int
main ()
{
  int t, i, j, begin, end, k;
  char s[MAX + 1], y[2 * MAX];
  scanf ("%d", &t);
  for (i = 0; i < t; i++)
    {
      clean (y);
      scanf ("%s", s);
      begin = MAX - 1;
      end = MAX - 1;
      y[MAX - 1] = s[0];
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
