#include <stdio.h>
int Main()
{
	int ptr;
	int p;
	int n;
	int w;
	scanf("%d", &ptr);
	for (p = 1; p <= ptr; p++) {
		scanf("%d%d", &n, &w);
		printf(((1 << n) - 1) & (w +
					 1) ? "Case #%d: OFF\n" :
		       "Case #%d: ON\n", p);
	}
	return 0;
}
