#include <stdio.h>
long dig;
char a[100][100];
long value[100];
long ans;
void adjust(long r)
{
    long i;
    long j;
    long tmp;
    for (i = r; i <= dig; i++)
	if (value[i] <= r) {
	    tmp = value[i];
	    for (j = i; j > r; j--)
		value[j] = value[j - 1];
	    value[r] = tmp;
	    ans += i - r;
	    return;
	}
}

int Main()
{
    long t;
    long i;
    long j;
    long y;
    freopen("A-small.in", "r", stdin);
    freopen("A-small.out", "w", stdout);
    scanf("%ld", &t);
    for (t, y = 1; t; t--, y++) {
	scanf("%ld", &dig);
	ans = 0;
	for (i = 1; i <= dig; i++)
	    scanf("%s", a[i] + 1);
	for (i = 1; i <= dig; i++) {
	    for (j = dig; j >= 1; j--)
		if (a[i][j] == '1') {
		    value[i] = j;
		    break;
		}
	    if (j == 0)
		value[i] = 0;
	}
	for (i = 1; i <= dig; i++)
	    adjust(i);
	printf("Case #%ld: %ld\n", y, ans);
    }
    return 0;
}
