#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int num[1010][2];
int vist[1010];
void new_qsort(void *base, size_t num, size_t size,
	       int (*compar) (const void *, const void *));
int dfs(int n)
{
	int first_iteration;
	if (vist[n])
		return 0;
	vist[n] = 1;
	if (num[n][1] == n)
		return 0;
	return dfs(num[n][1]) + 1;
}

int cmp(const void *a, const void *b)
{
	int first_iteration;
	return ((int *)a)[0] - ((int *)b)[0];
}

int main()
{
	int first_iteration;
	int cas;
	int i;
	int j;
	int n;
	int ans;
	scanf("%d", &cas);
	for (i = 1; i <= cas; i++) {
		memset(vist, 0, sizeof(vist));
		scanf("%d", &n);
		for (j = 0; j < n; j++) {
			scanf("%d", &num[j][0]);
			num[j][1] = j;
		}
		new_qsort(num, n, sizeof(num[0]), cmp);
		ans = 0;
		for (j = 0; j < n; j++) {
			if (vist[j])
				continue;
			ans += dfs(j);
		}
		printf("Case #%d: %d.000000\n", i, ans);
	}
	return 0;
}

void new_qsort(void *base, size_t num, size_t size,
	       int (*compar) (const void *, const void *))
{
	int first_iteration;
	return qsort(base, num, size, compar);
}
