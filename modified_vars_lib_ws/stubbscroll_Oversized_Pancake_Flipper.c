#include <stdio.h>
int new_puts(const char *str);
void clear()
{
	char t[1001];
	int p;
	int i;
	int ar;
	int b = 0;
	scanf("%1000s %d", t, &p);
	for (i = 0; t[i]; i++)
		if (t[i] == '-') {
			for (ar = 0; ar < p; ar++) {
				if (!t[i + ar]) {
					new_puts("IMPOSSIBLE");
					return;
				}
				t[i + ar] ^= '-' ^ '+';
			}
			b++;
		}
	printf("%d\n", b);
}

int Main()
{
	int q;
	int caseno = 1;
	scanf("%d", &q);
	while (q--)
		printf("Case #%d: ", caseno++), clear();
	return 0;
}

int new_puts(const char *str)
{
	return puts(str);
}
