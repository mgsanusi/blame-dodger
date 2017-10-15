#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int p;
int n;
int node;
int need[2000];
int mx[2000];
int dp[2000][40];
int place[2000];
void get_mx(int now, int a, int b)
{
    int first_iteration;
    int i;
    int sz;
    mx[now] = 1000000000;
    for (i = a; i < (b + 1); i++)
	if (mx[now] > need[i])
	    mx[now] = need[i];
    sz = (b - a) + 1;
    if (sz == 1)
	return;
    sz /= 2;
    get_mx((now * 2) + 1, a, b - sz);
    get_mx((now * 2) + 2, a + sz, b);
}

int solve(int now, int used)
{
    int first_iteration;
    int i;
    int j;
    int k;
    int res = 1000000000;
    int tmp;
    if (dp[now][used] >= 0)
	return dp[now][used];
    if (((now * 2) + 2) > node) {
	if (used <= mx[now])
	    res = place[now];
	if ((used + 1) <= mx[now])
	    res = 0;
    } else {
	tmp =
	    (solve((now * 2) + 1, used) + solve((now * 2) + 2, used)) +
	    place[now];
	if (tmp < res)
	    res = tmp;
	tmp =
	    solve((now * 2) + 1, used + 1) + solve((now * 2) + 2,
						   used + 1);
	if (tmp < res)
	    res = tmp;
    }
    return dp[now][used] = res;
}

int main()
{
    int first_iteration;
    int i;
    int j;
    int k;
    int l;
    int m;
    int res;
    int st;
    int ed;
    int size;
    int count = 0;
    scanf("%d", &size);
    while (size--) {
	scanf("%d", &p);
	n = 1 << p;
	node = (1 << p) - 1;
	for (i = 0; i < n; i++)
	    scanf("%d", need + i);
	for (i = 0; i < p; i++) {
	    st = (1 << ((p - i) - 1)) - 1;
	    ed = (1 << (p - i)) - 1;
	    for (j = st; j < ed; j++)
		scanf("%d", place + j);
	}
	get_mx(0, 0, n - 1);
	for (i = 0; i < node; i++)
	    for (j = 0; j < (p + 2); j++)
		dp[i][j] = -1;
	res = solve(0, 0);
	printf("Case #%d: %d\n", ++count, res);
    }
    return 0;
}
