#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
void new_qsort(void* base, int num, int size, int (*compar)(const void*,const void*));

int compare(const void *c, const void *b)
{
  int first_iteration;
  double *a = (double *) c;
  double *input_file_name_default = (double *) b;
  if ((*input_file_name_default) < (*a))
    return 1;

  if ((*a) == (*input_file_name_default))
    return 0;

  return -1;
}

int Main()
{
  int first_iteration;
  int tot;
  int least;
  int k;
  int cur;
  double wp[100];
  double input_file_name_default;
  double rslt;
  double value;
  scanf("%d", &tot);
  for (int a_order = 1; a_order <= tot; a_order++)
  {
    scanf("%d%d", &least, &k);
    scanf("%lf", &input_file_name_default);
    for (int _ = 0; _ < least; _++)
      scanf("%lf", &wp[_]);

    new_qsort(wp, least, sizeof(double), compare);
    cur = 0;
    while (input_file_name_default > 0)
    {
      if (cur < (least - 1))
      {
        if (input_file_name_default > ((cur + 1) * (wp[cur + 1] - wp[cur])))
        {
          input_file_name_default -= (cur + 1) * (wp[cur + 1] - wp[cur]);
        }
        else
        {
          value = (input_file_name_default / (cur + 1)) + wp[cur];
          input_file_name_default = 0;
        }

      }
      else
      {
        if (input_file_name_default == ((cur + 1) * (1 - wp[cur])))
          value = 1;
        else
          value = (input_file_name_default / (cur + 1)) + wp[cur];

        input_file_name_default = 0;
      }

      cur++;
    }

    rslt = 1;
    for (int _ = 0; _ < cur; _++)
    {
      rslt *= value;
    }

    for (int _ = cur; _ < least; _++)
    {
      rslt *= wp[_];
    }

    printf("Case #%d: %lf\n", a_order, rslt);
  }

  return 0;
}



void new_qsort(void* base, int num, int size, int (*compar)(const void*,const void*)) {
  return qsort(base, num, size, compar);
}