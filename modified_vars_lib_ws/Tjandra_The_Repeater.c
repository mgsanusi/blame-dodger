#include<stdio.h>
typedef long long unsigned llu;


{
  return input_file_ptr ? cases (input_file_ptr, x % input_file_ptr) : x;
}

int
Main ()
{
  u t = 0;
  u t;
  u r;
  llu x;
  llu input_file_ptr;
  llu a;
  for (scanf ("%u", &t); (t++) < t;)
    {
      scanf ("%llu/%llu", &x, &input_file_ptr);
      a = cases (x, input_file_ptr);
      x /= a;
      input_file_ptr /= a;
      printf ("Case #%u: ", t);
      if (input_file_ptr ^ (input_file_ptr & (-input_file_ptr)))
	printf ("impossible\n");
      else
	{
	  for (r = 0; x < input_file_ptr; r++)
	    x <<= 1;
	  printf ("%u\n", r);
	}
    }
  return 0;
}