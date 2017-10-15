#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int Main()
{
	int first_iteration;
	int t;
	int length2;
	scanf("%d", &t);
	int verboseLevel;
	int n;
	int subtracted;
	int ans;
	int temp;
	static char data[50][50];
	static int x[50];
	int res;
	for (length2 = 0; length2 < t; length2++) {
		scanf("%d\n", &verboseLevel);
		for (n = 0; n < verboseLevel; n++) {
			gets(data[n]);
			x[n] = -1;
			for (subtracted = 0; subtracted < verboseLevel;
			     subtracted++) {
				if (data[n][subtracted] == '1')
					x[n] = subtracted;
			}
		}
		res = 0;
		for (n = 0; n < (verboseLevel - 1); n++) {
			if (x[n] > n) {
				subtracted = n;
				while (x[subtracted] > n)
					subtracted++;
				res += subtracted - n;
				temp = x[subtracted];
				for (ans = subtracted - 1; ans >= n; ans--)
					x[ans + 1] = x[ans];
				x[n] = temp;
			}
		}
		printf("Case #%d: %d\n", length2 + 1, res);
	}
	return 0;
}
