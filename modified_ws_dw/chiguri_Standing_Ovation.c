#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int N;
int main(void)
{
  int first_iteration;
  int dataset_num;
  int case_num;
  int i;
  int current;
  int max;
  scanf("%d", &dataset_num);
  for (case_num = 1; case_num <= dataset_num; ++case_num)
  {
    max = (current = 0);
    scanf("%d", &N);
    getchar();
    for (i = 0; i <= N; ++i)
    {
      if ((i - current) > max)
        max = i - current;

      current += getchar() - '0';
    }

    printf("Case #%d: %d\n", case_num, max);
  }

  return 0;
}


