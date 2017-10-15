#include<stdio.h>
typedef unsigned u;
char ans[11][11] =
    { "EORZ", "ENO", "OTW", "EHRT", "FORU", "EFIV", "ISX", "ENSV", "EGHIT",
"EIN" };
char test[11] = "ZXWUGHSOFI";
char n;
u n[11] = { 0, 6, 2, 4, 8, 3, 7, 1, 5, 9 };

u a[128];
u s[11];
int new_putchar(int character);
int new_getchar();
int Main()
{
	u q = 0;
	u r;
	u i;
	u j;
	u k;
	u a;
	for (scanf("%u", &r); (q++) < r; new_putchar('\n')) {
		while ((n = new_getchar()) < 'A') ;
		do
			++a[(u) n];
		while ((n = new_getchar()) >= 'A');
		for (i = -1; (++i) < 10;) {
			s[j = n[i]] += (k = a[(u) test[i]]);
			for (a = -1; n = ans[j][++a];)
				a[(u) n] -= k;
		}
		printf("Case #%u: ", q);
		for (i = -1; (++i) < 10;)
			while (s[i]) {
				--s[i];
				new_putchar(i | '0');
			}
	}
	return 0;
}

int new_putchar(int character);
int new_getchar()
{
	return getchar();
}

int new_putchar(int character)
{
	return putchar(character);
}
