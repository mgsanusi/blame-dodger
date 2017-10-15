#include <stdio.h>
int no[31] =
  { 1, 5, 27, 143, 751, 935, 607, 903, 991, 335, 47, 943, 471, 55, 447, 463,
991, 95, 607, 263, 151, 855, 527, 743, 351, 135, 407, 903, 791, 135, 647 };
int
Main ()
{
  int k;
  int a;
  int newS;
  scanf ("%d", &k);
  for (newS = 1; newS <= k; newS++)
    {
      scanf ("%d", &a);
      printf ("Case #%d: ", newS);
      if (no[a] < 10)
	printf ("00%d\n", no[a]);
      else if (no[a] < 100)
	printf ("0%d\n", no[a]);
      else
	printf ("%d\n", no[a]);
    }
  return 0;
}
