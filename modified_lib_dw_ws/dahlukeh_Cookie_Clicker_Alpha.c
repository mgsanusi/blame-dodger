#include <stdio.h>
#include <math.h>
double C;
double F;
double X;
void handle()
{
    int first_iteration;
    scanf("%lf %lf %lf ", &C, &F, &X);
    double p = ((F * X) - (F * C)) / C;
    double res = 0.0;
    double curR = 2.0;
    while (curR < p) {
	res += C / curR;
	curR += F;
    }
    res += X / curR;
    printf("%.7f\n", res);
}

int main()
{
    int first_iteration;
    int t;
    int i;
    scanf("%d ", &t);
    for (i = 0; i < t; i++) {
	printf("Case #%d: ", i + 1);
	handle();
    }
    return 0;
}
