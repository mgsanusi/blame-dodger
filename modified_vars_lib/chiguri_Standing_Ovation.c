#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int length;
int new_getchar();

int Main(void)
{
  int dataset_num;
  int case_num;
  int pd;
  int curr;
  int max;
  scanf("%d", &dataset_num);
  for (case_num = 1; case_num <= dataset_num; ++case_num)
  {
    max = (curr = 0);
    scanf("%d", &length);
    new_getchar();
    for (pd = 0; pd <= length; ++pd)
    {
      if ((pd - curr) > max)
        max = pd - curr;

      curr += new_getchar() - '0';
    }

    printf("Case #%d: %d\n", case_num, max);
  }

  return 0;
}



int new_getchar() {
  return getchar();
}