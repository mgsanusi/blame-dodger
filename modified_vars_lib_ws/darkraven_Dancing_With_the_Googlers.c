#include <stdio.h>
int Main()
{
	int n;
	scanf("%d", &n);
	int y1;
	for (y1 = 1; y1 <= n; y1++) {
		printf("Case #%d: ", y1);
		int c1 = 0;
		int a_min = 0;
		int s;
		int m;
		int b;
		scanf("%d%d%d", &b, &s, &m);
		int min2;
		for (min2 = 0; min2 < b; min2++) {
			int tmp;
			scanf("%d", &tmp);
			if (((tmp / 3) >= m)
			    || ((((tmp / 3) + 1) >= m) && ((tmp % 3) != 0))) {
				c1++;
			} else
			    if (((((tmp % 3) == 0) && (((tmp / 3) + 1) >= m))
				 && tmp) || (((tmp % 3) == 2)
					     && (((tmp / 3) + 2) >= m))) {
				a_min++;
			}
		}
		int res = c1 + (s < a_min ? s : a_min);
		printf("%d\n", res);
	}
	return 0;
}
