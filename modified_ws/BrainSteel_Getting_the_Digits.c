/* 
 
Google Code Jam Round 1B
April 30, 2016
Jesse Pritchard
Public contact: chaserdevelopment@gmail.com
 
Problem A
*/
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "math.h"
#define STR_LEN 20001
int
strcount (char *s, char match)
{
  int result = 0;
  for (; *s; s++)
    {
      if (*s == match)
	result++;
    }
  return result;
}

int
main ()
{
  long num, iii;
  scanf (" %ld", &num);
  for (iii = 0; iii < num; iii++)
    {

      char S[STR_LEN] = { 0 };

      scanf (" %[^\n\t ]", S);

      int nums[10] = { 0 };


      nums[0] += strcount (S, 'Z');
      nums[2] += strcount (S, 'W');
      nums[4] += strcount (S, 'U');
      nums[6] += strcount (S, 'X');
      nums[8] += strcount (S, 'G');
      nums[5] += strcount (S, 'F') - nums[4];
      nums[7] += strcount (S, 'V') - nums[5];
      nums[3] += strcount (S, 'R') - nums[4] - nums[0];
      nums[1] += strcount (S, 'O') - nums[0] - nums[2] - nums[4];
      nums[9] += (strcount (S, 'N') - nums[7] - nums[1]) / 2;

      printf ("Case #%ld: ", iii + 1);

      int i;
      for (i = 0; i < 10; i++)
	{
	  while (nums[i])
	    {
	      printf ("%d", i);
	      nums[i]--;
	    }
	}

      printf ("\n");
    }
  return 0;
}
