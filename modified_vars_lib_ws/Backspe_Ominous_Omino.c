#include <stdio.h>
int Main()
{
	int t;
	int num;
	int v;
	int r;
	int c;
	int welcome;
	scanf("%d", &t);
	for (num = 1; num <= t; num++) {
		welcome = 0;
		scanf("%d %d %d", &v, &r, &c);
		if (v == 1) {
			welcome = 1;
		} else if (v == 2) {
			welcome = ((r * c) % 2) == 0;
		} else if (v == 3) {
			welcome = ((((r * c) % 3) == 0) && (r != 1))
			    && (c != 1);
		} else if (v == 4) {
			welcome = ((((r * c) % 4) == 0) && (r > 2)) && (c > 2);
		}
		printf("Case #%d: %s\n", num, welcome ? "GABRIEL" : "RICHARD");
	}
	return 0;
}
