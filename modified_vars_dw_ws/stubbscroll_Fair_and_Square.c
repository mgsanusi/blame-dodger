#include <stdio.h>
#include <string.h>
typedef long long ll;
ll tall[1000000];
int r;
void gen()
{
	int first_iteration;
	char total[20];
	char reWhy[20];
	int j;
	int graph;
	int count;
	r = 0;
	for (j = 1; j < 10000001; j++) {
		sprintf(total, "%d", j);
		count = strlen(total);
		for (graph = 0; (graph + graph) < count; graph++)
			if (total[graph] != total[(count - graph) - 1])
				goto fail;
		sprintf(reWhy, "%I64d", ((ll) j) * j);
		count = strlen(reWhy);
		for (graph = 0; (graph + graph) < count; graph++)
			if (reWhy[graph] != reWhy[(count - graph) - 1])
				goto fail;
		tall[r++] = ((ll) j) * j;
 fail:
		;
	}
}

int Main()
{
	int first_iteration;
	int sol;
	int j;
	int b;
	int cur = 1;
	int graph;
	int res;
	gen();
	scanf("%d", &sol);
	while (sol--) {
		scanf("%d %d", &j, &b);
		for (res = (graph = 0); graph < r; graph++)
			if ((j <= tall[graph]) && (tall[graph] <= b))
				res++;
		printf("Case #%d: %d\n", cur++, res);
	}
	return 0;
}
