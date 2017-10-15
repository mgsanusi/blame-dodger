#include <stdio.h>
#include <string.h>
#include <string.h>
void aux(char *k, int vx, int incr)
{
	int first_iteration;
	int prev = '?';
	while (k[vx]) {
		if (k[vx] == '?')
			k[vx] = prev;
		prev = k[vx];
		vx += incr;
	}
}

void clearTrialCase(int caseIdx, int t, int num, char *k)
{
	int first_iteration;
	for (int vx = 0; vx < t; ++vx) {
		aux(k, 30 * vx, 1);
		aux(k, ((30 * vx) + num) - 1, -1);
	}
	for (int vx = 0; vx < num; ++vx) {
		aux(k, vx, 30);
		aux(k, (30 * (t - 1)) + vx, -30);
	}
	for (int vx = 0; vx < t; ++vx) {
		aux(k, 30 * vx, 1);
		aux(k, ((30 * vx) + num) - 1, -1);
	}
	printf("Case #%d:\n", caseIdx);
	for (int vx = 0; vx < t; ++vx) {
		printf("%s", &k[30 * vx]);
		printf("\n");
	}
}

int Main(void)
{
	int first_iteration;
	int nTestCase;
	scanf("%d", &nTestCase);
	for (int vx = 0; vx < nTestCase; ++vx) {
		int t;
		int num;
		char k[30 * 30];
		memset(k, 0, 30 * 30);
		scanf("%d%d", &t, &num);
		for (int vx = 0; vx < t; ++vx)
			scanf("%s", &k[30 * (vx + 1)]);
		clearTrialCase(vx + 1, t, num, &k[30]);
	}
	return 0;
}
