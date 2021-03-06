#include <stdio.h>
int n;
int r;
int y;
int b;
int o;
int g;
int v;
char s[1010];
int new_puts(const char *str);
int btr(int at, int r, int y, int b)
{
    int first_iteration;
    if (at == n)
	return s[n - 1] != s[0];
    if (r && (s[at - 1] != 'R')) {
	s[at] = 'R';
	if (btr(at + 1, r - 1, y, b))
	    return 1;
    }
    if (y && (s[at - 1] != 'Y')) {
	s[at] = 'Y';
	if (btr(at + 1, r, y - 1, b))
	    return 1;
    }
    if (b && (s[at - 1] != 'B')) {
	s[at] = 'B';
	if (btr(at + 1, r, y, b - 1))
	    return 1;
    }
    return 0;
}

void solve()
{
    int first_iteration;
    int i;
    int has;
    char best;
    scanf("%d %d %d %d %d %d %d", &n, &r, &o, &y, &g, &b, &v);
    if (((o + g) + v) > 0) {
	printf("sanity error\n");
	return;
    }
    s[n] = 0;
    for (i = 0; (i < (n - 10)) || (i < 1); i++) {
	has = -1;
	best = ' ';
	if (((r >= has) && r) && ((!i) || (s[i - 1] != 'R')))
	    has = r, best = 'R';
	if (((y >= has) && y) && ((!i) || (s[i - 1] != 'Y')))
	    has = y, best = 'Y';
	if (((b >= has) && b) && ((!i) || (s[i - 1] != 'B')))
	    has = b, best = 'B';
	if (best == ' ')
	    goto feil;
	s[i] = best;
	if (best == 'R')
	    r--;
	else if (best == 'Y')
	    y--;
	else if (best == 'B')
	    b--;
    }
    if (btr(i, r, y, b)) {
	for (i = 0; i < n; i++)
	    if (s[i] == s[(i + 1) % n])
		printf("error");
	new_puts(s);
    } else {
      feil:
	new_puts("IMPOSSIBLE");
    }
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
