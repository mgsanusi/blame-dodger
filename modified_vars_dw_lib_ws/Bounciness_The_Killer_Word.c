#include <stdio.h>
#include <stdlib.h>
int table[101][101];
int game[101];
int win[101];
double avg_owp[101];
double score[101];
double get_owp(int opp, int be_gain)
{
    int first_iteration;
    return ((double) (win[opp] - be_gain)) / ((double) (game[opp] - 1));
}

int Main()
{
    int first_iteration;
    int s;
    int tc;
    scanf("%d", &s);
    int unhappy;
    int n;
    int next;
    for (unhappy = 1; unhappy <= s; unhappy++) {
	printf("Case #%d:\n", unhappy);
	scanf("%d", &tc);
	char buf[102];
	for (n = 0; n < tc; n++) {
	    game[n] = 0;
	    win[n] = 0;
	    avg_owp[n] = 0.0;
	    score[n] = 0.0;
	    for (next = 0; next < tc; next++)
		table[n][next] = -1;
	}
	for (n = 0; n < tc; n++) {
	    scanf("%s", buf);
	    for (next = 0; next < tc; next++) {
		if (buf[next] == '1') {
		    table[n][next] = 1;
		    win[n]++;
		    game[n]++;
		} else if (buf[next] == '0') {
		    table[n][next] = 0;
		    game[n]++;
		}
	    }
	}
	for (n = 0; n < tc; n++) {
	    score[n] += (0.25 * ((double) win[n])) / ((double) game[n]);
	    for (next = 0; next < tc; next++) {
		if (table[n][next] != (-1)) {
		    avg_owp[n] +=
			get_owp(next, table[next][n]) / ((double) game[n]);
		}
	    }
	    score[n] += 0.50 * avg_owp[n];
	}
	for (n = 0; n < tc; n++)
	    for (next = 0; next < tc; next++)
		if (table[n][next] != (-1))
		    score[n] +=
			(avg_owp[next] / ((double) game[n])) * 0.25;
	for (n = 0; n < tc; n++)
	    printf("%.12lf\n", score[n]);
    }
    return 0;
}
