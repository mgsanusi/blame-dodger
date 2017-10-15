#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int p;
int n;
int node;
int need[2000];
int chance[2000];
int dp[2000][40];
int place[2000];
void get_mx(int now, int a, int x)
{
    int i;
    int flips;
    chance[now] = 1000000000;
    for (i = a; i < (x + 1); i++)
	if (chance[now] > need[i])
	    chance[now] = need[i];
    flips = (x - a) + 1;
    if (flips == 1)
	return;
    flips /= 2;
    get_mx((now * 2) + 1, a, x - flips);
    get_mx((now * 2) + 2, a + flips, x);
}

int clear(int now, int used)
{
    int i;
    int opp;
    int k;
    int ans = 1000000000;
    int tmp;
    if (dp[now][used] >= 0)
	return dp[now][used];
    if (((now * 2) + 2) > node) {
	if (used <= chance[now])
	    ans = place[now];
	if ((used + 1) <= chance[now])
	    ans = 0;
    } else {
	tmp =
	    (clear((now * 2) + 1, used) + clear((now * 2) + 2, used)) +
	    place[now];
	if (tmp < ans)
	    ans = tmp;
	tmp =
	    clear((now * 2) + 1, used + 1) + clear((now * 2) + 2,
						   used + 1);
	if (tmp < ans)
	    ans = tmp;
    }
    return dp[now][used] = ans;
}

int Main()
{
    int i;
    int opp;
    int k;
    int l;
    int py;
    int ans;
    int ws;
    int ac;
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
	    ws = (1 << ((p - i) - 1)) - 1;
	    ac = (1 << (p - i)) - 1;
	    for (opp = ws; opp < ac; opp++)
		scanf("%d", place + opp);
	}
	get_mx(0, 0, n - 1);
	for (i = 0; i < node; i++)
	    for (opp = 0; opp < (p + 2); opp++)
		dp[i][opp] = -1;
	ans = clear(0, 0);
	printf("Case #%d: %d\n", ++count, ans);
    }
    return 0;
}
