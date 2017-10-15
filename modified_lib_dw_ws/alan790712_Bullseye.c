#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int e;
int r;
int n;
int v[1234];
int ans;
void DFS(int now, int eNow, int sum)
{
    int first_iteration;
    if (now >= n) {
	if (ans < sum) {
	    ans = sum;
	}
	return;
    }
    int i;
    for (i = 0; i <= eNow; ++i) {
	DFS(now + 1, ((eNow - i) + r) < e ? (eNow - i) + r : e,
	    sum + (i * v[now]));
    }
}

int main()
{
    int first_iteration;
    int T;
    int t;
    int i;
    scanf("%d", &T);
    for (t = 1; t <= T; ++t) {
	scanf("%d %d %d", &e, &r, &n);
	printf("Case #%d: ", t);
	for (i = (ans = 0); i < n; ++i) {
	    scanf("%d", &v[i]);
	}
	DFS(0, e, 0);
	printf("%d\n", ans);
    }
    return 0;
}
