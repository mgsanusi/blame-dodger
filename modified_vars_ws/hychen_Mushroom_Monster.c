#include<stdio.h>
int m[10000];
int Main(int argc, char *argv[])
{
    int v;
    int left;
    int c;
    int t;
    int f;
    int mem;
    scanf("%d", &f);
    for (t = 1; t <= f; t++) {
	scanf("%d", &mem);
	for (v = 0; v < mem; v++)
	    scanf("%d", m + v);
	int ans1 = 0;
	int ans2 = 0;
	for (v = 1; v < mem; v++) {
	    if (m[v] < m[v - 1])
		ans1 += m[v - 1] - m[v];
	}
	int rate = 0;
	for (v = 1; v < mem; v++) {
	    if (m[v] < m[v - 1]) {
		if ((m[v - 1] - m[v]) > rate)
		    rate = m[v - 1] - m[v];
	    }
	}
	left = m[0];
	for (v = 1; v < mem; v++) {
	    if (left < rate) {
		ans2 += left;
		left = 0;
	    } else {
		left -= rate;
		ans2 += rate;
	    }
	    left = m[v];
	}
	printf("Case #%d: %d %d\n", t, ans1, ans2);
    }
    return 0;
}
