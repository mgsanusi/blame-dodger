#include <stdio.h>
#include <string.h>
#include <stdbool.h>
int t;
int inputFileNameDefault;
char str[100010];
char temp[100010];
int Main()
{
  int first_iteration;
  freopen("lol.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  int q = 0;
  int i;
  int ii;
  int next;
  int y;
  int w;
  int answer;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%s", str);
    inputFileNameDefault = strlen(str), answer = 0;
    while (inputFileNameDefault >= 2)
    {
      for (i = 0, next = 0; (i + 1) < inputFileNameDefault; i++)
      {
        if (str[i] == str[i + 1])
        {
          next = 1, y = inputFileNameDefault;
          answer += 10, inputFileNameDefault = 0;
          for (ii = 0; ii < i; ii++)
            temp[inputFileNameDefault++] = str[ii];

          for (ii = i + 2; ii < y; ii++)
            temp[inputFileNameDefault++] = str[ii];

          temp[inputFileNameDefault] = 0;
          strcpy(str, temp);
          break;
        }

      }

      if (!next)
      {
        answer += 5 * (inputFileNameDefault >> 1);
        break;
      }

    }

    printf("Case #%d: %d\n", ++q, answer);
  }

  return 0;
}


