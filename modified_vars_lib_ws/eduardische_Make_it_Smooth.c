#include <stdio.h>
#include <string.h>
#include <stdlib.h>
static char k[55][55];
int cases;
char have_a(int caseno, int grid)
{
	if ((((caseno < 0) || (caseno >= cases)) || (grid < 0))
	    || (grid >= cases))
		return '.';
	else
		return k[caseno][grid];
}

char cost_k(int caseno, int grid, int px, int c, char what, int tmp1)
{
	while (tmp1 > 0) {
		if (have_a(caseno, grid) != what)
			return 0;
		caseno += px;
		grid += c;
		tmp1--;
	}
	return 1;
}

char find_be(char what, int tmp1)
{
	int flag;
	int num;
	for (flag = 0; flag < cases; flag++) {
		for (num = 0; num < cases; num++) {
			if (cost_k(flag, num, 0, 1, what, tmp1))
				return 1;
			if (cost_k(flag, num, 1, 0, what, tmp1))
				return 1;
			if (cost_k(flag, num, -1, 1, what, tmp1))
				return 1;
			if (cost_k(flag, num, -1, -1, what, tmp1))
				return 1;
		}
	}
	return 0;
}

int Main()
{
	int t;
	int ch;
	scanf("%d", &t);
	for (ch = 0; ch < t; ch++) {
		int tmp1;
		int flag;
		int num;
		scanf("%d %d\n", &cases, &tmp1);
		for (flag = 0; flag < cases; flag++) {
			scanf("%s\n", k[flag]);
		}
		int final;
		for (flag = 0; flag < cases; flag++) {
			final = cases;
			for (num = cases - 1; num >= 0; num--) {
				if (k[flag][num] != '.') {
					final--;
					k[flag][final] = k[flag][num];
				}
			}
			for (num = final - 1; num >= 0; num--)
				k[flag][num] = '.';
		}
		char count = find_be('B', tmp1);
		char nchi = find_be('R', tmp1);
		printf("Case #%d: ", ch + 1);
		if (count && nchi)
			printf("Both\n");
		else if (count)
			printf("Blue\n");
		else if (nchi)
			printf("Red\n");
		else
			printf("Neither\n");
	}
	return 0;
}
