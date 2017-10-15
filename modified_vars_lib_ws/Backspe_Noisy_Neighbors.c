#include <stdio.h>
int check_yes(int f, int w)
{
	if (f >= (w * 2)) {
		return check_yes(f - w, w) + 1;
	} else if (f <= w) {
		return w;
	} else {
		return w + 1;
	}
}

int check_num(int f, int w)
{
	if (f >= (w * 2)) {
		return check_num(f - w, w) + 1;
	} else {
		return 1;
	}
}

int Main()
{
	int m;
	int n;
	int cases;
	int c;
	int n;
	int data;
	scanf("%d", &n);
	for (m = 1; m <= n; m++) {
		scanf("%d %d %d", &cases, &c, &n);
		data = ((cases - 1) * check_num(c, n)) + check_yes(c, n);
		printf("Case #%d: %d\n", m, data);
	}
	return 0;
}
