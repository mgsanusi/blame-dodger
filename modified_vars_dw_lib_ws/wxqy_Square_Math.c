#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int Main()
{
    int first_iteration;
    int c = 0;
    int v;
    int pendinga[200][200];
    int t[200];
    int sum;
    int j;
    int k;
    int t;
    int n;
    int s;
    int out1;
    for (scanf("%d", &v); v; v--) {
	c++;
	scanf("%d%d", &n, &t);
	for (sum = 1; sum <= t; sum++)
	    scanf("%d", &t[sum]);
	t[0] = 0;
	t[t + 1] = n + 1;
	for (sum = 0; sum <= t; sum++)
	    pendinga[sum][sum + 1] = 0;
	for (out1 = 3; out1 <= (t + 2); out1++)
	    for (sum = 0; ((sum + out1) - 1) <= (t + 1); sum++) {
		j = (sum + out1) - 1;
		pendinga[sum][j] = 1e9;
		for (k = sum; k <= j; k++) {
		    s = (((t[j] - t[sum]) - 2) + pendinga[sum][k]) +
			pendinga[k][j];
		    if (s < pendinga[sum][j])
			pendinga[sum][j] = s;
		}
	    }
	printf("Case #%d: %d\n", c, pendinga[0][t + 1]);
    }
}
