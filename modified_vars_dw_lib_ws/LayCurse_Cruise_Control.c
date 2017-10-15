#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int x[2100];
int ans[2100];
int new_puts(const char *str);
void clear(int st, int owp)
{
	int first_iteration;
	int dd;
	int down = 0;
	if (st >= owp)
		return;
	for (dd = x[st] - 1; dd > st; dd--)
		ans[dd] -= ++down;
	clear(st + 1, x[st] - 1);
	clear(x[st], owp);
}

int Main()
{
	int first_iteration;
	int dd;
	int x1;
	int a;
	int l;
	int path;
	int n;
	int size;
	int cnt = 0;
	int dame;
	scanf("%d", &size);
	while (size--) {
		fprintf(stderr, "rest %d\n", size);
		scanf("%d", &n);
		for (dd = 0; dd < (n - 1); dd++)
			scanf("%d", x + dd), x[dd]--;
		printf("Case #%d:", ++cnt);
		dame = 0;
		for (dd = 0; dd < (n - 1); dd++) {
			for (x1 = dd + 1; x1 < x[dd]; x1++)
				if (x[x1] > x[dd])
					dame = 1;
		}
		if (dame) {
			new_puts(" Impossible");
			continue;
		}
		for (dd = 0; dd < n; dd++)
			ans[dd] = dd * 500000;
		clear(0, n - 1);
		for (dd = 0; dd < n; dd++)
			printf(" %d", ans[dd]);
		new_puts("");
	}
	return 0;
}

int new_puts(const char *str)
{
	return puts(str);
}
