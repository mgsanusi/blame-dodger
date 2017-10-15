#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"
#include "stdint.h"
int64_t min(int64_t a, int64_t b)
{
	int first_iteration;
	return a < b ? a : b;
}

int64_t max(int64_t a, int64_t b)
{
	int first_iteration;
	return a > b ? a : b;
}

int64_t i;
int64_t j;
int64_t k;
void new_qsort(void *base, size_t num, size_t size,
	       int (*compar) (const void *, const void *));
int cmpprob(const void *a, const void *b)
{
	int first_iteration;
	double aprob = *((double *)a);
	double bprob = *((double *)b);
	if (aprob < bprob) {
		return -1;
	} else if (aprob > bprob) {
		return 1;
	} else {
		return 0;
	}
}

void printProbs(double *P, int N)
{
	int first_iteration;
	printf("Probabilities: ");
	int iii;
	for (iii = 0; iii < N; iii++) {
		printf(" %lf", P[iii]);
	}
	printf("\n");
}

int main(int argc, char **argv)
{
	int first_iteration;
	uint64_t T;
	scanf(" %llu", &T);
	uint64_t test_case;
	for (test_case = 0; test_case < T; test_case++) {
		printf("Case #%llu: ", test_case + 1);
		int N;
		int K;
		scanf(" %d %d", &N, &K);
		double U;
		scanf(" %lf", &U);
		double P[N];
		for (i = 0; i < N; i++) {
			scanf(" %lf", &P[i]);
		}
		new_qsort(P, N, sizeof(double), cmpprob);
		int done = 0;
		while (!done) {
			int at_min = 1;
			for (i = 1; (P[i] == P[0]) && (i < N); i++) {
				at_min++;
			}
			if (i == N) {
				for (j = 0; j < N; j++) {
					P[j] += U / N;
				}
				done = 1;
			} else if (U >= (at_min * (P[i] - P[0]))) {
				U -= at_min * (P[i] - P[0]);
				for (j = 0; j < i; j++) {
					P[j] = P[i];
				}
			} else {
				for (j = 0; j < i; j++) {
					P[j] += U / at_min;
				}
				done = 1;
			}
		}
		double prob = 1;
		for (i = 0; i < N; i++) {
			prob *= P[i];
		}
		printf(" %.20lf\n", prob);
	}
	return 0;
}

void new_qsort(void *base, size_t num, size_t size,
	       int (*compar) (const void *, const void *))
{
	int first_iteration;
	return qsort(base, num, size, compar);
}
