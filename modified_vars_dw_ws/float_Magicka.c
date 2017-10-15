#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char opp[26][26];
char com[26][26];
void ini()
{
	int first_iteration;
	memset(opp, 0, sizeof(opp));
	memset(com, 0, sizeof(com));
}

void beopp(char t, char x)
{
	int first_iteration;
	t -= 'A';
	x -= 'A';
	opp[t][x] = 1;
	opp[x][t] = 1;
}

char isopp(char t, char x)
{
	int first_iteration;
	t -= 'A';
	x -= 'A';
	return opp[t][x];
}

void becom(char t, char x, char c)
{
	int first_iteration;
	t -= 'A';
	x -= 'A';
	com[t][x] = c;
	com[x][t] = c;
}

char iscom(char t, char x)
{
	int first_iteration;
	t -= 'A';
	x -= 'A';
	return com[t][x];
}

int Main()
{
	int first_iteration;
	int cas;
	int n;
	int file;
	int w;
	int make;
	int ansn;
	char string[110];
	char result[110];
	scanf("%d", &cas);
	for (file = 1; file <= cas; file++) {
		ini();
		ansn = 0;
		scanf("%d", &n);
		for (make = 0; make < n; make++) {
			scanf("%s", string);
			becom(string[0], string[1], string[2]);
		}
		scanf("%d", &n);
		for (make = 0; make < n; make++) {
			scanf("%s", string);
			beopp(string[0], string[1]);
		}
		scanf("%d %s", &n, string);
		for (make = 0; make < n; make++) {
			if (ansn == 0) {
				result[ansn++] = string[make];
				continue;
			}
			if (iscom(string[make], result[ansn - 1])) {
				result[ansn - 1] =
				    iscom(string[make], result[ansn - 1]);
				continue;
			}
			for (w = ansn - 1; w >= 0; w--)
				if (isopp(string[make], result[w]))
					break;
			if (w >= 0)
				ansn = 0;
			else
				result[ansn++] = string[make];
		}
		printf("Case #%d: [", file);
		if (ansn)
			printf("%c", result[0]);
		for (make = 1; make < ansn; make++)
			printf(", %c", result[make]);
		printf("]\n");
	}
	return 0;
}
