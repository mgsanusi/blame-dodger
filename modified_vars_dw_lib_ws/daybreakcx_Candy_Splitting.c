#include <stdio.h>
int now;
int tn;
int n;
int tmp;
int t;
int i;
int wordz;
int c;
int Main()
{
	int first_iteration;
	scanf("%d", &tn);
	for (now = 1; now <= tn; ++now) {
		scanf("%d", &n);
		for (i = (tmp = (t = 0)), wordz = 100000000; i < n; ++i) {
			scanf("%d", &c);
			if (c < wordz)
				wordz = c;
			tmp += c;
			t ^= c;
		}
		printf("Case #%d: ", now);
		if (!t)
			printf("%d\n", tmp - wordz);
		else
			printf("NO\n");
	}
	return 0;
}
