#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int Main()
{
  int c;
  int like;
  scanf("%d\n", &c);
  char data[30];
  int left[12];
  int num;
  int i;
  int cases;
  int prev;
  for (like = 0; like < c; like++)
  {
    gets(&data[1]);
    data[0] = '0';
    num = strlen(data);
    memset(left, 0, sizeof(left));
    for (i = 0; i < num; i++)
    {
      data[i] -= '0';
    }

    prev = -1;
    i = num - 1;
    while (1)
    {
      left[(int) data[i]]++;
      if (data[i] < prev)
        break;

      prev = data[i];
      i--;
    }

    cases = data[i] + 1;
    while (left[cases] == 0)
      cases++;

    data[i] = cases;
    left[(int) cases]--;
    i++;
    cases = 0;
    while (i < num)
    {
      while (left[cases] == 0)
        cases++;

      data[i] = cases;
      left[cases]--;
      i++;
    }

    printf("Case #%d: ", like + 1);
    i = 0;
    if (data[i] == 0)
      i++;

    while (i < num)
    {
      printf("%d", data[i]);
      i++;
    }

    printf("\n");
  }

  return 0;
}


