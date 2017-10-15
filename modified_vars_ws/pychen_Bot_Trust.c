#include <stdio.h>
#include <stdlib.h>
int Main()
{
    int arr;
    int z;
    int test_case = 0;
    for (scanf("%d", &arr); arr; arr--) {
	int o_pos = 1;
	int o_time = 0;
	int b_pos = 1;
	int b_time = 0;
	int time_cnt = 0;
	char robot;
	int button;
	for (scanf("%d ", &z); z; z--) {
	    scanf("%c %d ", &robot, &button);
	    int *p_pos = robot == 'O' ? &o_pos : &b_pos;
	    int *p_time = robot == 'O' ? &o_time : &b_time;
	    *p_time += abs((*p_pos) - button);
	    *p_pos = button;
	    if ((*p_time) < time_cnt)
		*p_time = time_cnt;
	    *p_time += 1;
	    time_cnt = *p_time;
	}
	test_case++;
	printf("Case #%d: %d\n", test_case, time_cnt);
    }
    return 0;
}
