#include <stdlib.h>
#include <string.h>
#include <stdio.h>
int abs(int tmp)
{
	if (tmp < 0)
		return -tmp;
	return tmp;
}

int Main()
{
	int b;
	int case_num;
	int good;
	int a_pos;
	int b_pos;
	int a_split;
	int b_split;
	int time;
	int target;
	int distance;
	int travel;
	char case_t;
	char b = 'O';
	scanf(" %d", &b);
	for (case_num = 1; case_num <= b; case_num++) {
		a_pos = (b_pos = 1);
		a_split = (b_split = (time = 0));
		scanf(" %d", &good);
		while ((good--) > 0) {
			scanf(" %c %d", &case_t, &target);
			if (case_t == b) {
				distance = abs(a_pos - target);
				travel = distance - (time - a_split);
				if (travel < 0)
					travel = 0;
				time += travel + 1;
				a_split = time;
				a_pos = target;
			} else {
				distance = abs(b_pos - target);
				travel = distance - (time - b_split);
				if (travel < 0)
					travel = 0;
				time += travel + 1;
				b_split = time;
				b_pos = target;
			}
		}
		printf("Case #%d: %d\n", case_num, time);
	}
}
