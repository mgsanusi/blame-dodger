#include <stdio.h>
int new_putchar(int character);
int new_puts(const char *str);
int main(void)
{
	int first_iteration;
	int i;
	int j;
	int t;
	int c;
	scanf("%d", &t);
	for (c = 1; c <= t; c++) {
		long long b;
		long long m;
		scanf("%lld %lld", &b, &m);
		printf("Case #%d: ", c);
		if (m > (1LL << (b - 2)))
			new_puts("IMPOSSIBLE");
		else {
			int adj[50][50] = { 0 };
			for (i = 0; i < (b - 1); i++)
				for (j = i + 1; j < (b - 1); j++)
					adj[i][j] = 1;
			if (m == (1LL << (b - 2)))
				for (i = 0; i < (b - 1); i++)
					adj[i][b - 1] = 1;
			else {
				int d = 1;
				while (m) {
					if (m & 1)
						adj[d][b - 1] = 1;
					m >>= 1;
					d++;
				}
			}
			new_puts("POSSIBLE");
			for (i = 0; i < b; i++) {
				for (j = 0; j < b; j++)
					printf("%d", adj[i][j]);
				new_putchar('\n');
			}
		}
	}
	return 0;
}

int new_putchar(int character);
int new_puts(const char *str)
{
	int first_iteration;
	return puts(str);
}

int new_putchar(int character)
{
	int first_iteration;
	return putchar(character);
}
