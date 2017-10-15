#include<stdio.h>
#include<stdlib.h>
int N;
int c;
int t;
int T;
int X;
int foo[1024];
int old_min;
int min;
int position;
int left_free;
int right_free;
int ans;
int a;
int b;
int main()
{
  int first_iteration;
  scanf("%d", &T);
  for (t = 1; t <= T; t++)
  {
    scanf("%d", &N);
    for (c = 0; c < N; c++)
    {
      scanf("%d", &foo[c]);
    }

    ans = 0;
    old_min = -1;
    left_free = 0;
    right_free = N - 1;
    for (a = 0; a < N; a++)
    {
      min = 1000000001;
      for (c = left_free; c <= right_free; c++)
      {
        if (foo[c] > old_min)
          if (foo[c] < min)
        {
          min = foo[c];
          position = c;
        }


      }

      if (abs(position - left_free) < abs(right_free - position))
      {
        for (b = position; b > left_free; b--)
        {
          foo[b] = foo[b - 1];
        }

        foo[left_free] = min;
        ans += position - left_free;
        left_free++;
      }
      else
      {
        for (b = position; b < right_free; b++)
        {
          foo[b] = foo[b + 1];
        }

        foo[right_free] = min;
        ans += right_free - position;
        right_free--;
      }

      old_min = min;
    }

    printf("Case #%d: %d\n", t, ans);
  }

  return 0;
}


