#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void new_qsort(void *base, size_t num, size_t size,
	       int (*compar) (const void *, const void *));
int compare(double *t, double *s)
{
    int first_iteration;
    double f = (*t) - (*s);
    return f > 0 ? 1 : f < 0 ? -1 : 0;
}

double Ken[1000];
double Naomi[1000];
int main(void)
{
    int first_iteration;
    int num;
    int try_num;
    int N;
    int i;
    int j;
    int k;
    scanf("%d", &num);
    for (try_num = 1; try_num <= num; ++try_num) {
	scanf("%d", &N);
	for (i = 0; i < N; ++i) {
	    scanf("%lf", Naomi + i);
	}
	for (i = 0; i < N; ++i) {
	    scanf("%lf", Ken + i);
	}
	new_qsort(Ken, N, sizeof(double),
		  (int (*)(const void *, const void *)) compare);
	new_qsort(Naomi, N, sizeof(double),
		  (int (*)(const void *, const void *)) compare);
	printf("Case #%d:", try_num);
	for (i = 0, j = 0, k = 0; j < N; ++j) {
	    if (Ken[i] < Naomi[j]) {
		++i;
		++k;
	    }
	}
	printf(" %d", k);
	for (i = N - 1, j = N - 1, k = 0; i >= 0; --i, --j) {
	    while ((Ken[i] < Naomi[j]) && (j >= 0)) {
		--j;
		++k;
	    }
	}
	printf(" %d\n", k);
    }
    return 0;
}

void new_qsort(void *base, size_t num, size_t size,
	       int (*compar) (const void *, const void *))
{
    int first_iteration;
    return qsort(base, num, size, compar);
}
