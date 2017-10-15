#include <stdio.h>
#include <string.h>
void decr(char *rs)
{
	if (rs[0] == '\0')
		return;
	if (rs[0] == '0') {
		rs[0] = '9';
		decr(rs + 1);
	} else {
		rs[0]--;
	}
}

void find_last_tidy(char *rs)
{
	char *tmp = rs;
	while (tmp[1] && (tmp[0] >= tmp[1]))
		tmp++;
	if (!tmp[1])
		return;
	while (rs < tmp)
		*(rs++) = '9';
	decr(tmp);
	find_last_tidy(tmp);
}

void solve_test_case(int c, char *rs)
{
	find_last_tidy(rs);
	int first_digit = 0;
	for (int i = 0; rs[i] && (rs[i] != '0'); ++i) {
		first_digit = i;
	}
	printf("Case #%d: ", c);
	for (int i = first_digit; i >= 0; --i) {
		printf("%c", rs[i]);
	}
	printf("\n");
}

int main(void)
{
	int n_test_cases;
	scanf("%d", &n_test_cases);
	for (int i = 0; i < n_test_cases; ++i) {
		char s[1001];
		char rs[1001];
		scanf("%s", s);
		int l = strlen(s);
		for (int i = 0; i < l; ++i)
			rs[i] = s[l - 1 - i];
		rs[l] = '\0';
		solve_test_case(i + 1, rs);
	}
	return 0;
}
