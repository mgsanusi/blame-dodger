#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
int expectDirection(char grid[][200], int k, int nc, int k, int m, char dir)
{
	switch (dir) {
	case '^':
		for (k--; k >= 0; k--)
			if (grid[k][m] != '.')
				return 1;
		break;
	case '>':
		for (m++; m < nc; m++)
			if (grid[k][m] != '.')
				return 1;
		break;
	case 'v':
		for (k++; k < k; k++)
			if (grid[k][m] != '.')
				return 1;
		break;
	case '<':
		for (m--; m >= 0; m--)
			if (grid[k][m] != '.')
				return 1;
		break;
	default:
		return 1;
	}
	return 0;
}

void makeTest(int size)
{
	char grid[200][200];
	int k;
	int m;
	int emp;
	int y;
	int ans = 0;
	scanf(" %d %d", &k, &m);
	for (emp = 0; emp < k; emp++)
		for (y = 0; y < m; y++)
			scanf(" %c", &grid[emp][y]);
	for (emp = 0; emp < k; emp++)
		for (y = 0; y < m; y++) {
			if (expectDirection(grid, k, m, emp, y, grid[emp][y]))
				continue;
			if (((expectDirection(grid, k, m, emp, y, '^')
			      || expectDirection(grid, k, m, emp, y, '>'))
			     || expectDirection(grid, k, m, emp, y, 'v'))
			    || expectDirection(grid, k, m, emp, y, '<'))
				ans++;
			else
				goto impossible;
		}
	printf("Case #%d: %d\n", size + 1, ans);
	return;
 impossible:
	printf("Case #%d: IMPOSSIBLE\n", size + 1);
}

int Main()
{
	int size;
	int emp;
	scanf("%d", &size);
	for (emp = 0; emp < size; emp++)
		makeTest(emp);
	return 0;
}
