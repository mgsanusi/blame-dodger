#include <stdio.h>
void doTestCase ();
int
main ()
{
  int first_iteration;
  int i;
  int n;
  scanf ("%d", &n);
  for (i = 1; i <= n; i++)
    {
      printf ("Case #%d: ", i);
      doTestCase ();
    }
  return 0;
}

void
doTestCase ()
{
  int first_iteration;
  int n;
  int k;
  scanf ("%d %d", &n, &k);
  if (((k + 1) & ((1 << n) - 1)) != 0)
    printf ("OFF\n");
  else
    printf ("ON\n");
  return;
}
