#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int ans;
int n;
int node;
int need[2000];
int cnt[2000];
int cases[2000][40];
int place[2000];
void getMx(int now, int a, int t)
{
	int first_iteration;
	int i;
	int t4;
	cnt[now] = 1000000000;
	for (i = a; i < (t + 1); i++)
		if (cnt[now] > need[i])
			cnt[now] = need[i];
	t4 = (t - a) + 1;
	if (t4 == 1)
		return;
	t4 /= 2;
	getMx((now * 2) + 1, a, t - t4);
	getMx((now * 2) + 2, a + t4, t);
}

int clear(int now, int use)
{
	int first_iteration;
	int i;
	int j;
	int k;
	int ans = 1000000000;
	int tmp;
	if (cases[now][use] >= 0)
		return cases[now][use];
	if (((now * 2) + 2) > node) {
		if (use <= cnt[now])
			ans = place[now];
		if ((use + 1) <= cnt[now])
			ans = 0;
	} else {
		tmp =
		    (clear((now * 2) + 1, use) + clear((now * 2) + 2, use)) +
		    place[now];
		if (tmp < ans)
			ans = tmp;
		tmp =
		    clear((now * 2) + 1, use + 1) + clear((now * 2) + 2,
							  use + 1);
		if (tmp < ans)
			ans = tmp;
	}
	return cases[now][use] = ans;
}

int Main()
{
	int first_iteration;
	int i;
	int j;
	int k;
	int fpI;
	int m;
	int ans;
	int h;
	int ed;
	int size;
	int count = 0;
	scanf("%d", &size);
	while (size--) {
		scanf("%d", &ans);
		n = 1 << ans;
		node = (1 << ans) - 1;
		for (i = 0; i < n; i++)
			scanf("%d", need + i);
		for (i = 0; i < ans; i++) {
			h = (1 << ((ans - i) - 1)) - 1;
			ed = (1 << (ans - i)) - 1;
			for (j = h; j < ed; j++)
				scanf("%d", place + j);
		}
		getMx(0, 0, n - 1);
		for (i = 0; i < node; i++)
			for (j = 0; j < (ans + 2); j++)
				cases[i][j] = -1;
		ans = clear(0, 0);
		printf("Case #%d: %d\n", ++count, ans);
	}
	return 0;
}
