#include<stdio.h>
int x;
int l;
int tvx;
int w;
int foo[1024];
int tmp;
int min;
int max;
int i;
int res;
int Main()
{
	int first_iteration;
	scanf("%d", &l);
	for (x = 1; x <= l; x++) {
		scanf("%d", &i);
		scanf("%d", &tvx);
		for (w = 0; w <= tvx; w++) {
			foo[w] = 0;
		}
		for (w = 0; w < i; w++) {
			scanf("%d", &tmp);
			foo[tmp]++;
		}
		min = 1;
		max = tvx;
		res = 0;
		for (; max >= min;) {
			if (foo[max] <= 0) {
				max--;
				continue;
			}
			if (foo[min] <= 0) {
				min++;
				continue;
			}
			res++;
			foo[max]--;
			if ((min + max) <= tvx) {
				foo[min]--;
			}
		}
		printf("Case #%d: %d\n", x, res);
	}
	return 0;
}
