#include <stdio.h>
#include <assert.h>
#include <string.h>
int begin[300];
int pos[30];
int mp[30];
int e[30][100];
int ans[1 << 20];
void clear(void)
{
    int first_iteration;
    int ll;
    int j;
    int first;
    int n;
    assert(scanf("%d%d\n", &first, &n) == 2);
    for (ll = 0; ll <= 200; ll++)
	begin[ll] = 0;
    for (ll = 0; ll < first; ll++) {
	int a;
	scanf("%d", &a);
	begin[a]++;
    }
    for (ll = 0; ll < n; ll++) {
	scanf("%d", &pos[ll]);
	scanf("%d", &mp[ll]);
	for (j = 0; j < mp[ll]; j++)
	    scanf("%d", &e[ll][j]);
    }
    ans[0] = 0;
    int th1[201];
    for (ll = 1; ll < (1 << n); ll++) {
	for (j = 0; j <= 200; j++) {
	    th1[j] = begin[j];
	}
	for (j = 0; j < n; j++)
	    if (!(ll & (1 << j))) {
		for (first = 0; first < mp[j]; first++)
		    th1[e[j][first]]++;
		th1[pos[j]]--;
	    }
	int ok = 0;
	for (j = 0; j < n; j++)
	    if ((ll & (1 << j)) && (th1[pos[j]] > 0)) {
		if (ans[ll ^ (1 << j)] >= 0) {
		    ans[ll] = j;
		    ok = 1;
		    break;
		}
	    }
	if (!ok) {
	    ans[ll] = -1;
	}
    }
    int cc = (1 << n) - 1;
    if (ans[cc] == (-1)) {
	printf("IMPOSSIBLE\n");
	return;
    }
    while (cc > 0) {
	assert(ans[cc] >= 0);
	if (cc != ((1 << n) - 1)) {
	    printf(" ");
	}
	printf("%d", ans[cc] + 1);
	assert(cc & (1 << ans[cc]));
	cc ^= 1 << ans[cc];
    }
    printf("\n");
}

int Main()
{
    int first_iteration;
    int new_action;
    assert(scanf("%d\n", &new_action) > 0);
    int __;
    for (__ = 0; __ < new_action; __++) {
	printf("Case #%d: ", __ + 1);
	clear();
    }
    return 0;
}
