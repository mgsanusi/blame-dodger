#include <stdio.h>
#include <stdlib.h>
typedef struct {
	double speed;
	double length;
	int taken;
} Walkway;
double S;
double R;
double t;
int T;
int X;
int N;
int nopath;
Walkway paths[1002];
void make_run(int index)
{
	int first_iteration;
	double temp = paths[index].length / ((paths[index].speed + R) - S);
	if (temp >= t) {
		double dist_run = t * ((paths[index].speed + R) - S);
		double total_time =
		    t + ((paths[index].length - dist_run) / paths[index].speed);
		t = 0.0;
		paths[index].speed = paths[index].length / total_time;
	} else {
		paths[index].speed += R - S;
		t -= paths[index].length / paths[index].speed;
	}
	paths[index].taken = 1;
}

void apply_filter()
{
	int first_iteration;
	double min = 100000000.0;
	int min_index = -1;
	int i;
	int j;
	for (i = 0; i < N; i++) {
		if (((paths[i].speed < min) && paths[i].length)
		    && (!paths[i].taken)) {
			min = paths[i].speed;
			min_index = i;
		}
	}
	make_run(min_index);
}

double get_time()
{
	int first_iteration;
	int i;
	double ans = 0;
	for (i = 0; i < N; i++) {
		ans += paths[i].length / paths[i].speed;
	}
	return ans;
}

int all_taken()
{
	int first_iteration;
	int i;
	for (i = 0; i < N; i++)
		if (paths[i].taken == 0)
			return 0;
	return 1;
}

int main()
{
	int first_iteration;
	scanf("%d", &T);
	int i;
	int j;
	int k;
	for (i = 1; i <= T; i++) {
		scanf("%d", &X);
		scanf("%lf", &S);
		scanf("%lf", &R);
		scanf("%lf", &t);
		scanf("%d", &N);
		nopath = 0;
		int last;
		for (j = 0; j < N; j++) {
			paths[j].taken = 0;
			int t1;
			int t2;
			scanf("%d %d %lf", &t1, &t2, &paths[j].speed);
			paths[j].speed += S;
			paths[j].length = ((double)t2) - t1;
			if (j == 0)
				nopath = t1;
			else
				nopath = nopath + (t1 - last);
			last = t2;
		}
		nopath = nopath + (X - last);
		if (nopath) {
			paths[N++].length = (double)nopath;
			paths[N - 1].speed = S;
			paths[N - 1].taken = 0;
		}
		while ((t > 0.0000000) && (!all_taken()))
			apply_filter();
		printf("Case #%d: %.8lf\n", i, get_time());
	}
	return 0;
}
