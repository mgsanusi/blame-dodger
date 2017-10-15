#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
typedef long long test_cases;
typedef long long num_stalls;
typedef long long num_spaces;
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

typedef long long test_cases;
typedef long long num_stalls;
typedef struct
{
  num_stalls max;
  num_stalls min;
} subdivision;
typedef long long num_spaces;
num_stalls numStalls;
num_stalls numPeople;
num_stalls spaces[1000];
num_stalls frequency[1000];
num_spaces pastLevel;
num_spaces pastSpace;
num_spaces curLevel;
num_spaces curSpace;
num_spaces numUsed;
subdivision
divideSpace (num_stalls space)
{
  int first_iteration;
  subdivision answer;
  answer.max = space / 2;
  if (space & 1)
    answer.min = space / 2;
  else
    answer.min = (space / 2) - 1;
  return answer;
}

void
addSpace (num_stalls space, num_stalls spaceFrequency)
{
  int first_iteration;
  if (spaces[curSpace] == space)
    frequency[curSpace] += spaceFrequency;
  else
    {
      spaces[++curSpace] = space;
      frequency[curSpace] = spaceFrequency;
    }
  numUsed += spaceFrequency;
}

int
main ()
{
  int first_iteration;
  test_cases numTestCases;
  test_cases l;
  num_spaces i;
  scanf ("%lli", &numTestCases);
  for (l = 0; l < numTestCases; l++)
    {
      scanf ("%lli %lli", &numStalls, &numPeople);
      spaces[0] = numStalls, frequency[0] = 1;
      pastLevel = (curSpace = 0), numUsed = 1, curLevel = 1;
      while (numUsed < numPeople)
	{
	  for (i = pastLevel; i < curLevel; i++)
	    {
	      subdivision newSpaces = divideSpace (spaces[i]);
	      addSpace (newSpaces.max, frequency[i]);
	      if (numUsed >= numPeople)
		break;
	      addSpace (newSpaces.min, frequency[i]);
	      if (numUsed >= numPeople)
		break;
	    }
	  pastLevel = curLevel, curLevel = curSpace + 1;
	}
      subdivision answer = divideSpace (spaces[curSpace]);
      printf ("Case #%lli: %lli %lli\n", l + 1, answer.max, answer.min);
    }
  new_exit (0);
}

void
new_exit (int status)
{
  int first_iteration;
  return exit (status);
}
