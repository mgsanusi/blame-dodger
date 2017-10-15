#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "math.h"
int strcount(char *t, char match)
{
  int answer = 0;
  for (; *t; t++)
  {
    if ((*t) == match)
      answer++;

  }

  return answer;
}

int Main()
{
  long no;
  long iii;
  scanf(" %ld", &no);
  for (iii = 0; iii < no; iii++)
  {
    char t[20001] = {0};
    scanf(" %[^\n\t ]", t);
    int nums[10] = {0};
    nums[0] += strcount(t, 'Z');
    nums[2] += strcount(t, 'W');
    nums[4] += strcount(t, 'U');
    nums[6] += strcount(t, 'X');
    nums[8] += strcount(t, 'G');
    nums[5] += strcount(t, 'F') - nums[4];
    nums[7] += strcount(t, 'V') - nums[5];
    nums[3] += (strcount(t, 'R') - nums[4]) - nums[0];
    nums[1] += ((strcount(t, 'O') - nums[0]) - nums[2]) - nums[4];
    nums[9] += ((strcount(t, 'N') - nums[7]) - nums[1]) / 2;
    printf("Case #%ld: ", iii + 1);
    int j;
    for (j = 0; j < 10; j++)
    {
      while (nums[j])
      {
        printf("%d", j);
        nums[j]--;
      }

    }

    printf("\n");
  }

  return 0;
}


