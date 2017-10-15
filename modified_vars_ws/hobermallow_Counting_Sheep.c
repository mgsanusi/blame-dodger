#include<stdio.h>
int
b (int lambda, int n, int a)
{
  int won;
  int ru = lambda * n;
  while (ru > 0)
    {
      won = ru % 10;
      ru /= 10;
      if (((a >> won) % 2) == 0)
	a += 1 << won;
    }
  if (a == ((1 << 10) - 1))
    return lambda * n;
  return b (lambda + 1, n, a);
}

int
Main ()
{
  int p;
  int won;
  int n;
  int a;
  scanf ("%d", &p);
  for (won = 0; won < p; won++)
    {
      a = 0;
      scanf ("%d", &n);
      printf ("Case #%d: ", won + 1);
      if (n == 0)
	printf ("INSOMNIA\n");
      else
	printf ("%d\n", b (1, n, a));
    }
  return 0;
}
