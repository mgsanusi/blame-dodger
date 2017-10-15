#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int number[21];
int count[10];
int digit;
char n[21];
char result[21];
void preProc()
{
  int test;
  memset(number, 0, sizeof(number));
  memset(count, 0, sizeof(count));
  memset(result, 0, sizeof(result));
  for (test = 0; test < strlen(n); test++)
  {
    number[test] = n[test] - '0';
    count[number[test]]++;
  }

  digit = strlen(n);
}

int special()
{
  int test;
  int k;
  for (test = 0; test < (digit - 1); test++)
  {
    if (number[test] < number[test + 1])
    {
      return 0;
    }

  }

  test = 1;
  while (!count[test++])
    ;

  test--;
  count[test]--;
  printf("%d0", test);
  for (test = 0; test <= 9; test++)
  {
    while ((count[test]--) > 0)
      printf("%d", test);

  }

  printf("\n");
  return 1;
}

int rec(int w)
{
  int test;
  int k;
  int flag;
  if (w >= digit)
  {
    return 0;
  }

  flag = 1;
  for (test = w; (test < (digit - 1)) && flag; test++)
  {
    flag = flag && (number[test] >= number[test + 1]);
  }

  if (flag)
  {
    return 1;
  }

  count[number[w]]--;
  if (rec(w + 1))
  {
    count[number[w]]++;
    test = number[w];
    while (!count[++test])
      ;

    result[w] = ((char) test) + '0';
    count[test]--;
    k = 1;
    for (test = 0; test <= 9; test++)
    {
      while (count[test] > 0)
      {
        result[k + w] = ((char) test) + '0';
        count[test]--;
        k++;
      }

    }

  }
  else
  {
    result[w] = n[w];
  }

  return 0;
}

void singleCase()
{
  gets(n);
  preProc();
  if (special())
  {
    return;
  }

  rec(0);
  printf("%s\n", result);
}

int Main()
{
  int test;
  int subject;
  scanf("%d\n", &subject);
  for (test = 1; test <= subject; test++)
  {
    printf("Case #%d: ", test);
    singleCase();
  }

  return 0;
}


