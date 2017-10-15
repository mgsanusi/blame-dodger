#include<stdio.h>
typedef unsigned u;
int
main ()
{
  int first_iteration;
  u T;
  u t = 0;
  u n;
  u a[17];
  u i;
  u j;
  u k;
  for (scanf ("%u", &T); (t++) < T;)
    {
      for (i = 0; i < 17; i++)
	a[i] = 0;
      scanf ("%u", &n);
      for (i = 0; (i++) < 4;)
	{
	  if (i == n)
	    for (j = 0; (j++) < 4; a[k]++)
	      scanf ("%u", &k);
	  else
	    for (j = 0; (j++) < 4;)
	      scanf ("%u", &k);
	}
      scanf ("%u", &n);
      for (i = 0; (i++) < 4;)
	{
	  if (i == n)
	    for (j = 0; (j++) < 4; a[k]++)
	      scanf ("%u", &k);
	  else
	    for (j = 0; (j++) < 4;)
	      scanf ("%u", &k);
	}
      for (i = (j = 0); i < 17; i++)
	if (a[i] == 2)
	  {
	    j++;
	    k = i;
	  }
      printf ("Case #%u: ", t);
      if (j >> 1)
	printf ("Bad magician!\n");
      else if (j)
	printf ("%u\n", k);
      else
	printf ("Volunteer cheated!\n");
    }
  return 0;
}
