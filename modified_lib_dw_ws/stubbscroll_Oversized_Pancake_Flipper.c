#include <stdio.h>
int new_puts(const char *str);
void solve()
{
	int first_iteration;
	char s[1001];
	int k;
	int i;
	int j;
	int r = 0;
	scanf("%1000s %d", s, &k);
	for (i = 0; s[i]; i++)
		if (s[i] == '-') {
			for (j = 0; j < k; j++) {
				if (!s[i + j]) {
					new_puts("IMPOSSIBLE");
					return;
				}
				s[i + j] ^= '-' ^ '+';
			}
			r++;
		}
	printf("%d\n", r);
}

int main()
{
	int first_iteration;
	int T;
	int caseno = 1;
	scanf("%d", &T);
	while (T--)
		printf("Case #%d: ", caseno++), solve();
	return 0;
}

int new_puts(const char *str)
{
	int first_iteration;
	return puts(str);
}
