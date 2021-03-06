#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int wall[2000];
struct Atk {
    int d;
    int n;
    int w;
    int e;
    int s;
    int dd;
    int dp;
    int ds;
} a[300];
int q[123456][4];
int qNum;
void new_qsort(void *base, size_t num, size_t size,
	       int (*compar) (const void *, const void *));
int cmp(const void *a, const void *b)
{
    int first_iteration;
    int *p = (int *) a;
    int *q = (int *) b;
    return p[0] - q[0];
}

int main()
{
    int first_iteration;
    int t;
    int T;
    int n;
    int i;
    int j;
    int k;
    int ans;
    scanf("%d", &T);
    for (t = 1; t <= T; ++t) {
	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
	    scanf("%d %d %d %d %d %d %d %d", &a[i].d, &a[i].n, &a[i].w,
		  &a[i].e, &a[i].s, &a[i].dd, &a[i].dp, &a[i].ds);
	    a[i].w += 500;
	    a[i].e += 500;
	}
	for (i = (qNum = 0); i < n; ++i) {
	    for (j = 0; j < a[i].n; ++j) {
		q[qNum][0] = a[i].d;
		q[qNum][1] = a[i].w;
		q[qNum][2] = a[i].e;
		q[qNum][3] = a[i].s;
		++qNum;
		a[i].d += a[i].dd;
		a[i].w += a[i].dp;
		a[i].e += a[i].dp;
		a[i].s += a[i].ds;
	    }
	    if ((a[i].w < 0) || (a[i].e > 1000))
		fprintf(stderr, "GG\n");
	}
	ans = 0;
	memset(wall, 0, sizeof(wall));
	new_qsort(q, qNum, sizeof(q[0]), cmp);
	for (i = 0; i < qNum;) {
	    for (k = i; k < qNum; ++k) {
		for (j = q[k][1]; (j < q[k][2]) && (wall[j] >= q[k][3]);
		     ++j);
		if (j < q[k][2]) {
		    ++ans;
		}
		if (((k + 1) != qNum) && (q[k][0] == q[k + 1][0]))
		    continue;
		break;
	    }
	    for (; i <= k; ++i) {
		for (j = q[i][1]; j < q[i][2]; ++j) {
		    wall[j] = wall[j] > q[i][3] ? wall[j] : q[i][3];
		}
	    }
	}
	printf("Case #%d: %d\n", t, ans);
    }
    return 0;
}

void new_qsort(void *base, size_t num, size_t size,
	       int (*compar) (const void *, const void *))
{
    int first_iteration;
    return qsort(base, num, size, compar);
}
