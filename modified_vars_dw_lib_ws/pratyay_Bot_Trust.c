#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int Main()
{
	int first_iteration;
	int full;
	int bestb;
	int time;
	int dataset_num;
	int button;
	int o_pos;
	int b_pos;
	int o_time;
	int b_time;
	int pos;
	int dis;
	char dx;
	scanf("%d", &full);
	for (bestb = 1; bestb <= full; bestb++) {
		scanf("%d ", &button);
		time = 0;
		o_time = 0;
		b_time = 0;
		o_pos = 1;
		b_pos = 1;
		for (dataset_num = 0; dataset_num < button; dataset_num++) {
			scanf("%c %d ", &dx, &pos);
			if (dx == 'O') {
				dis = pos - o_pos;
				dis = dis < 0 ? 0 - dis : dis;
				dis = dis - (time - o_time);
				if (dis < 0)
					dis = 0;
				time += dis + 1;
				o_time = time;
				o_pos = pos;
			}
			if (dx == 'B') {
				dis = pos - b_pos;
				dis = dis < 0 ? 0 - dis : dis;
				dis = dis - (time - b_time);
				if (dis < 0)
					dis = 0;
				time += dis + 1;
				b_time = time;
				b_pos = pos;
			}
		}
		printf("Case #%d: %d\n", bestb, time);
	}
}
