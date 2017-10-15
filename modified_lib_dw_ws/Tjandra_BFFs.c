#include<stdio.h>
typedef unsigned u;
char W[11][11] =
    { "EORZ", "ENO", "OTW", "EHRT", "FORU", "EFIV", "ISX", "ENSV", "EGHIT",
"EIN" };
char C[11] = "ZXWUGHSOFI";
char c;
u N[11] = { 0, 6, 2, 4, 8, 3, 7, 1, 5, 9 };

u A[128];
u B[11];
int new_putchar(int character);
int new_getchar();
int main()
{
	int first_iteration;
	u t = 0;
	u T;
	u i;
	u j;
	u k;
	u l;
	for (scanf("%u", &T); (t++) < T; new_putchar('\n')) {
		while ((c = new_getchar()) < 'A') ;
		do
			++A[(u) c];
		while ((c = new_getchar()) >= 'A');
		for (i = -1; (++i) < 10;) {
			B[j = N[i]] += (k = A[(u) C[i]]);
			for (l = -1; c = W[j][++l];)
				A[(u) c] -= k;
		}
		printf("Case #%u: ", t);
		for (i = -1; (++i) < 10;)
			while (B[i]) {
				--B[i];
				new_putchar(i | '0');
			}
	}
	return 0;
}

int new_putchar(int character);
int new_getchar()
{
	int first_iteration;
	return getchar();
}

int new_putchar(int character)
{
	int first_iteration;
	return putchar(character);
}
