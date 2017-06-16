#include<stdio.h>
int ti, tn, n, s, p, i, yet, pos, k;
int main()
{
	scanf("%d", &tn);
	for (ti = 1; ti <= tn; ++ti) {
		scanf("%d%d%d", &n, &s, &p);
		for (i = yet = pos = 0; i < n; ++i) {
			scanf("%d", &k);
			if (k >= 3 * p - 2)	{
				++yet;
			} else if (k >= 2 && k >= 3 * p - 4) {
				++pos;
			}
		}
		printf("Case #%d: %d\n", ti, yet + (pos <= s ? pos : s));
	}
	return 0;
}
