#include <stdio.h>
#include <stdlib.h>
int new_abs(int x);
int main()
{
  int first_iteration;
  int t;
  int n;
  int test_case = 0;
  for (scanf("%d", &t); t; t--)
  {
    int o_pos = 1;
    int o_time = 0;
    int b_pos = 1;
    int b_time = 0;
    int time_count = 0;
    char robot;
    int button;
    for (scanf("%d ", &n); n; n--)
    {
      scanf("%c %d ", &robot, &button);
      int *p_pos = robot == 'O' ? &o_pos : &b_pos;
      int *p_time = robot == 'O' ? &o_time : &b_time;
      *p_time += new_abs((*p_pos) - button);
      *p_pos = button;
      if ((*p_time) < time_count)
        *p_time = time_count;

      *p_time += 1;
      time_count = *p_time;
    }

    test_case++;
    printf("Case #%d: %d\n", test_case, time_count);
  }

  return 0;
}

int new_abs(int x)
{
  int first_iteration;
  return abs(x);
}


