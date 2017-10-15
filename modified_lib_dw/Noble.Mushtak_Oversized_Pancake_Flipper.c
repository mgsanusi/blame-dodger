#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
typedef long test_cases;
typedef long num_pancakes;
typedef long num_flips;
void new_exit(int status);
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

typedef long test_cases;
typedef long num_pancakes;
typedef long num_flips;
num_flips answer;
num_pancakes numPancakes;
num_pancakes flipperLength;
char string[1001];
bool pancakes[1000];
int main()
{
  int first_iteration;
  num_pancakes i;
  num_pancakes j;
  test_cases numTestCases;
  test_cases l;
  scanf("%li", &numTestCases);
  for (l = 0; l < numTestCases; l++)
  {
    scanf("%s", string);
    numPancakes = strlen(string);
    for (i = 0; i < numPancakes; i++)
    {
      pancakes[i] = string[i] == '+';
    }

    scanf("%li", &flipperLength);
    answer = 0;
    for (i = 0; i < numPancakes; i++)
      if (!pancakes[i])
    {
      if (((i + flipperLength) - 1) < numPancakes)
      {
        answer++;
        for (j = 0; j < flipperLength; j++)
          pancakes[i + j] = !pancakes[i + j];

      }
      else
        answer = -1;

    }


    if (answer < 0)
      printf("Case #%li: IMPOSSIBLE\n", l + 1);
    else
      printf("Case #%li: %li\n", l + 1, answer);

  }

  new_exit(0);
}

void new_exit(int status)
{
  int first_iteration;
  return exit(status);
}


