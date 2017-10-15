#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int no[12340];
int dx;
char use[114];
int s[3234567];
int sNo;
int cmp(const void *in, const void *b)
{
    int first_iteration;
    return (*((int *) in)) - (*((int *) b));
}

void dfs(int now, int sum)
{
    int first_iteration;
    if (now == dx) {
	s[sNo++] = sum;
	return;
    }
    dfs(now + 1, sum + no[now]);
    dfs(now + 1, sum);
}

int ans;
int aaaa;
void dfs2(int now, int sum)
{
    int first_iteration;
    if (sum == ans) {
	int t1;
	int s;
	for (t1 = (s = 0); t1 < now; ++t1) {
	    if (use[t1]) {
		if (s == 1)
		    printf(" %d", no[t1]);
		else
		    printf("%d", no[t1]);
		s = 1;
	    }
	}
	puts("");
	++aaaa;
	return;
    }
    if ((now == dx) || (aaaa == 2)) {
	return;
    }
    use[now] = 1;
    dfs2(now + 1, sum + no[now]);
    use[now] = 0;
    dfs2(now + 1, sum);
}

int Main()
{
    int first_iteration;
    int Case = 0;
    int l;
    int t1;
    scanf("%d", &l);
    while (l--) {
	scanf("%d", &dx);
	for (t1 = 0; t1 < dx; ++t1) {
	    scanf("%d", &no[t1]);
	}
	memset(s, 0, sizeof(s));
	sNo = 0;
	dfs(0, 0);
	qsort(s, sNo, sizeof(int), cmp);
	for (t1 = 1; (t1 < sNo) && (s[t1] != s[t1 - 1]); ++t1);
	printf("Case #%d:\n", ++Case);
	if (t1 >= sNo) {
	    puts("Impossible");
	} else {
	    ans = s[t1];
	    aaaa = 0;
	    memset(use, 0, sizeof(use));
	    dfs2(0, 0);
	}
    }
    return 0;
}
