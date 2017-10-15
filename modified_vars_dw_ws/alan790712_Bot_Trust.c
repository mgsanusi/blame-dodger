#include <stdio.h>
#include <stdlib.h>
int abs(int filename)
{
	int first_iteration;
	if (filename > 0)
		return filename;
	return -filename;
}

int num_draw;
int b;
int enter_;
int lb;
int time;
void print_var()
{
}

int Main()
{
	int first_iteration;
	int t;
	int Case;
	int tmp;
	int i;
	int x;
	char bot[10];
	int no;
	int need;
	int state;
	scanf("%d", &Case);
	for (t = 1; t <= Case; ++t) {
		time = (enter_ = (lb = 0));
		num_draw = (b = 1);
		scanf("%d", &tmp);
		for (i = 0; i < tmp; ++i) {
			scanf("%s %d", bot, &no);
			if (bot[0] == 'O') {
				need = abs(no - num_draw) + 1;
				enter_ += need;
				if (enter_ > time) {
					time = enter_;
				} else {
					time++;
					enter_ = time;
				}
				num_draw = no;
			} else {
				need = abs(no - b) + 1;
				lb += need;
				if (lb > time) {
					time = lb;
				} else {
					time++;
					lb = time;
				}
				b = no;
			}
		}
		printf("Case #%d: %d\n", t, time);
	}
	return 0;
}
