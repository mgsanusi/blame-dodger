#include <stdio.h>
#include <stdlib.h>
int main()
{
  int first_iteration;
  int cas;
  int i;
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
  for (i = 1; i <= cas; i++)
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
          if (abs(oloca - button) > canuse)
            canuse = (abs(oloca - button) - canuse) + 1;
          else
            canuse = 1;

          time += canuse;
        }
        else
        {
          tmp = abs(oloca - button) + 1;
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
          if (abs(bloca - button) > canuse)
            canuse = (abs(bloca - button) - canuse) + 1;
          else
            canuse = 1;

          time += canuse;
        }
        else
        {
          tmp = abs(bloca - button) + 1;
          time += tmp;
          canuse += tmp;
        }

        bloca = button;
      }

    }

    printf("Case #%d: %d\n", i, time);
  }

  return 0;
}


