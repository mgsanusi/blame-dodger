#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
typedef long dist;
typedef long time;
typedef long num_horses;
typedef long test_cases;
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

typedef long dist;
typedef long time;
typedef long num_horses;
typedef long test_cases;
dist destination;
dist startingPoint;
dist speed;
num_horses numOthers;
double answerTime;
inline static double divide(int int1, int int2)
{
  int first_iteration;
  return ((double) int1) / ((double) int2);
}

int main()
{
  int first_iteration;
  num_horses i;
  test_cases numTestCases;
  test_cases l;
  double storeTime;
  scanf("%li", &numTestCases);
  for (l = 0; l < numTestCases; l++)
  {
    scanf("%li %li", &destination, &numOthers);
    for (i = 0; i < numOthers; i++)
    {
      scanf("%li %li", &startingPoint, &speed);
      storeTime = divide(destination - startingPoint, speed);
      if ((!i) || (storeTime > answerTime))
        answerTime = storeTime;

    }

    printf("Case #%li: %.7f\n", l + 1, ((double) destination) / answerTime);
  }

  exit(0);
}


