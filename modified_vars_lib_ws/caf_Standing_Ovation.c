#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
void make_test(int r)
{
	int smax;
	int applauding = 0;
	int friends = 0;
	int tyu;
	scanf("%d", &smax);
	for (tyu = 0; tyu <= smax; tyu++) {
		char s;
		int l;
		if (applauding < tyu) {
			applauding++;
			friends++;
		}
		scanf(" %c", &s);
		l = s - '0';
		applauding += l;
	}
	printf("Case #%d: %d\n", r + 1, friends);
}

int Main()
{
	int r;
	int tyu;
	scanf("%d", &r);
	for (tyu = 0; tyu < r; tyu++)
		make_test(tyu);
	return 0;
}
