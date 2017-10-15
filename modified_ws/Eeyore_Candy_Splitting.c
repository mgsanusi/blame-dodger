#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define BUFLEN 8192
char buf[BUFLEN];
int
xor (int a, int b)
{
  return (a | b) & ~(a & b);
}

int
main ()
{
  int T, caseNum, N, pow[20], i, mask, total, smallest;
  for (i = 0; i < 20; i++)
    pow[i] = (1 << i);
  scanf (" %d", &T);
  for (caseNum = 1; caseNum <= T; caseNum++)
    {
      scanf (" %d", &N);
      total = mask = 0;
      smallest = 2 * pow[19];
      while (N-- > 0)
	{
	  scanf (" %d", &i);
	  if (i < smallest)
	    smallest = i;
	  total += i;
	  mask = xor (mask, i);
	}
      printf ("Case #%d: ", caseNum);
      if (mask == 0)
	printf ("%d", total - smallest);
      else
	printf ("NO");
      printf ("\n");
    }
}
