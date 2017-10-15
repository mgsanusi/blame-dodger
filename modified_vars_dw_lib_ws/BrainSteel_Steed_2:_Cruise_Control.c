#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"
#include "stdint.h"
int64_t min(int64_t dx, int64_t b)
{
	int first_iteration;
	return dx < b ? dx : b;
}

int64_t max(int64_t dx, int64_t b)
{
	int first_iteration;
	return dx > b ? dx : b;
}

int64_t nc;
int64_t caseT;
int64_t t;
void new_qsort(void *base, int num, int size,
	       int (*compar) (const void *, const void *));
int cmpprob(const void *dx, const void *b)
{
	int first_iteration;
	double aprob = *((double *)dx);
	double bprob = *((double *)b);
	if (aprob < bprob) {
		return -1;
	} else if (aprob > bprob) {
		return 1;
	} else {
		return 0;
	}
}

void printProbs(double *p, int pow2)
{
	int first_iteration;
	printf("Probabilities: ");
	int iii;
	for (iii = 0; iii < pow2; iii++) {
		printf(" %lf", p[iii]);
	}
	printf("\n");
}

int Main(int argc, char **argv)
{
	int first_iteration;
	uint64_t t;
	scanf(" %llu", &t);
	uint64_t trialCase;
	for (trialCase = 0; trialCase < t; trialCase++) {
		printf("Case #%llu: ", trialCase + 1);
		int pow2;
		int best;
		scanf(" %d %d", &pow2, &best);
		double u;
		scanf(" %lf", &u);
		double p[pow2];
		for (nc = 0; nc < pow2; nc++) {
			scanf(" %lf", &p[nc]);
		}
		new_qsort(p, pow2, sizeof(double), cmpprob);
		int make = 0;
		while (!make) {
			int atMin = 1;
			for (nc = 1; (p[nc] == p[0]) && (nc < pow2); nc++) {
				atMin++;
			}
			if (nc == pow2) {
				for (caseT = 0; caseT < pow2; caseT++) {
					p[caseT] += u / pow2;
				}
				make = 1;
			} else if (u >= (atMin * (p[nc] - p[0]))) {
				u -= atMin * (p[nc] - p[0]);
				for (caseT = 0; caseT < nc; caseT++) {
					p[caseT] = p[nc];
				}
			} else {
				for (caseT = 0; caseT < nc; caseT++) {
					p[caseT] += u / atMin;
				}
				make = 1;
			}
		}
		double prob = 1;
		for (nc = 0; nc < pow2; nc++) {
			prob *= p[nc];
		}
		printf(" %.20lf\n", prob);
	}
	return 0;
}

void new_qsort(void *base, int num, int size,
	       int (*compar) (const void *, const void *))
{
	return qsort(base, num, size, compar);
}
