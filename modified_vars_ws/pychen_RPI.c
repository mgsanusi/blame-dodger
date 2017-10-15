#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int ret;
int n;
char grid[100][100];
int clear()
{
	int i;
	int j;
	for (i = 0; i < ret; i++)
		for (j = 0; j < n; j++)
			if (grid[i][j] == '#') {
				if ((i == (ret - 1)) || (j == (n - 1)))
					return 0;
				if (((grid[i][j + 1] != '#')
				     || (grid[i + 1][j] != '#'))
				    || (grid[i + 1][j + 1] != '#'))
					return 0;
				grid[i][j] = '/';
				grid[i][j + 1] = '\\';
				grid[i + 1][j] = '\\';
				grid[i + 1][j + 1] = '/';
			}
	for (i = 0; i < ret; i++)
		printf("%s\n", grid[i]);
	return 1;
}

int Main()
{
	int n;
	int tCase;
	scanf("%d", &tCase);
	for (n = 1; n <= tCase; n++) {
		int i;
		scanf("%d %d", &ret, &n);
		for (i = 0; i < ret; i++)
			scanf("%s", grid[i]);
		printf("Case #%d:\n", n);
		if (!clear())
			printf("Impossible\n");
	}
	return 0;
}
