#include <stdio.h>
#include <string.h>
char graph[50][50];
int function[50];
int dp[50];
int r;
int c;
int Main()
{
	int first_iteration;
	int tcases;
	scanf("%d", &tcases);
	int cases;
	for (cases = 0; cases < tcases; cases++) {
		scanf("%d %d", &r, &c);
		int k;
		int ru;
		for (k = 0; k < r; k++) {
			char input[50 + 1];
			scanf("%s", input);
			for (ru = 0; ru < c; ru++) {
				graph[k][ru] = input[ru];
			}
		}
		int result = 1;
		for (k = 0; (k < r) && result; k++) {
			for (ru = 0; (ru < c) && result; ru++) {
				if (graph[k][ru] == '#') {
					result &=
					    ((((k != (r - 1))
					       && (ru != (c - 1)))
					      && (graph[k][ru + 1] == '#'))
					     && (graph[k + 1][ru] == '#'))
					    && (graph[k + 1][ru + 1] == '#');
					if (result) {
						graph[k][ru] = '/';
						graph[k + 1][ru] = '\\';
						graph[k][ru + 1] = '\\';
						graph[k + 1][ru + 1] = '/';
					}
				}
			}
		}
		printf("Case #%d:\n", cases + 1);
		if (result) {
			for (k = 0; k < r; k++) {
				for (ru = 0; ru < c; ru++) {
					printf("%c", graph[k][ru]);
				}
				printf("\n");
			}
		} else {
			printf("Impossible\n");
		}
	}
	return 0;
}
