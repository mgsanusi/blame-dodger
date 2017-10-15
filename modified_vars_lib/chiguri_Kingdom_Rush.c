#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int buttonColorList[10000];
int t[10000];
int goal;
int n;
void search(int cur, int pos, int reach)
{
  int j;
  if ((pos + reach) >= goal)
  {
    goal = -1;
    return;
  }

  int temp;
  for (j = cur + 1; j < n; ++j)
  {
    if (buttonColorList[j] > (pos + reach))
    {
      break;
    }

    temp = buttonColorList[j] - pos;
    if (temp > t[j])
      temp = t[j];

    search(j, buttonColorList[j], temp);
    if (goal < 0)
      return;

  }

  return;
}

int Main(void)
{
  int no;
  int i;
  int j;
  int str;
  int reach;
  int pos;
  int cur;
  int tempPos;
  int tempReach;
  scanf("%d", &no);
  for (i = 1; i <= no; ++i)
  {
    scanf("%d", &n);
    for (j = 0; j < n; ++j)
    {
      scanf("%d %d", buttonColorList + j, t + j);
    }

    scanf("%d", &goal);
    pos = buttonColorList[0];
    reach = buttonColorList[0];
    cur = 0;
    search(0, buttonColorList[0], buttonColorList[0]);
    printf("Case #%d: ", i);
    if (goal < 0)
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


