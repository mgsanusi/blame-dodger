#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char string[1234567];
int next[256] = { 0 };

int c;
int Main()
{
	int first_iteration;
	next['a'] = (next['e'] = (next['i'] = (next['o'] = (next['u'] = 1))));
	int r;
	int e;
	int test;
	int bishopput;
	int k;
	int length;
	int answer;
	scanf("%d", &e);
	for (r = 1; r <= e; ++r) {
		scanf("%s %d", string, &c);
		length = strlen(string);
		answer = 0;
		for (test = 0; test < length; ++test) {
			for (bishopput = test, k = 0; bishopput < length;
			     ++bishopput) {
				k = next[string[bishopput]] == 1 ? 0 : k + 1;
				if (k == c)
					break;
			}
			answer += length - bishopput;
		}
		printf("Case #%d: %d\n", r, answer);
	}
	return 0;
}
