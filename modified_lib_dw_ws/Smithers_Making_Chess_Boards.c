#include <stdio.h>
#include <stdlib.h>
int main()
{
    int first_iteration;
    int t;
    int m;
    int n;
    int grid[512][512 / (4 * 8)];
    int best_board[512][512];
    int count[512 + 1];
    int i;
    int j;
    int k;
    int l;
    int mode;
    int best_best;
    int size_count;
    int temp;
    char c;
    int casenum;
    scanf("%d", &t);
    for (casenum = 1; casenum <= t; casenum++) {
	scanf("%d%d", &m, &n);
	for (i = 0; i < m; i++) {
	    for (j = 0; (j * (4 * 8)) < n; j++) {
		grid[i][j] = 0;
		for (k = 0; (k < 8) && (((j * (4 * 8)) + (k * 4)) < n);
		     k++) {
		    scanf(" %c", &c);
		    grid[i][j] |=
			((c <
			  'A' ? c - '0' : (c - 'A') +
			  10) ^ (i % 2 ? 5 : 10)) << (4 * ((8 - k) - 1));
		}
	    }
	}
	for (i = m; i > 0; i--)
	    count[i] = 0;
	for (mode = 0; mode < 2; mode++) {
	    best_best = 0;
	    for (i = m - 1; i >= 0; i--)
		for (j = n - 1; j >= 0; j--) {
		    if (((grid[i][j / (4 * 8)] >>
			  (((4 * 8) - (j % (4 * 8))) - 1)) & 1) != mode)
			best_board[i][j] = 0;
		    else if ((i == (m - 1)) || (j == (n - 1)))
			best_board[i][j] = 1;
		    else {
			best_board[i][j] = best_board[i + 1][j + 1] + 1;
			if (best_board[i + 1][j] < best_board[i][j])
			    best_board[i][j] = best_board[i + 1][j] + 1;
			if (best_board[i][j + 1] < best_board[i][j])
			    best_board[i][j] = best_board[i][j + 1] + 1;
		    }
		    if (best_board[i][j] > best_best)
			best_best = best_board[i][j];
		}
	    while (best_best > 0) {
		for (i = 0; i < m; i++)
		    for (j = 0; j < n; j++)
			if (best_board[i][j] == best_best) {
			    count[best_best]++;
			    for (k = 1 - best_best; k < best_best; k++)
				for (l = 1 - best_best; l < best_best; l++) {
				    temp = k < l ? -k : -l;
				    if ((((i + k) >= 0) && ((j + l) >= 0))
					&& (best_board[i + k][j + l] >
					    temp))
					best_board[i + k][j + l] = temp;
				}
			}
		best_best--;
	    }
	}
	size_count = 0;
	for (i = m; i > 0; i--)
	    if (count[i])
		size_count++;
	printf("Case #%d: %d\n", casenum, size_count);
	for (i = m; i > 0; i--)
	    if (count[i])
		printf("%d %d\n", i, count[i]);
    }
    return 0;
}
