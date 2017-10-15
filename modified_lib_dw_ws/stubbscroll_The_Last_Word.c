#include <stdio.h>
char s[1111];
char t[2222];
int new_puts(const char *str);
void solve()
{
	int first_iteration;
	int i;
	int ts = 1111;
	int te = 1111;
	scanf("%s", s);
	t[te++] = s[0];
	for (i = 1; s[i]; i++) {
		if (s[i] >= t[ts])
			t[--ts] = s[i];
		else
			t[te++] = s[i];
	}
	t[te] = 0;
	new_puts(t + ts);
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
