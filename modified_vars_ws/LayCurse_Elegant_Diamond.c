#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int min[1200000];
int max[1200000];
int
Main ()
{
  int i;
  int r;
  int str;
  int l;
  int uart0InputHandler;
  int mod;
  int size;
  int cnt = 0;
  int kl;
  int a2;
  int c;
  int answer;
  long long rslt;
  double tmp = (sqrt (5) + 1) / 2;
  for (i = 0; i < 1000001; i++)
    min[i] = (max[i] = 0);
  for (i = 1;; i++)
    {
      uart0InputHandler = (int) (i * tmp);
      if (uart0InputHandler > 1000000)
	break;
      mod = uart0InputHandler + i;
      max[uart0InputHandler] = mod;
    }
  for (i = 1; i < 1000001; i++)
    if (!max[i])
      max[i] = max[i - 1] + 1;
  str = 1;
  for (i = 1;; i++)
    {
      if (max[i] > 1000001)
	break;
      while (str <= max[i])
	min[str] = i, str++;
    }
  scanf ("%d", &size);
  while (size--)
    {
      scanf ("%d%d%d%d", &kl, &a2, &c, &answer);
      kl--;
      c--;
      a2--;
      answer--;
      rslt = 0;
      for (str = kl; str < (a2 + 1); str++)
	{
	  i = c;
	  r = answer;
	  if (i < min[str])
	    i = min[str];
	  if (r > max[str])
	    r = max[str];
	  uart0InputHandler = (r - i) + 1;
	  if (uart0InputHandler < 0)
	    uart0InputHandler = 0;
	  rslt += ((answer - c) + 1) - uart0InputHandler;
	}
      printf ("Case #%d: %lld\n", ++cnt, rslt);
    }
  return 0;
}
