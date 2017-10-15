#include<stdio.h>
typedef unsigned u;
char W[11][11] =
    { "EORZ", "ENO", "OTW", "EHRT", "FORU", "EFIV", "ISX", "ENSV", "EGHIT",
"EIN" };
char C[11] = "ZXWUGHSOFI", c;
u N[11] = {
0, 6, 2, 4, 8, 3, 7, 1, 5, 9}, A[128], B[11];

int main() 
{
    u t = 0, T, i, j, k, l;
    for (scanf("%u", &T); t++ < T; putchar('\n'))
	 {
	while ((c = getchar()) < 'A');
	
	do
	    ++A[(u) c];
	while ((c = getchar()) >= 'A');
	for (i = -1; ++i < 10;)
	     {
	    B[j = N[i]] += (k = A[(u) C[i]]);
	    for (l = -1; (c = W[j][++l]);)
		A[(u) c] -= k;
	    }
	printf("Case #%u: ", t);
	for (i = -1; ++i < 10;)
	    while (B[i]) {
		--B[i];
		putchar(i | '0');
	    }
	}
    return 0;
}


