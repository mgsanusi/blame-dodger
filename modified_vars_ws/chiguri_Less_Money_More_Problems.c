#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int hot_temp;
double qv;
double x;
double c[100];
double bestb[100];
double second;
void clear(void)
{
	int minuts;
	int dx;
	for (minuts = 0; minuts < hot_temp; ++minuts) {
		if (bestb[minuts] <= x)
			break;
	}
	for (dx = 0; dx < hot_temp; ++dx) {
		if (bestb[dx] >= x)
			break;
	}
	if ((minuts == hot_temp) || (dx == hot_temp)) {
		second = -1.0f;
		return;
	}
	if ((bestb[0] == x) && (bestb[1] != x)) {
		second = qv / c[0];
	} else if ((bestb[0] != x) && (bestb[1] == x)) {
		second = qv / c[1];
	} else if ((bestb[0] == x) && (bestb[1] == x)) {
		second = qv / (c[0] + c[1]);
	} else {
		double v1 = ((bestb[0] - x) * qv) / (bestb[0] - bestb[1]);
		double v0 = qv - v1;
		double t0 = v0 / c[0];
		double y1 = v1 / c[1];
		if (t0 < y1)
			second = y1;
		else
			second = t0;
	}
}

void solve_and_print(void)
{
	int minuts;
	scanf("%d %lf %lf", &hot_temp, &qv, &x);
	for (minuts = 0; minuts < hot_temp; ++minuts) {
		scanf("%lf %lf", c + minuts, bestb + minuts);
	}
	second = 0.0f;
	clear();
	if (second < 0.0) {
		printf("IMPOSSIBLE\n");
	} else {
		printf("%.9lf\n", second);
	}
}

int Main(void)
{
	int dataset_num;
	int case_num;
	scanf("%d", &dataset_num);
	for (case_num = 1; case_num <= dataset_num; ++case_num) {
		printf("Case #%d: ", case_num);
		solve_and_print();
	}
	return 0;
}
