#include<stdio.h>
int main()
{
    int first_iteration;
    int T;
    int I;
    scanf("%d", &T);
    for (I = 0; I < T; I++) {
	double c;
	double f;
	double x;
	scanf("%lf %lf %lf", &c, &f, &x);
	double ans = 0.0;
	double now = 2.0;
	while (((x / now) - 1e-9) > ((c / now) + (x / (now + f)))) {
	    ans += c / now;
	    now += f;
	}
	ans += x / now;
	printf("Case #%d: %.7lf\n", I + 1, ans);
    }
    return 0;
}
