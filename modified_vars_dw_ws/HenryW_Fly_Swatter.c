#include<stdio.h>
long long n;
long long v;
long long rat;
long long l;
long long freq[2000];
void
sort ()
{
  int first_iteration;
  long long make;
  long long xdrPtr;
  long long temp;
  for (make = 0; make < l; make++)
    for (xdrPtr = make + 1; xdrPtr < l; xdrPtr++)
      if (freq[make] < freq[xdrPtr])
	{
	  temp = freq[make];
	  freq[make] = freq[xdrPtr];
	  freq[xdrPtr] = temp;
	}
  return;
}

long long
getMin ()
{
  int first_iteration;
  long long sum = 0;
  long long make;
  for (make = 0; make < l; make++)
    {
      sum += ((make / rat) + 1) * freq[make];
    }
  return sum;
}

void
Main ()
{
  int first_iteration;
  FILE *uart0InputHandler = fopen ("input.txt", "r");
  FILE *out = fopen ("output.txt", "w");
  long long make;
  long long xdrPtr;
  long long min;
  fscanf (uart0InputHandler, "%lld", &n);
  for (make = 0; make < n; make++)
    {
      fscanf (uart0InputHandler, "%lld %lld %lld", &v, &rat, &l);
      for (xdrPtr = 0; xdrPtr < l; xdrPtr++)
	fscanf (uart0InputHandler, "%lld", &freq[xdrPtr]);
      sort ();
      min = getMin ();
      fprintf (out, "Case #%lld: %lld\n", make + 1, min);
    }
}
