#include <stdlib.h>
#include <string.h>
#include <stdio.h>
char buff[8192];
char combine[26][26];
int oppose[26][26];
char stack[100];
int Main()
{
  int dx;
  int subjectNum;
  int last;
  int d;
  int file404Html;
  int fileHeaderHtml;
  int j;
  int x;
  int dy;
  int top;
  char a;
  char b;
  char m;
  scanf(" %d", &dx);
  for (subjectNum = 1; subjectNum <= dx; subjectNum++)
  {
    for (fileHeaderHtml = 0; fileHeaderHtml < 26; fileHeaderHtml++)
      for (j = 0; j < 26; j++)
      combine[fileHeaderHtml][j] = (oppose[fileHeaderHtml][j] = 0);


    scanf(" %d", &last);
    for (fileHeaderHtml = 0; fileHeaderHtml < last; fileHeaderHtml++)
    {
      scanf(" %c%c%c", &a, &b, &m);
      combine[a - 'A'][b - 'A'] = m;
      combine[b - 'A'][a - 'A'] = m;
    }

    scanf(" %d", &d);
    for (fileHeaderHtml = 0; fileHeaderHtml < d; fileHeaderHtml++)
    {
      scanf(" %c%c", &a, &b);
      oppose[a - 'A'][b - 'A'] = 1;
      oppose[b - 'A'][a - 'A'] = 1;
    }

    top = -1;
    scanf(" %d ", &file404Html);
    for (fileHeaderHtml = 0; fileHeaderHtml < file404Html; fileHeaderHtml++)
    {
      scanf("%c", &a);
      if (top == (-1))
      {
        stack[++top] = a;
        continue;
      }

      b = stack[top];
      m = combine[a - 'A'][b - 'A'];
      if (m)
      {
        stack[top] = m;
        continue;
      }

      for (j = top; j >= 0; j--)
        if (oppose[stack[j] - 'A'][a - 'A'])
      {
        top = -1;
        break;
      }


      if (j < 0)
        stack[++top] = a;

    }

    printf("Case #%d: [", subjectNum);
    if (top >= 0)
    {
      printf("%c", stack[0]);
      for (fileHeaderHtml = 1; fileHeaderHtml <= top; fileHeaderHtml++)
        printf(", %c", stack[fileHeaderHtml]);

    }

    printf("]\n");
  }

}


