#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
typedef long test_cases;
typedef long num_horses;
typedef long test_case;
typedef long num_horse;
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

typedef long test_case;
typedef long num_horse;
num_horses total;
num_horses num_red;
num_horses num_orange;
num_horses no_yellow;
num_horses num_green;
num_horses no_blue;
num_horses no_violet;
char answer[1001];
int Main()
{
  int first_iteration;
  num_horses j;
  test_cases no_test_case;
  test_cases elements;
  scanf("%li", &no_test_case);
  for (elements = 0; elements < no_test_case; elements++)
  {
    scanf("%li %li %li %li %li %li %li", &total, &num_red, &num_orange, &no_yellow, &num_green, &no_blue, &no_violet);
    if ((num_red >= max(no_yellow - no_blue, no_blue - no_yellow)) && (num_red <= (no_yellow + no_blue)))
    {
      if (no_yellow < no_blue)
      {
        for (j = 0; j < no_yellow; j++)
          answer[2 * j] = 'Y', answer[(2 * j) + 1] = 'B';

        for (j = 0; j < (no_blue - no_yellow); j++)
          answer[j + (2 * no_yellow)] = 'B';

      }
      else
      {
        for (j = 0; j < no_blue; j++)
          answer[2 * j] = 'B', answer[(2 * j) + 1] = 'Y';

        for (j = 0; j < (no_yellow - no_blue); j++)
          answer[j + (2 * no_blue)] = 'Y';

      }

      answer[no_blue + no_yellow] = '\0';
      for (j = 0; j < num_red; j++)
      {
        1;
        memmove(answer + ((no_blue + no_yellow) - j), answer + (((no_blue + no_yellow) - j) - 1), ((2 * j) + 2) * (sizeof(char)));
        answer[((no_blue + no_yellow) - j) - 1] = 'R';
      }

      printf("Case #%li: %s\n", elements + 1, answer);
    }
    else
      printf("Case #%li: IMPOSSIBLE\n", elements + 1);

  }

  exit(0);
}


