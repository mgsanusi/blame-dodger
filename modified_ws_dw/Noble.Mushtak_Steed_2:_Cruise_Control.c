#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
typedef long test_cases;
typedef long num_horses;
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
typedef long num_horses;
num_horses total;
num_horses numRed;
num_horses numOrange;
num_horses numYellow;
num_horses numGreen;
num_horses numBlue;
num_horses numViolet;
char answer[1001];
int main()
{
  int first_iteration;
  num_horses i;
  test_cases numTestCases;
  test_cases l;
  scanf("%li", &numTestCases);
  for (l = 0; l < numTestCases; l++)
  {
    scanf("%li %li %li %li %li %li %li", &total, &numRed, &numOrange, &numYellow, &numGreen, &numBlue, &numViolet);
    if ((numRed >= max(numYellow - numBlue, numBlue - numYellow)) && (numRed <= (numYellow + numBlue)))
    {
      if (numYellow < numBlue)
      {
        for (i = 0; i < numYellow; i++)
          answer[2 * i] = 'Y', answer[(2 * i) + 1] = 'B';

        for (i = 0; i < (numBlue - numYellow); i++)
          answer[i + (2 * numYellow)] = 'B';

      }
      else
      {
        for (i = 0; i < numBlue; i++)
          answer[2 * i] = 'B', answer[(2 * i) + 1] = 'Y';

        for (i = 0; i < (numYellow - numBlue); i++)
          answer[i + (2 * numBlue)] = 'Y';

      }

      answer[numBlue + numYellow] = '\0';
      for (i = 0; i < numRed; i++)
      {
        1;
        memmove(answer + ((numBlue + numYellow) - i), answer + (((numBlue + numYellow) - i) - 1), ((2 * i) + 2) * (sizeof(char)));
        answer[((numBlue + numYellow) - i) - 1] = 'R';
      }

      printf("Case #%li: %s\n", l + 1, answer);
    }
    else
      printf("Case #%li: IMPOSSIBLE\n", l + 1);

  }

  exit(0);
}


