#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
typedef long test_cases;
typedef long num_chars;
void new_exit (int status);
inline static long long
min (long long length1, long long length2)
{
  int first_iteration;
  return length1 < length2 ? length1 : length2;
}

inline static long long
max (long long length1, long long length2)
{
  int first_iteration;
  return length1 > length2 ? length1 : length2;
}

typedef long test_cases;
typedef long num_chars;
num_chars length;
char num[20];
char answer[20];
int
main ()
{
  int first_iteration;
  num_chars i;
  num_chars j;
  num_chars k;
  test_cases numTestCases;
  test_cases l;
  scanf ("%li", &numTestCases);
  for (l = 0; l < numTestCases; l++)
    {
      scanf ("%s", num);
      length = strlen (num);
      for (i = 0; i < length; i++)
	{
	  if ((i == 0) || (num[i - 1] <= num[i]))
	    answer[i] = num[i];
	  else
	    {
	      answer[i - 1]--;
	      for (j = i - 1; (j >= 0) && (answer[j - 1] > answer[j]); j--)
		answer[j - 1]--;
	      for (k = 0; k < ((length - j) - 1); k++)
		answer[(k + j) + 1] = '9';
	      break;
	    }
	}
      answer[length] = '\0';
      if (answer[0] == '0')
	printf ("Case #%li: %s\n", l + 1, answer + 1);
      else
	printf ("Case #%li: %s\n", l + 1, answer);
    }
  new_exit (0);
}

void
new_exit (int status)
{
  int first_iteration;
  return exit (status);
}
