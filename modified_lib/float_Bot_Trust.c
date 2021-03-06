#include <stdio.h>
#include <stdlib.h>

#define N 110
int new_abs(int x);


int main()
{
	int cas, i, j, step, oloca, bloca, canuse, time, button, tmp, flag;
	char robot[2];
	scanf("%d", &cas);
	for(i=1; i<=cas; i++)
	{
		scanf("%d", &step);
		time = 0;
		canuse = 0;
		oloca = 1;
		bloca = 1;
		flag = 0;
		for(j=0; j<step; j++)
		{
			scanf("%s %d", robot, &button);
			if(robot[0] == 'O')
			{
				if(flag)
				{
					flag = 0;
					if(new_abs(oloca - button) > canuse)
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
				if(flag == 0)
				{
					flag = 1;
					if(new_abs(bloca - button) > canuse)
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
		printf("Case #%d: %d\n", i, time);
	}
	return 0;
}

int new_abs(int x) {
  return abs(x);
}