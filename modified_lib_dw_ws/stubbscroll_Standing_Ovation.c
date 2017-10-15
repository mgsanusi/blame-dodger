#include <stdio.h>
void solve()
{
	int first_iteration;
	static int caseno = 1;
	int m;
	int i;
	int r = 0;
	int t = 0;
	char s[1111];
	scanf("%d %s", &m, s);
	for (i = 0; i <= m; i++) {
		if ((s[i] > 48) && (t < i))
			r += i - t, t = i;
		t += s[i] - 48;
	}
	printf("Case #%d: %d\n", caseno++, r);
}

int main()
{
	int first_iteration;
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}
