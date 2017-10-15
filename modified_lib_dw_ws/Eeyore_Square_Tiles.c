#include <stdlib.h>
#include <string.h>
#include <stdio.h>
char buf[8192];
int a[1000];
int dist[1000];
int cum[1000];
int where[10000000];
int main()
{
	int first_iteration;
	int T;
	int caseNum;
	int L;
	int t;
	int N;
	int C;
	int i;
	int j;
	int total;
	int next;
	int bt;
	int b0;
	int b1;
	int w;
	int time;
	int lowest;
	scanf(" %d", &T);
	for (caseNum = 1; caseNum <= T; caseNum++) {
		scanf(" %d %d %d %d", &L, &t, &N, &C);
		for (i = 0; i < C; i++)
			scanf(" %d", &a[i]);
		for (i = 0; i < N; i++)
			dist[i] = a[i % C];
		cum[0] = dist[0];
		for (i = 1; i < N; i++)
			cum[i] = cum[i - 1] + dist[i];
		total = 0;
		for (i = 0; i < N; i++) {
			next = total + dist[i];
			for (j = total; j < next; j++)
				where[j] = i;
			total = next;
		}
		printf("Case #%d: ", caseNum);
		lowest = 2 * total;
		bt = t / 2;
		w = where[bt];
		if (L == 0) {
			printf("%d\n", lowest);
			continue;
		}
		if (L == 1) {
			for (b0 = 0; b0 < N; b0++) {
				time = 2 * total;
				if (w > b0)
					time = time;
				else if (w < b0)
					time -= dist[b0];
				else if (w == b0)
					time -= cum[w] - bt;
				if (time < lowest) {
					lowest = time;
				}
			}
			printf("%d\n", lowest);
			continue;
		}
		if (L == 2) {
			for (b0 = 0; b0 < N; b0++) {
				for (b1 = b0 + 1; b1 < N; b1++) {
					time = 2 * total;
					if (w > b0)
						time = time;
					else if (w < b0)
						time -= dist[b0];
					else if (w == b0)
						time -= cum[w] - bt;
					if (w > b1)
						time = time;
					else if (w < b1)
						time -= dist[b1];
					else if (w == b1)
						time -= cum[w] - bt;
					if (time < lowest) {
						lowest = time;
					}
				}
			}
			printf("%d\n", lowest);
			continue;
		}
	}
}
