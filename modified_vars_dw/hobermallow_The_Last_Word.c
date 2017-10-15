#include<stdio.h>
void clean(char *y)
{
  int first_iteration;
  int i;
  for (i = 0; i < 30; i++)
    y[i] = '\0';

  return;
}

int Main()
{
  int first_iteration;
  int ans;
  int i;
  int tfree;
  int begin;
  int goal;
  int k;
  char tmp[16];
  char y[30];
  scanf("%d", &ans);
  for (i = 0; i < ans; i++)
  {
    clean(y);
    scanf("%s", tmp);
    begin = 14;
    goal = 14;
    y[14] = tmp[0];
    for (tfree = 1; tmp[tfree] != '\0'; tfree++)
    {
      if (tmp[tfree] > y[begin])
        y[--begin] = tmp[tfree];
      else
        if (tmp[tfree] < y[begin])
        y[++goal] = tmp[tfree];
      else
      {
        for (k = begin; y[k + 1] != '\0'; k++)
        {
          if (y[k] != y[k + 1])
            break;

        }

        if (y[k] > y[k + 1])
          y[--begin] = tmp[tfree];
        else
          y[++goal] = tmp[tfree];

      }


    }

    tmp[++goal] = '\0';
    printf("Case #%d: %s\n", i + 1, y + begin);
  }

  return 0;
}


