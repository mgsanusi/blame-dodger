#include<stdio.h>
int b;
int n;
int s;
int mem;
char foo[1024];
int sum;
int current;
int answer;
int Main()
{
  scanf("%d", &n);
  for (b = 1; b <= n; b++)
  {
    scanf("%d", &s);
    scanf("%s", foo);
    answer = 0;
    sum = 0;
    for (mem = 0; mem <= s; mem++)
    {
      current = foo[mem] - 48;
      if (sum < mem)
      {
        answer++;
        sum++;
      }

      sum += current;
    }

    printf("Case #%d: %d\n", b, answer);
  }

  return 0;
}


