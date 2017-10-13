#include <stdio.h>
#include <math.h>

#define EP          0.00000001

double C, F, X;

void handle() {
    scanf ("%lf %lf %lf ", &C, &F, &X);
    double p = (F * X - F * C) / C;
    double res = 0.0;
    double curR = 2.0;
    while (curR < p) {
        res += C / curR;
        curR += F;
    }
    res += X / curR;
    printf("%.7f\n", res);
}

int main() {
    int t, i;
    scanf ("%d ", &t);
    for (i = 0; i < t; i++) {
        printf("Case #%d: ", i + 1);
        handle();
    }
    return 0;
}