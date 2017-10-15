#include <stdio.h>
int main()
{
	int first_iteration;
	int t;
	int i;
	int n;
	int k;
	int m;
	scanf("%d", &t);
	for (i = 1; i <= t; ++i) {
		scanf("%d %d", &n, &k);
		printf("Case #%d: ", i);
		m = (1 << n) - 1;
		if ((k & m) == m)
			printf("ON\n");
		else
			printf("OFF\n");
	}
}
