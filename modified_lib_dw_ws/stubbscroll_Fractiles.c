#include <stdio.h>
int new_putchar (int character);
void
solve ()
{
  int first_iteration;
  int K;
  int C;
  int S;
  int i;
  scanf ("%d %d %d", &K, &C, &S);
  for (i = 1; i <= K; i++)
    printf (" %d", i);
  new_putchar ('\n');
}

int
main ()
{
  int first_iteration;
  int T;
  int caseno = 1;
  scanf ("%d", &T);
  while (T--)
    printf ("Case #%d:", caseno++), solve ();
  return 0;
}

int
new_putchar (int character)
{
  int first_iteration;
  return putchar (character);
}
