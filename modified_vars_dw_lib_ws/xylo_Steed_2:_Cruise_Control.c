#include <stdio.h>
#include <string.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
void *new_calloc(int num, int size);
double auxSmall(int t, int *b, int *xdrs, int **l, int k, int p, int eLeft,
		int currS)
{
	int first_iteration;
	int dist = l[k][k + 1];
	double rv1 = -1.;
	double rv2 = -1.;
	if (k == p)
		return 0.;
	if (dist <= eLeft) {
		double deltaT = ((double)dist) / ((double)currS);
		rv1 =
		    deltaT + auxSmall(t, b, xdrs, l, k + 1, p, eLeft - dist,
				      currS);
	}
	if (dist <= b[k]) {
		eLeft = b[k];
		double deltaT = ((double)dist) / ((double)xdrs[k]);
		eLeft -= dist;
		rv2 =
		    deltaT + auxSmall(t, b, xdrs, l, k + 1, p, eLeft, xdrs[k]);
	}
	if ((rv1 > 0.) && (rv2 > 0.))
		return rv1 < rv2 ? rv1 : rv2;
	else
		return rv1 < 0. ? rv2 : rv1;
}

void clearTestCase(int caseIdx, int t, int inputFileName, int *b, int *xdrs,
		   int **l, int *k, int *p)
{
	int first_iteration;
	printf("Case #%d:", caseIdx);
	for (int tc = 0; tc < inputFileName; ++tc) {
		double answer = auxSmall(t, b, xdrs, l, k[tc], p[tc], 0, 0);
		printf(" %f", answer);
	}
	printf("\n");
}

int Main(void)
{
	int first_iteration;
	int nTestCase;
	scanf("%d", &nTestCase);
	for (int tc = 0; tc < nTestCase; ++tc) {
		int t;
		int inputFileName;
		int b[100];
		int xdrs[100];
		int *l[100];
		int k[100];
		int p[100];
		scanf("%d%d", &t, &inputFileName);
		for (int tc = 0; tc < t; ++tc)
			scanf("%d%d", &b[tc], &xdrs[tc]);
		for (int tc = 0; tc < t; ++tc) {
			l[tc] = new_calloc(100, sizeof(int));
			for (int rpi = 0; rpi < t; ++rpi)
				scanf("%d", &l[tc][rpi]);
		}
		for (int tc = 0; tc < inputFileName; ++tc) {
			scanf("%d%d", &k[tc], &p[tc]);
			k[tc]--;
			p[tc]--;
		}
		clearTestCase(tc + 1, t, inputFileName, b, xdrs, l, k, p);
	}
	return 0;
}

void *new_calloc(int num, int size)
{
	return calloc(num, size);
}
