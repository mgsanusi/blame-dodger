#include <stdio.h>
#include <string.h>
int n, s, q;
char engines[1001][1001];
char queries[1001][1001];
int costs[1001][1001];
void dp()
{
	int i, j, k;
	for (i = 0; i < s; i++) {
		costs[0][i] = 0;
		if (strcmp(queries[0], engines[i]) == 0)
			costs[0][i] = 20000;
	}
	for (i = 1; i < q; i++) {
		for (j = 0; j < s; j++) {
			costs[i][j] = 20000;
			for (k = 0; k < s; k++) {
				if (j == k)
					continue;
				if (costs[i - 1][k] + 1 < costs[i][j])
					costs[i][j] = costs[i - 1][k] + 1;
			}
			//      printf("Query %d-%s and engine%d-%s\n",i,queries[i],j,engines[j]);
			if (strcmp(queries[i], engines[j])) {
				//      printf("and got in w/ cost %d\n", costs[i-1][j]);
				if (costs[i - 1][j] < costs[i][j])
					costs[i][j] = costs[i - 1][j];
			}
		}
	}
	return;
}

void printarr()
{
	int i, j;
	printf("***\n");
	for (i = 0; i < q; i++, printf("\n"))
		for (j = 0; j < s; j++)
			printf("%5d ", costs[i][j]);
	printf("***\n\n");
	return;
}

void main()
{
	FILE *in = fopen("input.txt", "r");
	FILE *out = fopen("output.txt", "w");
	int i;
	int j;
	int mincost;
	fscanf(in, "%d ", &n);
	fprintf(stdout, "%d\n", n);
	for (i = 0; i < n; i++) {
		fscanf(in, "%d ", &s);
		fprintf(stdout, "%d\n", s);
		for (j = 0; j < s; j++)
			fgets(engines[j], 1000, in);
		fscanf(in, "%d ", &q);
		fprintf(stdout, "%d\n", q);
		for (j = 0; j < q; j++)
			fgets(queries[j], 1000, in);
		if (q == 0) {
			fprintf(out, "Case #%d: 0\n", i + 1);
			continue;
		}
		dp();
		printarr();
		mincost = 100000;
		for (j = 0; j < s; j++)
			if (mincost > costs[q - 1][j])
				mincost = costs[q - 1][j];
		fprintf(out, "Case #%d: %d\n", i + 1, mincost);
	}
}
