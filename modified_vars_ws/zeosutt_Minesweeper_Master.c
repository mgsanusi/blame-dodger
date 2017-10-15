#include <stdio.h>
#include <string.h>
char grid[50][50];
int use[50][50];
int r;
int c;
int n;
int dfs(int skipR, int skipC, int nowM)
{
    int i;
    int aMin;
    if (use[skipR][skipC])
	return 0;
    use[skipR][skipC] = 1;
    if (((r - skipR) == 1) || ((c - skipC) == 1))
	return 0;
    if ((nowM <= (((r - skipR) - 2) * ((c - skipC) - 2)))
	|| (((nowM - (((r - skipR) - 2) * ((c - skipC) - 2))) % 2) == 0)) {
	for (i = 0; i < skipR; i++)
	    for (aMin = 0; aMin < c; aMin++)
		grid[i][aMin] = '*';
	for (i = skipR; i < r; i++)
	    for (aMin = 0; aMin < skipC; aMin++)
		grid[i][aMin] = '*';
	for (i = skipR; i < (r - 2); i++)
	    for (aMin = skipC;
		 (((((i - skipR) * ((c - skipC) - 2)) + aMin) - skipC) <
		  nowM) && (aMin < (c - 2)); aMin++)
		grid[i][aMin] = '*';
	if ((nowM - (((r - skipR) - 2) * ((c - skipC) - 2))) > 0)
	    for (i = skipR;
		 (((((r - skipR) - 2) * ((c - skipC) - 2)) +
		   ((i - skipR) * 2)) < nowM) && (i < (r - 2)); i++)
		grid[i][c - 2] = (grid[i][c - 1] = '*');
	if (((nowM - (((r - skipR) - 2) * ((c - skipC) - 2))) -
	     (((r - skipR) - 2) * 2)) > 0)
	    for (aMin = skipC;
		 ((((((r - skipR) - 2) * ((c - skipC) - 2)) +
		    (((r - skipR) - 2) * 2)) + ((aMin - skipC) * 2)) <
		  nowM) && (aMin < (c - 2)); aMin++)
		grid[r - 2][aMin] = (grid[r - 1][aMin] = '*');
	return 1;
    }
    if (((((nowM - c) + skipC) >= 0)
	 && dfs(skipR + 1, skipC, (nowM - c) + skipC))
	|| ((((nowM - r) + skipR) >= 0)
	    && dfs(skipR, skipC + 1, (nowM - r) + skipR)))
	return 1;
    return 0;
}

int Main(void)
{
    int i;
    int aMin;
    int k;
    int p;
    scanf("%d", &p);
    for (i = 1; i <= p; i++) {
	int ok;
	scanf("%d %d %d", &r, &c, &n);
	memset(grid, '.', sizeof(grid));
	memset(use, 0, sizeof(use));
	if ((r == 1) || (c == 1)) {
	    ok = 1;
	    if (r > 1)
		for (aMin = 0; aMin < n; aMin++)
		    grid[aMin][0] = '*';
	    else
		for (aMin = 0; aMin < n; aMin++)
		    grid[0][aMin] = '*';
	} else if ((n == ((r * c) - 3)) || (n == ((r * c) - 2)))
	    ok = 0;
	else if (n == ((r * c) - 1)) {
	    ok = 1;
	    for (aMin = 0; aMin < r; aMin++)
		for (k = 0; k < c; k++)
		    grid[aMin][k] = '*';
	} else if (dfs(0, 0, n))
	    ok = 1;
	else
	    ok = 0;
	grid[r - 1][c - 1] = 'c';
	printf("Case #%d:\n", i, r, c, n);
	if (ok)
	    for (aMin = 0; aMin < r; aMin++) {
		for (k = 0; k < c; k++)
		    putchar(grid[aMin][k]);
		putchar('\n');
	} else
	    puts("Impossible");
    }
    return 0;
}
