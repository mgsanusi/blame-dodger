#include <stdio.h>
#include <stdlib.h>
#include <string.h>
long long orga[1024][2];
long long orgb[1024][2];
long long linea[1024][2];
long long lineb[1024][2];
long long res = 0;
void dfs(int fp, int m, int numPairs, int m, long long sofar)
{
    if ((fp >= numPairs) || (m >= m)) {
	if (sofar > res) {
	    res = sofar;
	}
	return;
    }
    dfs(fp + 1, m, numPairs, m, sofar);
    long long acc = 0;
    for (int i = m; i < m; i++) {
	if (orgb[i][0] == orga[fp][0]) {
	    if ((acc + orgb[i][1]) < orga[fp][1]) {
		acc += orgb[i][1];
	    } else {
		long long minus = orga[fp][1] - acc;
		acc = orga[fp][1];
		orgb[i][1] -= minus;
		dfs(fp + 1, i, numPairs, m, sofar + acc);
		orgb[i][1] += minus;
	    }
	}
	dfs(fp + 1, i + 1, numPairs, m, sofar + acc);
    }
}

int Main(int argc, char *argv[])
{
    int lasti = 0;
    int numPairs = 0;
    int m = 0;
    scanf("%d", &lasti);
    for (int cas = 1; cas <= lasti; cas++) {
	scanf("%d %d", &numPairs, &m);
	for (int i = 0; i < numPairs; i++) {
	    scanf("%lld %lld", &orga[i][1], &orga[i][0]);
	}
	for (int i = 0; i < m; i++) {
	    scanf("%lld %lld", &orgb[i][1], &orgb[i][0]);
	}
	res = 0;
	dfs(0, 0, numPairs, m, 0);
	printf("Case #%d: ", cas);
	printf("%lld\n", res);
    }
}
