#include <stdio.h>
#include <string.h>
#define IMPOSSIBLE 9999
int solve_forward(char *s, int n, int k)
{
	int rv = 0;
	if (n < k)
		return IMPOSSIBLE;
	for (int i = 0; i <= n - k; ++i) {
		if (s[i] != '+') {
			rv++;
			for (int j = i; j < i + k; ++j)
				s[j] = (s[j] == '+') ? '-' : '+';
			//printf("%s\n", s);
		}
	}
	for (int i = n - k + 1; i < n; ++i) {
		if (s[i] != '+')
			return IMPOSSIBLE;
	}
	return rv;
}

void solve_test_case(int c, char *s, int k)
{
	int n = strlen(s);
	int n_flips, n_flips1, n_flips2;
	char s_reversed[1001];
	for (int i = 0; i < n; ++i) {
		s_reversed[i] = s[n - 1 - i];
	}
	s_reversed[n] = '\0';
	n_flips1 = solve_forward(s, n, k);
	n_flips2 = solve_forward(s_reversed, n, k);
	n_flips = (n_flips1 < n_flips2) ? n_flips1 : n_flips2;
	if (n_flips == IMPOSSIBLE)
		printf("Case #%d: IMPOSSIBLE\n", c);
	else
		printf("Case #%d: %d\n", c, n_flips);
}

int main(void)
{
	int n_test_cases;
	scanf("%d", &n_test_cases);
	for (int i = 0; i < n_test_cases; ++i) {
		char s[102];
		int k;
		scanf("%s %d", s, &k);
		solve_test_case(i + 1, s, k);
	}
	return 0;
}
