#include <stdio.h>
char robot_id[100];
int robot_pts[100];
int main(void)
{
  int first_iteration;
  int i = 0;
  int k = 0;
  long j = 0;
  long current_ans = 0;
  int no_tests = 0;
  int current_no_pts = 0;
  int current_ptr = 0;
  int robo_location;
  int robb_location;
  scanf("%d", &no_tests);
  for (i = 0; i < no_tests; i++)
  {
    scanf("%d", &current_no_pts);
    for (j = 0; j < current_no_pts; j++)
    {
      scanf(" %c", &robot_id[j]);
      scanf(" %d", &robot_pts[j]);
    }

    current_ans = 0;
    current_ptr = 0;
    robo_location = 1;
    robb_location = 1;
    j = 0;
    while (1)
    {
      if (current_ptr == current_no_pts)
      {
        current_ans = j;
        printf("Case #%d: %ld\n", i + 1, current_ans);
        break;
      }

      if (robot_id[current_ptr] == 'O')
      {
        if (robot_pts[current_ptr] < robo_location)
          robo_location--;
        else
          if (robot_pts[current_ptr] > robo_location)
          robo_location++;
        else
          if (robot_pts[current_ptr] == robo_location)
        {
          robot_pts[current_ptr] = 0;
          current_ptr++;
        }



        for (k = current_ptr; (robot_id[k] == 'O') && (k != current_no_pts); k++)
          ;

        if (k != current_no_pts)
        {
          if (robot_pts[k] < robb_location)
            robb_location--;
          else
            if (robot_pts[k] > robb_location)
            robb_location++;


        }

      }
      else
      {
        if (robot_pts[current_ptr] < robb_location)
          robb_location--;
        else
          if (robot_pts[current_ptr] > robb_location)
          robb_location++;
        else
          if (robot_pts[current_ptr] == robb_location)
        {
          robot_pts[current_ptr] = 0;
          current_ptr++;
        }



        for (k = current_ptr; (robot_id[k] == 'B') && (k != current_no_pts); k++)
          ;

        if (k != current_no_pts)
        {
          if (robot_pts[k] < robo_location)
            robo_location--;
          else
            if (robot_pts[k] > robo_location)
            robo_location++;


        }

      }

      j++;
    }

  }

  return 1;
}


