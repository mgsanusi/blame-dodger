#include <stdio.h>
 int main()
{
	int t, n, s, p, x, a, b, k;
	scanf("%d", &t);
	for (k = 1; k <= t; k++) {
		a = b = 0;
		scanf("%d%d%d", &n, &s, &p);
		while (n--) {
			scanf("%d", &x);
			if (x >= p * 3 - 2)
				a++;
			
			else if (x >= p * 3 - 4 && x >= 2)
				b++;
		}
		printf("Case #%d: %d\n", k, a + (s < b ? s : b));
	}
	return 0;
}


