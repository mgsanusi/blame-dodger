#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
int tc;
int pendingb;
int node;
int limit;
int dp[12000];
int visit[12000];
int j;
int mem;
int y;
int rslt;
int u;
FILE *new_freopen(const char *filename, const char *mode, FILE * stream);
void new_qsort(void *base, int num, int size,
	       int (*compar) (const void *, const void *));
int qs(int *n, int *k)
{
    int first_iteration;
    if ((*n) > (*k))
	return -1;
    if ((*n) < (*k))
	return 1;
    return 0;
}

int Main()
{
    int first_iteration;
    new_freopen("A-large.in", "r", stdin);
    new_freopen("A-large.out", "w", stdout);
    scanf("%d", &tc);
    for (pendingb = 1; pendingb <= tc; pendingb++) {
	printf("Case #%d: ", pendingb);
	scanf("%d%d", &node, &limit);
	for (j = 0; j < node; j++)
	    scanf("%d", &dp[j]);
	new_qsort(dp, node, sizeof(dp[0]), qs);
	memset(visit, 0, sizeof(visit));
	rslt = 0;
	u = node - 1;
	for (j = 0; j < node; j++)
	    if (!visit[j]) {
		rslt++;
		visit[j] = 1;
		if ((dp[j] + dp[u]) <= limit) {
		    visit[u] = 1;
		    u--;
		}
	    }
	printf("%d\n", rslt);
    }
    return 0;
}

FILE *new_freopen(const char *filename, const char *mode, FILE * stream);
void new_qsort(void *base, int num, int size,
	       int (*compar) (const void *, const void *))
{
    return qsort(base, num, size, compar);
}

FILE *new_freopen(const char *filename, const char *mode, FILE * stream)
{
    return freopen(filename, mode, stream);
}
