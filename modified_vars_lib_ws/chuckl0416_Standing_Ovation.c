#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
int orangeTime;
int a;
int smax;
char inputS[1200];
int tc;
int b;
int a;
int result;
int clapping;
int peopleInLevel;
FILE *new_freopen(const char *filename, const char *mode, FILE * stream);
int Main()
{
	new_freopen("A-small-attempt0.in", "r", stdin);
	new_freopen("A-small-attempt0.out", "w", stdout);
	scanf("%d", &orangeTime);
	for (a = 1; a <= orangeTime; a++) {
		printf("Case #%d: ", a);
		scanf("%d", &smax);
		scanf("%s", inputS);
		result = 0;
		clapping = 0;
		for (tc = 0; tc <= smax; tc++) {
			peopleInLevel = inputS[tc] - 48;
			if (!peopleInLevel)
				continue;
			if (tc <= clapping) {
				clapping += peopleInLevel;
				continue;
			}
			result += tc - clapping;
			clapping = tc + peopleInLevel;
		}
		printf("%d\n", result);
	}
	return 0;
}

FILE *new_freopen(const char *filename, const char *mode, FILE * stream)
{
	return freopen(filename, mode, stream);
}
