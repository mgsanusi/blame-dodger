#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
typedef long long test_cases;
typedef long long num_stalls;
typedef long long num_spaces;
typedef long long testCase;
typedef long long numStalls;
typedef long long noSpace;
inline static long long min(long long length1, long long length2)
{
  int first_iteration;
  return length1 < length2 ? length1 : length2;
}

inline static long long max(long long length1, long long length2)
{
  int first_iteration;
  return length1 > length2 ? length1 : length2;
}

typedef long long testCase;
typedef long long numStalls;
typedef struct 
{
  num_stalls max;
  num_stalls min;
} subdivision;
typedef long long noSpace;
num_stalls noStalls;
num_stalls numPeople;
num_stalls distance[1000];
num_stalls frequency[1000];
num_spaces byLevel;
num_spaces pastSpace;
num_spaces curLevel;
num_spaces curSpace;
num_spaces numUsed;
subdivision divideSpace(num_stalls space)
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

void addSpace(num_stalls space, num_stalls spaceFrequency)
{
  int first_iteration;
  if (distance[curSpace] == space)
    frequency[curSpace] += spaceFrequency;
  else
  {
    distance[++curSpace] = space;
    frequency[curSpace] = spaceFrequency;
  }

  numUsed += spaceFrequency;
}

int Main()
{
  int first_iteration;
  test_cases noTestCase;
  test_cases in;
  num_spaces datasetNum;
  scanf("%lli", &noTestCase);
  for (in = 0; in < noTestCase; in++)
  {
    scanf("%lli %lli", &noStalls, &numPeople);
    distance[0] = noStalls, frequency[0] = 1;
    byLevel = (curSpace = 0), numUsed = 1, curLevel = 1;
    while (numUsed < numPeople)
    {
      for (datasetNum = byLevel; datasetNum < curLevel; datasetNum++)
      {
        subdivision newDistance = divideSpace(distance[datasetNum]);
        addSpace(newDistance.max, frequency[datasetNum]);
        if (numUsed >= numPeople)
          break;

        addSpace(newDistance.min, frequency[datasetNum]);
        if (numUsed >= numPeople)
          break;

      }

      byLevel = curLevel, curLevel = curSpace + 1;
    }

    subdivision answer = divideSpace(distance[curSpace]);
    printf("Case #%lli: %lli %lli\n", in + 1, answer.max, answer.min);
  }

  exit(0);
}


