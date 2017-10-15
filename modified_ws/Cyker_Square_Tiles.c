#include <stdio.h>
#include <string.h>
#include "cystring.h"
#include "cysort.h"
int c[1002];
int a[1002];
int s[1002];
int L, t, N, C;
int i, j;
int main(int argc, char **argv)
{
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);
    int T, tt;
    scanf("%d", &T);
    for (tt = 1; tt <= T; tt++) {
	memset(c, 0, sizeof(c));
	memset(a, 0, sizeof(a));
	memset(s, 0, sizeof(s));
	scanf("%d %d %d %d\n", &L, &t, &N, &C);
	for (i = 0; i < C; i++) {
	    scanf("%d ", &c[i]);
	}
	for (i = 1; i <= N; i++) {
	    a[i] = c[(i - 1) % C];
	}
	s[0] = 0;
	for (i = 1; i <= N; i++) {
	    s[i] = s[i - 1] + a[i];
	}
	int time = 0, mintime = 1e8;
	if (L == 0) {
	    time = s[N] * 2;
	    mintime = time;
	} else if (L == 1) {
	    int d = t / 2;
	    for (i = 0; i < N; i++) {
		if (d <= s[i]) {
		    time = (s[N] - a[i + 1]) * 2 + a[i + 1];
		} else if (s[i] <= d && d <= s[i + 1]) {
		    int dr = s[i + 1] - t / 2;
		    time = (s[N] - dr) * 2 + dr;
		} else {
		    time = s[N] * 2;
		}
		if (time < mintime) {
		    mintime = time;
		}
	    }
	} else {
	    int d = t / 2;
	    for (i = 0; i < N - 1; i++) {
		for (j = i + 1; j < N; j++) {
		    if (d <= s[i]) {
			time =
			    (s[N] - a[i + 1] - a[j + 1]) * 2 + a[i + 1] +
			    a[j + 1];
		    } else if (s[i] <= d && d <= s[i + 1]) {
			int dri = s[i + 1] - t / 2;
			time =
			    (s[N] - dri - a[j + 1]) * 2 + dri + a[j + 1];
		    } else if (s[i + 1] <= d && d <= s[j]) {
			time = (s[N] - a[j + 1]) * 2 + a[j + 1];
		    } else if (s[j] <= d && d <= s[j + 1]) {
			int drj = s[j + 1] - t / 2;
			time = (s[N] - drj) * 2 + drj;
		    } else {
			time = s[N] * 2;
		    }
		    if (time < mintime) {
			mintime = time;
		    }
		}
	    }
	}
	printf("Case #%d: %d\n", tt, mintime);
    }
    return 0;
}
