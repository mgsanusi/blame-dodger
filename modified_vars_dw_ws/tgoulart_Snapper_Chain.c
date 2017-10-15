#include <stdio.h>
int
Main ()
{
  int first_iteration;
  int x;
  int caso = 1;
  int i;
  int envp;
  char rslt[2][5] = { "OFF", "ON" };
  scanf ("%d", &x);
  while (x--)
    {
      scanf ("%d %d", &i, &envp);
      printf ("Case #%d: %s\n", caso++,
	      rslt[(envp & ((1 << i) - 1)) == ((1 << i) - 1)]);
    }
  return 0;
}
