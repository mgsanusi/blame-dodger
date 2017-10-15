#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
inline static long long min(long long length1, long long length2)
{
  return length1 < length2 ? length1 : length2;
}

inline static long long max(long long length1, long long length2)
{
  return length1 > length2 ? length1 : length2;
}

typedef long test_cases;
typedef long numPancakes;
typedef long num_flips;
num_flips ans;
numPancakes num_pancakes;
numPancakes flipperLen;
char str[1001];
bool pancakes[1000];
int Main()
{
  numPancakes cases;
  numPancakes sx;
  test_cases noTestCase;
  test_cases s;
  scanf("%li", &noTestCase);
  for (s = 0; s < noTestCase; s++)
  {
    scanf("%s", str);
    num_pancakes = strlen(str);
    for (int cases = 0; cases < num_pancakes; cases++)
    {
      pancakes[cases] = str[cases] == '+';
    }

    scanf("%li", &flipperLen);
    ans = 0;
    for (int cases = 0; cases < num_pancakes; cases++)
      if (!pancakes[cases])
    {
      if (((cases + flipperLen) - 1) < num_pancakes)
      {
        ans++;
        for (int sx = 0; sx < flipperLen; sx++)
          pancakes[cases + sx] = !pancakes[cases + sx];

      }
      else
        ans = -1;

    }


    if (ans < 0)
      printf("Case #%li: IMPOSSIBLE\n", s + 1);
    else
      printf("Case #%li: %li\n", s + 1, ans);

  }

  exit(0);
}


