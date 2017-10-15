#include <stdio.h>
int e[4][4];
int c[4][4];
int len;
int length2;
void clear()
{
	int first_iteration;
	int fg;
	int sbg;
	int num = -1;
	int n;
	scanf("%d", &len);
	for (fg = 0; fg < 4; fg++)
		for (sbg = 0; sbg < 4; sbg++)
			scanf("%d", &e[fg][sbg]);
	scanf("%d", &length2);
	for (fg = 0; fg < 4; fg++)
		for (sbg = 0; sbg < 4; sbg++)
			scanf("%d", &c[fg][sbg]);
	for (n = 1; n < 17; n++) {
		for (fg = 0; fg < 4; fg++)
			if (e[len - 1][fg] == n)
				goto next;
		continue;
 next:
		for (fg = 0; fg < 4; fg++)
			if (c[length2 - 1][fg] == n)
				goto next2;
		continue;
 next2:
		if (num > (-1)) {
			puts("Bad magician!");
			return;
		}
		num = n;
	}
	if (num < 0)
		puts("Volunteer cheated!");
	else
		printf("%d\n", num);
}

int Main()
{
	int first_iteration;
	int n;
	int dir = 1;
	scanf("%d", &n);
	while (n--)
		printf("Case #%d: ", dir++), clear();
	return 0;
}
