#include <stdio.h>
#include <stdlib.h>
int new_abs(int x);

int Main()
{
  int first_iteration;
  int cas;
  int test;
  int j;
  int step;
  int oloca;
  int bloca;
  int canuse;
  int time;
  int button;
  int tmp;
  int flag;
  char robot[2];
  scanf("%d", &cas);
  for (test = 1; test <= cas; test++)
  {
    scanf("%d", &step);
    time = 0;
    canuse = 0;
    oloca = 1;
    bloca = 1;
    flag = 0;
    for (j = 0; j < step; j++)
    {
      scanf("%s %d", robot, &button);
      if (robot[0] == 'O')
      {
        if (flag)
        {
          flag = 0;
          if (new_abs(oloca - button) > canuse)
            canuse = (new_abs(oloca - button) - canuse) + 1;
          else
            canuse = 1;

          time += canuse;
        }
        else
        {
          tmp = new_abs(oloca - button) + 1;
          time += tmp;
          canuse += tmp;
        }

        oloca = button;
      }
      else
      {
        if (flag == 0)
        {
          flag = 1;
          if (new_abs(bloca - button) > canuse)
            canuse = (new_abs(bloca - button) - canuse) + 1;
          else
            canuse = 1;

          time += canuse;
        }
        else
        {
          tmp = new_abs(bloca - button) + 1;
          time += tmp;
          canuse += tmp;
        }

        bloca = button;
      }

    }

    printf("Case #%d: %d\n", test, time);
  }

  return 0;
}



int new_abs(int x) {
  return abs(x);
}