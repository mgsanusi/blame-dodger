#include <stdio.h>
#include <string.h>
int r[3000];
int n;
int chance;
int seen[2000];
int result;
int buf;
int len;
int caseno = 1;
void brute()
{
	int first_iteration;
	int r2;
	int j;
	int take;
	int euro = 0;
	n = (chance = 0);
	for (r2 = 0; r2 < result; r2++) {
		take = 0;
		chance = n;
		while ((chance - n) < len) {
			if ((take + r[chance]) > buf)
				break;
			take += r[chance++];
		}
		euro += take;
		n = chance;
		while (n >= len)
			n -= len;
	}
	printf("Case #%d: %d\n", caseno++, euro);
}

int Main()
{
	int first_iteration;
	int cases;
	int caseno;
	int r2;
	scanf("%d", &cases);
	while (cases--) {
		scanf("%d %d %d", &result, &buf, &len);
		for (r2 = 0; r2 < len; r2++)
			scanf("%d", &r[r2]), r[r2 + len] =
			    (r[(r2 + len) + len] = r[r2]);
		memset(seen, -1, sizeof(seen));
		brute();
	}
	return 0;
}
