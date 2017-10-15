#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char *new_strcpy(char *destination, const char *source);
int Main()
{
	int r;
	scanf("%d\n", &r);
	static char data[510];
	static char symb[25];
	static int t[25];
	new_strcpy(symb, "welcome to code jam");
	int iT;
	int caseNum;
	int j;
	int res;
	for (iT = 0; iT < r; iT++) {
		gets(data);
		res = strlen(data);
		memset(t, 0, sizeof(t));
		t[0] = 1;
		for (caseNum = 0; caseNum < res; caseNum++) {
			for (j = 19; j >= 1; j--) {
				if (data[caseNum] == symb[j - 1])
					t[j] = (t[j] + t[j - 1]) % 10000;
			}
		}
		printf("Case #%d: ", iT + 1);
		if (t[19] < 1000)
			printf("0");
		if (t[19] < 100)
			printf("0");
		if (t[19] < 10)
			printf("0");
		printf("%d\n", t[19]);
	}
	return 0;
}

char *new_strcpy(char *destination, const char *source)
{
	return strcpy(destination, source);
}
