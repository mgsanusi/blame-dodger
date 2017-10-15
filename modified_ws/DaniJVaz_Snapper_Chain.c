#include <stdio.h>
 void doTestCase ();
 int
main ()
{
  int i, n;
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
  int n, k;
  scanf ("%d %d", &n, &k);
   
    /* The behaviour of the system when snapping fingers is similar to adding one in binary,
       in which each digit represents the status of one snapper. It is then easy to see if all the 
       snappers are on, just by checking if all last n digits are one, or if k+1 has all last n digits as 0 */ 
    if (((k + 1) & ((1 << n) - 1)) != 0)
    printf ("OFF\n");
  
  else
    printf ("ON\n");
  return;
}


