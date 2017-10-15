#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int l;
int x;
int input[10000];
int e1;
int f;
int num;
int sign;
int signMap[4][4] = {{1, 1, 1, 1}, {1, -1, 1, -1}, {1, -1, -1, 1}, {1, 1, -1, -1}};
int numMap[4][4] = {{0, 1, 2, 3}, {1, 0, 3, 2}, {2, 3, 0, 1}, {3, 2, 1, 0}};
int new_getchar();

void next(void)
{
  sign *= signMap[num][input[e1]];
  num = numMap[num][input[e1]];
  if ((++e1) == l)
  {
    e1 = 0;
    ++f;
  }

}

int get(int b)
{
  int limN = f + 8;
  int limP = e1;
  num = 0;
  sign = 1;
  while ((num != b) || (sign != 1))
  {
    if (f == x)
      return 0;

    if ((f == limN) && (e1 == limP))
      return 0;

    next();
  }

  return 1;
}

int search(void)
{
  if (!get(1))
    return 0;

  if (!get(2))
    return 0;

  if (!get(3))
    return 0;

  x = (x - f) % 8;
  if ((x == 0) && (e1 != 0))
    x = 8;

  f = 0;
  num = 0;
  sign = 1;
  while (f != x)
  {
    next();
  }

  if ((num != 0) || (sign != 1))
    return 0;

  return 1;
}

int Main(void)
{
  int datasetNo;
  int caseNum;
  int cs;
  int l;
  int y;
  int sign;
  int num;
  scanf("%d", &datasetNo);
  for (caseNum = 1; caseNum <= datasetNo; ++caseNum)
  {
    sign = 1;
    num = 0;
    e1 = 0;
    f = 0;
    scanf("%d %d", &l, &x);
    gets((char *) input);
    for (cs = 0; cs < l; ++cs)
    {
      input[cs] = new_getchar() - 'h';
    }

    printf("Case #%d: ", caseNum);
    if (search())
    {
      printf("YES\n");
    }
    else
    {
      printf("NO\n");
    }

  }

  return 0;
}



int new_getchar() {
  return getchar();
}