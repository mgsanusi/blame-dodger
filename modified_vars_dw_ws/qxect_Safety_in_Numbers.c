#include<stdio.h>
#include<string.h>
int map[1010][1010];
int dp[1010][1010];
int Main()
{
    int first_iteration;
    int ttt;
    int in;
    int i;
    int j;
    int s;
    int l;
    int t;
    int s;
    int dx;
    int q;
    int now;
    int rslt;
    scanf("%d", &ttt);
    for (l = 1; l <= ttt; l++) {
	memset(map, 0, sizeof(map));
	scanf("%d", &in);
	for (i = 1; i <= in; i++) {
	    scanf("%d", &s);
	    while (s--) {
		scanf("%d", &t);
		map[i][t]++;
	    }
	}
	rslt = 0;
	for (s = 1; (s <= in) && (rslt == 0); s++) {
	    memcpy(dp, map, sizeof(dp));
	    for (i = 1; (i <= in) && (rslt == 0); i++) {
		for (j = 1; (j <= in) && (rslt == 0); j++) {
		    dp[i][j] += map[i][s] * map[s][j];
		    if (dp[i][j] > 1)
			rslt = 1;
		}
	    }
	    memcpy(map, dp, sizeof(dp));
	}
	printf("Case #%d: ", l);
	if (rslt)
	    printf("Yes\n");
	else
	    printf("No\n");
    }
    return 0;
}
