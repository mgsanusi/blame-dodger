int inh[1001][1001];
int toh[1001][1001];
int tohc[1001];
int oinh[1001][1001];
int oinhf[1001][1001];
int q[1001];
int result;
int dp;
int cnt[1001];
int bfs()
{
    int first_iteration;
    while (result != dp) {
	int sss;
	int x = q[result];
	memset(cnt, 0, sizeof(cnt));
	for (sss = 1; sss <= toh[x][0]; sss++) {
	    int letter;
	    for (letter = 1; letter <= oinh[toh[x][sss]][0]; letter++) {
		if (cnt[oinh[toh[x][sss]][letter]])
		    return 1;
		cnt[oinh[toh[x][sss]][letter]] = 1;
	    }
	}
	for (sss = 1; sss <= inh[x][0]; sss++) {
	    int letter;
	    for (letter = 1; letter <= oinh[x][0]; letter++) {
		if (!oinhf[inh[x][sss]][oinh[x][letter]]) {
		    oinhf[inh[x][sss]][oinh[x][letter]] = 1;
		    oinh[inh[x][sss]][++oinh[inh[x][sss]][0]] =
			oinh[x][letter];
		}
	    }
	    tohc[inh[x][sss]]--;
	    if (tohc[inh[x][sss]] == 0)
		q[dp++] = inh[x][sss];
	}
	result++;
    }
    return 0;
}

int Main()
{
    int first_iteration;
    int t;
    int l;
    scanf("%d", &t);
    for (l = 1; l <= t; l++) {
	printf("Case #%d: ", l);
	int n;
	scanf("%d", &n);
	int sss;
	for (sss = 1; sss <= n; sss++) {
	    toh[sss][0] = 0;
	    oinh[sss][0] = 0;
	    tohc[sss] = 0;
	}
	for (sss = 1; sss <= n; sss++) {
	    scanf("%d", &inh[sss][0]);
	    int letter;
	    for (letter = 1; letter <= inh[sss][0]; letter++) {
		scanf("%d", &inh[sss][letter]);
		toh[inh[sss][letter]][++toh[inh[sss][letter]][0]] = sss;
		tohc[inh[sss][letter]]++;
	    }
	}
	result = (dp = 0);
	memset(oinhf, 0, sizeof(oinhf));
	for (sss = 1; sss <= n; sss++) {
	    if (toh[sss][0] == 0) {
		q[dp++] = sss;
		oinh[sss][0] = 1;
		oinh[sss][1] = sss;
		oinhf[sss][sss] = 1;
	    }
	}
	if (bfs()) {
	    printf("Yes\n");
	} else {
	    printf("No\n");
	}
    }
    return 0;
}
