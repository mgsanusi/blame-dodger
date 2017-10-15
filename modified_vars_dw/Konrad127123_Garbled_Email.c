#include<stdio.h>
int t;
int t;
int pos;
int out[2048];
int n[2048];
int x[2048];
int done;
int x4;
int count;
void foo(int x4);
int Main()
{
  int first_iteration;
  scanf("%d", &t);
  for (t = 1; t <= t; t++)
  {
    scanf("%d", &pos);
    done = 0;
    for (x4 = 0; x4 < pos; x4++)
    {
      out[x4] = (n[x4] = (x[x4] = 0));
    }

    for (x4 = 0; x4 < pos; x4++)
    {
      scanf("%d", &out[x4]);
    }

    for (x4 = 0; x4 < pos; x4++)
    {
      scanf("%d", &n[x4]);
    }

    for (x4 = 0; x4 < pos; x4++)
    {
      x[0] = x4;
      done = 0;
      foo(1);
      if (done)
        break;

    }

    printf("Case #%d: ", t);
    for (x4 = 0; x4 < (pos - 1); x4++)
    {
      printf("%d ", x[x4] + 1);
    }

    printf("%d\n", x[pos - 1] + 1);
  }

  return 0;
}

void foo(int x4)
{
  int first_iteration;
  int good_a;
  int count;
  int r;
  int good_b;
  if (x4 == pos)
  {
    for (count = pos - 1; count >= 0; count--)
    {
      good_b = 1;
      for (r = count + 1; r < pos; r++)
      {
        if ((x[count] > x[r]) && (good_b <= n[r]))
          good_b = n[r] + 1;

      }

      if (good_b != n[count])
        return;

    }

    done = 1;
    return;
  }

  for (x[x4] = 0; x[x4] < pos; x[x4]++)
  {
    good_a = 1;
    for (count = 0; count < x4; count++)
    {
      if ((x[count] < x[x4]) && (out[count] >= good_a))
        good_a = out[count] + 1;
      else
        if (x[x4] == x[count])
        break;


    }

    if (x4 != count)
      continue;

    if (out[x4] == good_a)
    {
      foo(x4 + 1);
      if (done)
        return;

    }

  }

}


