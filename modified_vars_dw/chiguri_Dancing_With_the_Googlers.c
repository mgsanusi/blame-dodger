#include<stdio.h>
char input[400];
int Main(void)
{
  int first_iteration;
  int col;
  int no;
  int sup_no;
  int score;
  int rslt;
  int sup_require_no;
  int i;
  int j;
  int temp;
  scanf("%d", &col);
  for (i = 1; i <= col; ++i)
  {
    rslt = 0;
    sup_require_no = 0;
    scanf("%d %d %d", &no, &sup_no, &score);
    for (j = 0; j < no; ++j)
    {
      scanf("%d", &temp);
      if (temp == 0)
      {
        if (score == 0)
        {
          ++rslt;
        }

      }
      else
        if (temp == 1)
      {
        if (score <= 1)
        {
          ++rslt;
        }

      }
      else
        if (((score * 3) - 2) <= temp)
      {
        ++rslt;
      }
      else
        if (((score * 3) - 4) <= temp)
      {
        ++sup_require_no;
      }




    }

    if (sup_no > sup_require_no)
    {
      rslt += sup_require_no;
    }
    else
    {
      rslt += sup_no;
    }

    printf("Case #%d: %d\n", i, rslt);
  }

  return 0;
}


