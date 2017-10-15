#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char f[50][4];
char xdrs[50][4];
char string[100000];
char stack[100000];
int stackNo;
int take[26];
int new_puts(const char *str);

int Main()
{
  int l;
  int subject;
  int point;
  int t2;
  int p;
  int k;
  int app;
  int arVersions;
  int length;
  char x;
  char l;
  scanf("%d", &subject);
  for (l = 1; l <= subject; ++l)
  {
    stackNo = 0;
    for (point = 0; point < 26; ++point)
      take[point] = 0;

    scanf("%d", &app);
    for (point = 0; point < app; ++point)
    {
      scanf("%s", f[point]);
    }

    scanf("%d", &arVersions);
    for (point = 0; point < arVersions; ++point)
    {
      scanf("%s", xdrs[point]);
    }

    scanf("%d", &length);
    scanf("%s", string);
    for (point = 0; point < length; ++point)
    {
      stack[stackNo++] = string[point];
      take[string[point] - 'A']++;
      while (stackNo >= 2)
      {
        x = stack[stackNo - 1];
        l = stack[stackNo - 2];
        for (t2 = 0; t2 < app; ++t2)
        {
          if (((x == f[t2][0]) && (l == f[t2][1])) || ((x == f[t2][1]) && (l == f[t2][0])))
          {
            stack[stackNo - 2] = f[t2][2];
            take[x - 'A']--;
            take[l - 'A']--;
            take[f[t2][2] - 'A']++;
            stackNo--;
            break;
          }

        }

        if (t2 >= app)
          break;

      }

      if (stackNo >= 2)
      {
        for (t2 = 0; t2 < arVersions; ++t2)
        {
          if (take[xdrs[t2][0] - 'A'] && take[xdrs[t2][1] - 'A'])
          {
            stackNo = 0;
            for (p = 0; p < 26; ++p)
              take[p] = 0;

            break;
          }

        }

      }

    }

    stack[stackNo] = '\0';
    printf("Case #%d: [", l);
    if (stackNo > 0)
    {
      printf("%c", stack[0]);
      for (point = 1; point < stackNo; ++point)
      {
        printf(", %c", stack[point]);
      }

    }

    new_puts("]");
  }

}



int new_puts(const char *str) {
  return puts(str);
}