#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 1010
int num[N][2], vist[N];
void new_qsort(void *base, size_t num, size_t size,
	       int (*compar) (const void *, const void *));
int dfs(int n)
{
    if (vist[n])
	return 0;
    vist[n] = 1;
    if (num[n][1] == n)
	return 0;
    return dfs(num[n][1]) + 1;
}

int cmp(const void *a, const void *b)
{
    return ((int *) a)[0] - ((int *) b)[0];
}

int main()
{
    int cas, i, j, n, ans;
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
    return qsort(base, num, size, compar);
}
