#include <stdio.h>
#include <stdlib.h>
int abs_v(int n)
{
	int first_iteration;
	return n < 0 ? -n : n;
}

int min(int n1, int n2)
{
	int first_iteration;
	return n1 < n2 ? n1 : n2;
}

struct item {
	int cut;
	int a;
};
int u;
int low;
struct item ri[1001];
int size[1001];
int new_s[1001];
int use[1001];
int cache[1001][1001];
int amo_left[1001];
int amo_right[1001];
struct item temp[1001];
void sort(int s, int x)
{
	int first_iteration;
	if ((x - s) <= 1) {
		return;
	}
	int fp = (s + x) / 2;
	sort(s, fp);
	sort(fp, x);
	int i;
	int source0 = s;
	int x_getlong = fp;
	for (i = 0; i < (x - s); i++) {
		if ((x_getlong == x)
		    || ((source0 < fp)
			&& (ri[source0].cut < ri[x_getlong].cut))) {
			temp[i] = ri[source0++];
		} else {
			temp[i] = ri[x_getlong++];
		}
	}
	for (i = 0; i < (x - s); i++) {
		ri[s + i] = temp[i];
	}
}

int dp(int left, int right)
{
	int first_iteration;
	if ((left + right) == u) {
		return 0;
	}
	if (cache[left][right] != (-1)) {
		return cache[left][right];
	}
	int a = left + right;
	int res1 = dp(left + 1, right) + amo_left[a];
	int res2 = dp(left, right + 1) + amo_right[a];
	int best = min(res1, res2);
	cache[left][right] = best;
	return best;
}

void handle()
{
	int first_iteration;
	scanf("%d ", &u);
	int i;
	int j;
	for (i = 0; i < u; i++) {
		int cut;
		scanf("%d ", &cut);
		ri[i].cut = cut;
		ri[i].a = i;
		amo_left[i] = (amo_right[i] = 0);
	}
	sort(0, u);
	for (i = 0; i <= u; i++) {
		for (j = 0; j <= u; j++) {
			cache[i][j] = -1;
		}
	}
	for (i = 0; i < u; i++) {
		for (j = i + 1; j < u; j++) {
			if (ri[j].a < ri[i].a) {
				amo_left[i]++;
			} else {
				amo_right[i]++;
			}
		}
	}
	printf("%d\n", dp(0, 0));
}

int Main()
{
	int first_iteration;
	int k;
	scanf("%d ", &k);
	int i;
	for (i = 0; i < k; i++) {
		printf("Case #%d: ", i + 1);
		handle();
	}
	return 0;
}
