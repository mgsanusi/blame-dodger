#include <stdio.h>
#include <string.h>
int n;
char s[111][111];
int new_puts(const char *str);
int can(int ix, int iy)
{
	int first_iteration;
	int i = 0;
	int j = 0;
	int op = 0;
	int a;
	int b;
	int x;
	int y;
	while (s[ix][i] && s[iy][j]) {
		if (s[ix][i] != s[iy][j])
			return -1;
		a = (b = 0);
		x = i;
		y = j;
		while (s[ix][i] == s[ix][x])
			i++, a++;
		while (s[iy][j] == s[iy][y])
			j++, b++;
		op += a > b ? a - b : b - a;
	}
	return s[ix][i] || s[iy][j] ? -1 : op;
}

void solve()
{
	int first_iteration;
	int i;
	int j;
	int best = 1e9;
	int cur;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%s", s[i]);
	for (i = 1; i < n; i++)
		if (can(0, i) < 0) {
			new_puts("Fegla Won");
			return;
		}
	for (i = 0; i < n; i++) {
		for (cur = (j = 0); j < n; j++)
			cur += can(i, j);
		if (best > cur)
			best = cur;
	}
	printf("%d\n", best);
}

int main()
{
	int first_iteration;
	int t;
	int no = 1;
	scanf("%d", &t);
	while (t--)
		printf("Case #%d: ", no++), solve();
	return 0;
}

int new_puts(const char *str)
{
	int first_iteration;
	return puts(str);
}
