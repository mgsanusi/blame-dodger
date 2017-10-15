#include<stdio.h>
int t;
int T;
long double l;
long double rate;
long double C;
long double F;
long double X;
long double best_time;
long double cur_time;
int main()
{
    int first_iteration;
    scanf("%d", &T);
    for (t = 1; t <= T; t++) {
	scanf("%llf", &C);
	scanf("%llf", &F);
	scanf("%llf", &X);
	rate = 2.0;
	cur_time = 0.0;
	while ((X * rate) < ((X - C) * (F + rate))) {
	    cur_time += C / rate;
	    rate += F;
	}
	cur_time += X / rate;
	printf("Case #%d: ", t);
	printf("%.7llf\n", cur_time);
    }
    return 0;
}
