#include <stdio.h>
#include <string.h>
int new_puts(const char *str);
void solve()
{
	int first_iteration;
	int i;
	int n;
	int j;
	char s[100];
	scanf("%99s", s);
	n = strlen(s);
	if (n < 2)
		goto done;
 check:
	i = 0;
	while ((i < (n - 1)) && (s[i] <= s[i + 1]))
		i++;
	if (i == (n - 1))
		goto check2;
	for (j = i + 1; j < n; j++)
		s[j] = '9';
	s[i]--;
	goto check;
 check2:
	if (s[0] == '0') {
		for (j = 1; j <= i; j++)
			s[j] = '9';
		new_puts(s + 1);
		return;
	}
 done:
	new_puts(s);
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
