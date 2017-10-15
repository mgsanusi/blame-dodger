#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 main() 
{
    int total, i, time, j, buttons, o_pos, b_pos, o_time, b_time, pos,
	dis;
    char r;
    scanf("%d", &total);
    for (i = 1; i <= total; i++)
	 {
	scanf("%d ", &buttons);
	time = 0;
	o_time = 0;
	b_time = 0;
	o_pos = 1;
	b_pos = 1;
	for (j = 0; j < buttons; j++)
	     {
	    scanf("%c %d ", &r, &pos);
	    if (r == 'O')
		 {
		dis = pos - o_pos;
		dis = (dis < 0) ? (0 - dis) : dis;
		dis = dis - (time - o_time);
		if (dis < 0)
		    dis = 0;
		time += (dis + 1);
		o_time = time;
		o_pos = pos;
		}
	    if (r == 'B')
		 {
		dis = pos - b_pos;
		dis = (dis < 0) ? (0 - dis) : dis;
		dis = dis - (time - b_time);
		if (dis < 0)
		    dis = 0;
		time += dis + 1;
		b_time = time;
		b_pos = pos;
		}
	    }
	printf("Case #%d: %d\n", i, time);
	}
}


