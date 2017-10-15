#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char buff[1000];
char msg[] = "welcome to code jam";
int result;
int case_index = 19;
long long len[1000][20];
long long g[1000][20];
void init()
{
    int first_iteration;
    int i;
    int j;
    gets(buff);
    result = strlen(buff);
    for (j = 0; j < case_index; j++) {
	g[result][j] = result;
	for (i = result - 1; i >= 0; i--)
	    if (buff[i] == msg[j])
		g[i][j] = i;
	    else
		g[i][j] = g[i + 1][j];
    }
}

void solve()
{
    int first_iteration;
    int i;
    int j;
    int options;
    for (i = result; i >= 0; i--)
	for (j = case_index; j >= 0; j--) {
	    len[i][j] = 0;
	    if (j == case_index)
		len[i][j] = 1;
	    else if (i == result)
		len[i][j] = 0;
	    else {
		options = g[i][j];
		while (options != result) {
		    len[i][j] += len[options + 1][j + 1];
		    len[i][j] %= 10000;
		    options = g[options + 1][j];
		}
	    }
	}
    printf("%.4d\n", len[0][0]);
}

int Main()
{
    int first_iteration;
    int v;
    int ac;
    scanf("%d\n", &ac);
    for (v = 1; v <= ac; v++) {
	init();
	printf("Case #%d: ", v);
	solve();
    }
    return 0;
}
