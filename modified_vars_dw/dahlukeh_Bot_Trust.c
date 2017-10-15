#include <stdio.h>
#include <stdlib.h>
int cur_ins[101][2];
void handle_case(void);
int Main()
{
  int first_iteration;
  freopen("bot.in", "r", stdin);
  freopen("bot.out", "w", stdout);
  int no_case;
  scanf("%d ", &no_case);
  int i_t;
  for (i_t = 0; i_t < no_case; i_t++)
  {
    printf("Case #%d: ", i_t + 1);
    handle_case();
  }

  return 0;
}

void handle_case(void)
{
  int first_iteration;
  int no_ins;
  scanf("%d ", &no_ins);
  int i_t;
  char person;
  for (i_t = 0; i_t < no_ins; i_t++)
  {
    scanf("%c %d ", &person, &cur_ins[i_t][1]);
    if (person == 'O')
    {
      cur_ins[i_t][0] = 0;
    }
    else
    {
      cur_ins[i_t][0] = 1;
    }

  }

  int time_take = 0;
  int cur_org = 1;
  int cur_blue = 1;
  int left_blue_time = 0;
  int left_orange_time = 0;
  int dis;
  for (i_t = 0; i_t < no_ins; i_t++)
  {
    if (cur_ins[i_t][0] == 0)
    {
      dis = abs(cur_ins[i_t][1] - cur_org);
      if (left_orange_time > dis)
      {
        time_take++;
        left_blue_time++;
      }
      else
      {
        time_take += (dis - left_orange_time) + 1;
        left_blue_time += (dis - left_orange_time) + 1;
      }

      left_orange_time = 0;
      cur_org = cur_ins[i_t][1];
    }
    else
    {
      dis = abs(cur_ins[i_t][1] - cur_blue);
      if (left_blue_time > dis)
      {
        time_take++;
        left_orange_time++;
      }
      else
      {
        time_take += (dis - left_blue_time) + 1;
        left_orange_time += (dis - left_blue_time) + 1;
      }

      left_blue_time = 0;
      cur_blue = cur_ins[i_t][1];
    }

  }

  printf("%d\n", time_take);
}


