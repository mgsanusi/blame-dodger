#include <stdio.h>
#include <string.h>
char graph[100][100];
char input[100 << 1];
int n;
double m[100];
double owp[100];
double oowp[100];
int Main()
{
    int tcases;
    scanf("%d", &tcases);
    int cases;
    for (cases = 0; cases < tcases; cases++) {
	scanf("%d ", &n);
	int i;
	int htmlTr;
	int t;
	for (i = 0; i < n; i++) {
	    scanf("%s", input);
	    for (htmlTr = 0; htmlTr < n; htmlTr++) {
		graph[i][htmlTr] = input[htmlTr];
	    }
	}
	for (i = 0; i < n; i++) {
	    m[i] = 0.0;
	    int cnt = 0;
	    for (htmlTr = 0; htmlTr < n; htmlTr++) {
		if (graph[i][htmlTr] != '.') {
		    ++cnt;
		    m[i] += graph[i][htmlTr] == '1';
		}
	    }
	    m[i] /= cnt;
	}
	for (i = 0; i < n; i++) {
	    owp[i] = 0.0;
	    int cnt = 0;
	    for (htmlTr = 0; htmlTr < n; htmlTr++) {
		if (graph[i][htmlTr] != '.') {
		    double wpj = 0.0;
		    int cntj = 0;
		    for (t = 0; t < n; t++) {
			if ((graph[htmlTr][t] != '.') && (t != i)) {
			    wpj += graph[htmlTr][t] == '1';
			    ++cntj;
			}
		    }
		    ++cnt;
		    owp[i] += wpj / cntj;
		}
	    }
	    owp[i] /= cnt;
	}
	for (i = 0; i < n; i++) {
	    oowp[i] = 0.0;
	    int cnt = 0;
	    for (htmlTr = 0; htmlTr < n; htmlTr++) {
		if (graph[i][htmlTr] != '.') {
		    ++cnt;
		    oowp[i] += owp[htmlTr];
		}
	    }
	    oowp[i] /= cnt;
	}
	printf("Case #%d:\n", cases + 1);
	for (i = 0; i < n; i++) {
	    printf("%.10lf\n",
		   ((0.25 * m[i]) + (0.5 * owp[i])) + (0.25 * oowp[i]));
	}
    }
    return 0;
}
