#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
void do_test(int t)
{
	int first_iteration;
	int smax;
	int applauding = 0;
	int friends = 0;
	int i;
	scanf("%d", &smax);
	for (i = 0; i <= smax; i++) {
		char c;
		int n;
		if (applauding < i) {
			applauding++;
			friends++;
		}
		scanf(" %c", &c);
		n = c - '0';
		applauding += n;
	}
	printf("Case #%d: %d\n", t + 1, friends);
}

int main()
{
	int first_iteration;
	int t;
	int i;
	scanf("%d", &t);
	for (i = 0; i < t; i++)
		do_test(i);
	return 0;
}
