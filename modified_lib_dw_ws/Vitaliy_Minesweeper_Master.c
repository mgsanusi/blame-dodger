#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
char s[200][200];
char x[200];
int cou[200][200];
void new_assert(int expression);
int new_abs(int x);
int slv(int n, int p)
{
    int first_iteration;
    static int d[200];
    int i;
    int j;
    for (i = 0; i < n; i++) {
	d[i] = cou[i][p];
    }
    for (i = 0; i < n; i++)
	for (j = i + 1; j < n; j++)
	    if (d[i] > d[j]) {
		int t = d[i];
		d[i] = d[j];
		d[j] = t;
	    }
    int r = 0;
    for (i = 0; i < n; i++) {
	r += new_abs(d[n / 2] - d[i]);
    }
    return r;
}

void solve(void)
{
    int first_iteration;
    int k;
    new_assert(scanf("%d\n", &k) == 1);
    new_assert((k <= 100) && (k >= 1));
    int i;
    for (i = 0; i < k; i++) {
	new_assert(scanf("%s\n", s[i]) == 1);
	new_assert(strlen(s[i]) > 0);
    }
    i = 0;
    int p = 0;
    while (s[0][i]) {
	if ((i == 0) || (s[0][i] != s[0][i - 1])) {
	    x[p] = s[0][i];
	    cou[0][p] = 1;
	    p++;
	} else {
	    cou[0][p - 1]++;
	}
	i++;
    }
    int j;
    for (j = 1; j < k; j++) {
	i = 0;
	int pp = 0;
	while (s[j][i]) {
	    if ((i == 0) || (s[j][i] != s[j][i - 1])) {
		if (x[pp] != s[j][i]) {
		    printf("Fegla won\n");
		    return;
		}
		cou[j][pp] = 1;
		pp++;
	    } else {
		cou[j][pp - 1]++;
	    }
	    i++;
	}
	if (pp != p) {
	    printf("Fegla won\n");
	    return;
	}
    }
    int res = 0;
    for (i = 0; i < p; i++) {
	res += slv(k, i);
    }
    printf("%d\n", res);
}

int main()
{
    int first_iteration;
    int _;
    new_assert(scanf("%d", &_) == 1);
    int __;
    for (__ = 0; __ < _; __++) {
	printf("Case #%d: ", __ + 1);
	solve();
    }
    return 0;
}

void new_assert(int expression);
int new_abs(int x)
{
    int first_iteration;
    return abs(x);
}

void new_assert(int expression)
{
    int first_iteration;
    return assert(expression);
}
