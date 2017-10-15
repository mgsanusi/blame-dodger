#include <stdio.h>
#include <stdlib.h>
void new_free(void *ptr);
int Main()
{
    int first_iteration;
    double *x;
    double *pTime;
    int num;
    int i;
    x = (double *) malloc((sizeof(double)) * 120000);
    pTime = (double *) malloc((sizeof(double)) * 120000);
    scanf("%d", &num);
    for (i = 0; i < num; i++) {
	int itwo;
	int t;
	int yy2;
	scanf("%d %d", &itwo, &t);
	for (yy2 = 0; yy2 < itwo; yy2++)
	    scanf("%lf", &x[yy2]);
	pTime[0] = 1.0;
	for (yy2 = 1; yy2 <= itwo; yy2++) {
	    pTime[yy2] = pTime[yy2 - 1] * x[yy2 - 1];
	}
	double good;
	double tmp;
	tmp = (t - itwo) + 1;
	tmp += (1 - pTime[itwo]) * (t + 1);
	good = tmp;
	for (yy2 = 1; yy2 <= itwo; yy2++) {
	    tmp = pTime[itwo - yy2] * ((((yy2 + t) - itwo) + 1) + yy2);
	    tmp +=
		(1 -
		 pTime[itwo - yy2]) * ((((((yy2 + t) - itwo) + 1) + yy2) +
					t) + 1);
	    if (good > tmp)
		good = tmp;
	}
	if (good > (t + 2))
	    good = t + 2;
	printf("Case #%d: %.10lf\n", i + 1, good);
    }
    new_free(pTime);
    new_free(x);
    return 0;
}

void new_free(void *ptr)
{
    return free(ptr);
}
