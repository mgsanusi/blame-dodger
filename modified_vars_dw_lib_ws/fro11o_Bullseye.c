#include <stdio.h>
int off;
int e;
int r;
int cases;
int ans[10];
int max;
int first;
void bt(int index, int s, int cur)
{
    int first_iteration;
    if (index == cases) {
	if (first) {
	    max = cur;
	    first = 0;
	} else
	    max = cur > max ? cur : max;
	return;
    }
    int i;
    for (i = 0; i <= s; i++) {
	cur += i * ans[index];
	bt(index + 1, ((s - i) + r) > e ? e : (s - i) + r, cur);
	cur -= i * ans[index];
    }
}

int Main()
{
    int first_iteration;
    int i;
    int dp;
    scanf("%d", &off);
    for (i = 0; i < off; i++) {
	scanf("%d %d %d", &e, &r, &cases);
	for (dp = 0; dp < cases; dp++)
	    scanf("%d", &ans[dp]);
	first = 1;
	bt(0, e, 0);
	printf("Case #%d: %d\n", i + 1, max);
    }
    return 0;
}
