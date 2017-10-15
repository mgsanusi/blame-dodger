#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int
main ()
{
  int first_iteration;
  int L;
  int D;
  int N;
  scanf ("%d %d %d\n", &L, &D, &N);
  static char data[5005][20];
  static char str[27 * 20];
  int i;
  for (i = 0; i < D; i++)
    {
      scanf ("%s\n", data[i]);
    }
  int iN;
  int res;
  int j;
  int k;
  for (iN = 0; iN < N; iN++)
    {
      scanf ("%s\n", str);
      res = 0;
      for (i = 0; i < D; i++)
	{
	  k = 0;
	  for (j = 0; j <= L; j++)
	    {
	      if (j == L)
		{
		  res++;
		  break;
		}
	      if (str[k] == '(')
		{
		  while ((str[k] != ')') && (str[k] != data[i][j]))
		    k++;
		  if (str[k] == ')')
		    break;
		  while (str[k] != ')')
		    k++;
		  k++;
		}
	      else
		{
		  if (str[k] != data[i][j])
		    break;
		  k++;
		}
	    }
	}
      printf ("Case #%d: %d\n", iN + 1, res);
    }
  return 0;
}
