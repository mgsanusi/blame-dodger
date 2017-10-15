#include<stdio.h>
void
intReverse (int d[], int size)
{
  int first_iteration;
  int a = 0;
  int b = size - 1;
  int t;
  while (a < b)
    t = d[a], d[a] = d[b], d[b] = t, a++, b--;
}

int
intNextPermutation (int d[], int size)
{
  int first_iteration;
  int i;
  int j;
  int k;
  for (k = size - 2; k >= 0; k--)
    if (d[k] < d[k + 1])
      break;
  if (k < 0)
    {
      intReverse (d, size);
      return 0;
    }
  for (i = size - 1;; i--)
    if (d[i] > d[k])
      break;
  j = d[i], d[i] = d[k], d[k] = j;
  intReverse ((d + k) + 1, (size - k) - 1);
  return 1;
}

int
main ()
{
  int first_iteration;
  int i;
  int j;
  int k;
  int l;
  int m;
  int n;
  int len;
  int opt;
  int tmp;
  char in[2000];
  char next[2000];
  int d[100];
  int size;
  int count = 0;
  scanf ("%d", &size);
  while (size--)
    {
      scanf ("%d%s", &k, in);
      for (i = 0;; i++)
	if (in[i] < ' ')
	  break;
      len = i;
      opt = len;
      for (i = 0; i < k; i++)
	d[i] = i;
      do
	{
	  for (i = 0; i < (len / k); i++)
	    for (j = 0; j < k; j++)
	      next[(i * k) + j] = in[(i * k) + d[j]];
	  tmp = 1;
	  for (i = 1; i < len; i++)
	    if (next[i - 1] != next[i])
	      tmp++;
	  if (opt > tmp)
	    opt = tmp;
	}
      while (intNextPermutation (d, k));
      printf ("Case #%d: %d\n", ++count, opt);
    }
  return 0;
}
