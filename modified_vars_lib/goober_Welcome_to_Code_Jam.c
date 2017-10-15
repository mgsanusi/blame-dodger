#include <stdio.h>
#include <string.h>
char phrase[] = "welcome to code jam";
char buf[501];
int n[501][20];
int Main()
{
  int n;
  int n;
  scanf("%d ", &n);
  for (n = 1; n <= n; n++)
  {
    int str;
    int answer;
    int draw;
    gets(buf);
    str = strlen(buf);
    for (answer = 0; answer < 19; answer++)
      n[str][answer] = 0;

    for (answer = 0; answer <= str; answer++)
      n[answer][19] = 1;

    for (answer = str - 1; answer >= 0; answer--)
      for (draw = 18; draw >= 0; draw--)
    {
      n[answer][draw] = n[answer + 1][draw];
      if (phrase[draw] == buf[answer])
        n[answer][draw] = (n[answer][draw] + n[answer + 1][draw + 1]) % 10000;

    }


    printf("Case #%d: %04d\n", n, n[0][0]);
  }

  return 0;
}


