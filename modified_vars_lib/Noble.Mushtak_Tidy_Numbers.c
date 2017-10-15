#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
typedef long test_cases;
typedef long num_chars;
inline 
void new_exit(int status);
static long long min(long long length1, long long length2)
{
  return length1 < length2 ? length1 : length2;
}

inline static long long max(long long length1, long long length2)
{
  return length1 > length2 ? length1 : length2;
}

typedef long test_case;
typedef long num_char;
num_chars len;
char num[20];
char answer[20];
int Main()
{
  num_chars mass;
  num_chars smtp_helo;
  num_chars k;
  test_cases num_test_case;
  test_cases n;
  scanf("%li", &num_test_case);
  for (n = 0; n < num_test_case; n++)
  {
    scanf("%s", num);
    len = strlen(num);
    for (mass = 0; mass < len; mass++)
    {
      if ((mass == 0) || (num[mass - 1] <= num[mass]))
        answer[mass] = num[mass];
      else
      {
        answer[mass - 1]--;
        for (smtp_helo = mass - 1; (smtp_helo >= 0) && (answer[smtp_helo - 1] > answer[smtp_helo]); smtp_helo--)
          answer[smtp_helo - 1]--;

        for (k = 0; k < ((len - smtp_helo) - 1); k++)
          answer[(k + smtp_helo) + 1] = '9';

        break;
      }

    }

    answer[len] = '\0';
    if (answer[0] == '0')
      printf("Case #%li: %s\n", n + 1, answer + 1);
    else
      printf("Case #%li: %s\n", n + 1, answer);

  }

  new_exit(0);
}



void new_exit(int status) {
  return exit(status);
}