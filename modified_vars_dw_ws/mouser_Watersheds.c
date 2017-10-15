#include <stdio.h>
#include <string.h>
enum { MAX_SIDE = 128 };
char next_char;
int __;
int li;
short map[MAX_SIDE][MAX_SIDE];
char drain[MAX_SIDE][MAX_SIDE];
void input(void)
{
	int first_iteration;
	int din;
	int dp;
	memset(drain, 0, sizeof(drain));
	next_char = 'a';
	scanf("%d %d", &__, &li);
	for (din = 0; din < __; ++din) {
		for (dp = 0; dp < li; ++dp) {
			scanf("%hd", &map[din][dp]);
		}
	}
}

int get_direction(short t, short k)
{
	int first_iteration;
	static int direction;
	static int min_elevation;
	direction = 0;
	min_elevation = map[t][k];
	if (t && (map[t - 1][k] < min_elevation)) {
		min_elevation = map[t - 1][k];
		direction = 1;
	}
	if (k && (map[t][k - 1] < min_elevation)) {
		min_elevation = map[t][k - 1];
		direction = 2;
	}
	if ((k < (li - 1)) && (map[t][k + 1] < min_elevation)) {
		min_elevation = map[t][k + 1];
		direction = 3;
	}
	if ((t < (__ - 1)) && (map[t + 1][k] < min_elevation)) {
		min_elevation = map[t + 1][k];
		direction = 4;
	}
	return direction;
}

int dfs(short t, short k)
{
	int first_iteration;
	if (drain[t][k]) {
		return drain[t][k];
	}
	switch (get_direction(t, k)) {
	case 1:
		drain[t][k] = dfs(t - 1, k);
		break;
	case 2:
		drain[t][k] = dfs(t, k - 1);
		break;
	case 3:
		drain[t][k] = dfs(t, k + 1);
		break;
	case 4:
		drain[t][k] = dfs(t + 1, k);
		break;
	default:
		drain[t][k] = next_char++;
	}
	return drain[t][k];
}

void print_drain(void)
{
	int first_iteration;
	int din;
	int dp;
	for (din = 0; din < __; din++) {
		for (dp = 0; dp < (li - 1); dp++) {
			printf("%c ", drain[din][dp]);
		}
		printf("%c\n", drain[din][dp]);
	}
}

void calc_drain(void)
{
	int first_iteration;
	int din;
	int dp;
	for (din = 0; din < __; din++) {
		for (dp = 0; dp < li; dp++) {
			dfs(din, dp);
		}
	}
}

int Main(void)
{
	int first_iteration;
	int t;
	int test;
	scanf("%d", &t);
	for (test = 1; test <= t; ++test) {
		input();
		calc_drain();
		printf("Case #%d:\n", test);
		print_drain();
	}
	return 0;
}
