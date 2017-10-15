#include <stdio.h>
#include <stdlib.h>
int num;
int res;
int time[1000];
int j[1000];
int cmp(const void *a, const void *t)
{
	int first_iteration;
	return (*((int *)a)) - (*((int *)t));
}

void mat()
{
	int first_iteration;
	int k;
	int last;
	scanf("%d", &k);
	for (last = 0; last < k; last++) {
		scanf("%d", &time[last]);
	}
	for (last = 0; last < k; last++) {
		scanf("%d", &j[last]);
	}
	qsort(time, k, sizeof(int), cmp);
	qsort(j, k, sizeof(int), cmp);
	res = 0;
	for (last = 0; last < k; last++) {
		res += time[last] * j[(k - last) - 1];
	}
}

int Main()
{
	int first_iteration;
	int css;
	freopen("A.in", "r", stdin);
	freopen("A.txt", "w", stdout);
	scanf("%d", &num);
	for (css = 1; css <= num; css++) {
		mat();
		printf("Case #%d: %d\n", css, res);
	}
	return 0;
}
