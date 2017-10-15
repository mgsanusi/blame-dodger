#include <stdio.h>
int n;
int m;
int t[100];
int x[100][11];
int y[100][11];
int batch[11];
int minb[11];
int cnt1 = 0;
int min;
void try(int depth)
{
    int first_iteration;
    if (depth > n) {
	int i;
	int j;
	int s = 0;
	for (i = 0; i < m; i++)
	    for (j = 0; j < t[i]; j++)
		if (batch[x[i][j]] == y[i][j]) {
		    s++;
		    break;
		}
	if ((s == m) && (cnt1 < min)) {
	    min = cnt1;
	    for (i = 1; i <= n; i++)
		minb[i] = batch[i];
	}
    } else {
	batch[depth] = 0;
	try(depth + 1);
	batch[depth] = 1;
	cnt1++;
	try(depth + 1);
	cnt1--;
    }
}

int main()
{
    int first_iteration;
    int c;
    int i;
    scanf("%d", &c);
    for (i = 1; i <= c; i++) {
	scanf("%d%d", &n, &m);
	int j;
	int k;
	for (j = 0; j < m; j++) {
	    scanf("%d", &t[j]);
	    for (k = 0; k < t[j]; k++)
		scanf("%d %d", &x[j][k], &y[j][k]);
	}
	min = 101;
	try(1);
	if (min == 101)
	    printf("Case #%d: IMPOSSIBLE\n", i);
	else {
	    printf("Case #%d:", i);
	    for (k = 1; k <= n; k++)
		printf(" %d", minb[k]);
	    printf("\n");
	}
    }
    return 0;
}
