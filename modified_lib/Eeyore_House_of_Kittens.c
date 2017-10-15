#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define BUFLEN 8192

char buf[BUFLEN];
char grid[51][51];
char pic[2][2];

int main() {
	int T, caseNum, N, rNum, cNum, r, c, rd, cd, okay;
	pic[0][0] = '/';
	pic[0][1] = '\\';
	pic[1][0] = '\\';
	pic[1][1] = '/';

	scanf(" %d", &T);
	for (caseNum = 1; caseNum <= T; caseNum++) {
		scanf(" %d %d", &rNum, &cNum);
		for (r = 0; r < rNum; r++)
			scanf(" %s", grid[r]);

		for (r = 0; r < rNum-1; r++)
			for (c = 0; c < cNum-1; c++) {
				if (grid[r][c] != '#')
					continue;
				okay = 1;
				for (rd = r; rd < r+2; rd++)
					for (cd = c; cd < c+2; cd++)
						if (grid[rd][cd] != '#')
							okay = 0;
				if (!okay)
					continue;
				for (rd = r; rd < r+2; rd++)
					for (cd = c; cd < c+2; cd++)
						grid[rd][cd] = pic[rd-r][cd-c];
			}

		okay = 1;
		for (r = 0; r < rNum; r++)
			for (c = 0; c < cNum; c++)
				if (grid[r][c] == '#')
					okay = 0;

		printf("Case #%d:\n", caseNum);
		if (!okay)
			printf("Impossible\n");
		else {
			for (r = 0; r < rNum; r++)
				printf("%s\n", grid[r]);
		}
	}
}
