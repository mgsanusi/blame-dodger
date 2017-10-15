#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int n;
int rs[10000];
int Main(void)
{
  int dataset_num;
  int case_num;
  int tn;
  int lol;
  int y;
  int acc;
  scanf("%d", &dataset_num);
  for (case_num = 1; case_num <= dataset_num; ++case_num)
  {
    acc = 0;
    scanf("%d", &n);
    for (tn = 0; tn < n; ++tn)
    {
      scanf("%d", rs + tn);
    }

    printf("Case #%d: ", case_num);
    for (tn = 1; tn < n; ++tn)
    {
      if (rs[tn - 1] > rs[tn])
        acc += rs[tn - 1] - rs[tn];

    }

    printf("%d ", acc);
    for (lol = 0; lol < 10000; ++lol)
    {
      int input_file_ptr = 1;
      for (tn = 1; tn < n; ++tn)
      {
        if ((rs[tn - 1] - lol) > rs[tn])
        {
          input_file_ptr = 0;
          break;
        }

      }

      if (input_file_ptr)
        break;

    }

    acc = 0;
    for (tn = 1; tn < n; ++tn)
    {
      if ((rs[tn - 1] - lol) < 0)
        acc += rs[tn - 1];
      else
        acc += lol;

    }

    printf("%d\n", acc);
  }

  return 0;
}


