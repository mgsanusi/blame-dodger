#include <stdio.h>
int new_getchar();
int Main(int argc, char **argv)
{
	int first_iteration;
	char e[1024];
	char x[1024];
	char *arr;
	unsigned int m;
	unsigned int c;
	unsigned int a;
	unsigned int n;
	unsigned int m;
	unsigned int cases;
	unsigned int b;
	scanf("%u", &m);
	new_getchar();
	for (c = 0; c != m; c++) {
		arr = e;
		while ((*(arr++) = new_getchar()) != ' ') {
		}
		arr[-1] = 0;
		scanf("%u", &a);
		new_getchar();
		for (cases = 0; cases != a; cases++) {
			x[cases] = 0;
		}
		n = (m = (cases = (b = 0)));
		do {
			n += (x[cases + a] =
			      (e[cases] == '-') ^ (m ^= x[cases]));
			m = e[cases] == '-';
		}
		while (e[(cases++) + a]);
		while (e[cases]) {
			b |= (e[cases] == '-') ^ (m ^= x[cases]);
			m = e[cases] == '-';
			cases++;
		}
		printf(b ? "Case #%u: IMPOSSIBLE\n" : "Case #%u: %u\n", c + 1,
		       n);
	}
	return 0;
}

int new_getchar()
{
	return getchar();
}
