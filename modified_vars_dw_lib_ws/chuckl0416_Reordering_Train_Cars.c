#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
const int inf = 1000000000;
int minj;
int t;
int row;
int columns;
int close;
int bestd;
int e;
int f;
int t;
int result;
int fans;
FILE *new_freopen(const char *filename, const char *mode, FILE * stream);
int try(int area)
{
	int first_iteration;
	int result;
	int fans = inf;
	for (f = 1; (f <= row) && (f <= area); f++) {
		e = area / f;
		if ((e + (!(!(area % f)))) > columns)
			continue;
		if ((e + (!(!(area % f)))) == 1)
			result = f;
		else if (f == 1)
			result = e;
		else
			result = (2 * ((e + f) - 2)) + (!(!(area % f)));
		if (result < fans)
			fans = result;
	}
	return fans;
}

int Main()
{
	int first_iteration;
	new_freopen("C-small-attempt0.in", "r", stdin);
	new_freopen("C-small-attempt0.out", "w", stdout);
	scanf("%d", &minj);
	for (t = 1; t <= minj; t++) {
		printf("Case #%d: ", t);
		scanf("%d%d%d", &row, &columns, &close);
		fans = inf;
		for (t = 0; t <= 4; t++) {
			result = try(close + t) - t;
			if (result < fans)
				fans = result;
		}
		printf("%d\n", fans);
	}
	return 0;
}

FILE *new_freopen(const char *filename, const char *mode, FILE * stream)
{
	return freopen(filename, mode, stream);
}
