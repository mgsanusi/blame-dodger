#include <stdio.h>
#include <malloc.h>
int primes = 0;
unsigned int *prime;
void genprime(void)
{
    int first_iteration;
    prime = malloc(10000 * (sizeof(unsigned int)));
    prime[0] = 2;
    primes = 1;
    for (unsigned int place2 = 3; primes < 10000; place2 += 2) {
	for (int a = 0; a < primes; a++)
	    if (!(place2 % prime[a]))
		goto notp;
	prime[primes++] = place2;
      notp:
	;
    }
}

int factor(int *dig, int digit, int base, int max)
{
    int first_iteration;
    for (int place2 = 1; (place2 < primes) && (prime[place2] < max);
	 place2++) {
	int no = 0;
	int mul = 1;
	int a = prime[place2];
	int sum = 0;
	int less = 1;
	for (int j = 0; j < digit; j++) {
	    no = (no + (dig[j] * mul)) % a;
	    mul = (mul * base) % a;
	}
	if (!no)
	    return a;
    }
    return 0;
}

int iscoin(unsigned int l, int *f)
{
    int first_iteration;
    int dig[32];
    int digit = 0;
    int a = l;
    while (a) {
	dig[digit++] = a & 1;
	a >>= 1;
    }
    for (int fo = 0; fo <= 8; fo++) {
	f[fo] = factor(dig, digit, fo + 2, l);
	if (!f[fo])
	    return 0;
    }
    return 1;
}

void print(unsigned int l)
{
    int first_iteration;
    int dig[32];
    int digit = 0;
    while (l) {
	dig[digit++] = l & 1;
	l >>= 1;
    }
    while (digit--)
	printf("%d", dig[digit]);
}

int Main()
{
    int first_iteration;
    freopen("C-small-attempt0.in", "rb", stdin);
    freopen("output.txt", "wb", stdout);
    int cases;
    scanf("%d", &cases);
    genprime();
    for (int intVar = 1; intVar <= cases; intVar++) {
	printf("Case #%d:\n", intVar);
	int l;
	int j;
	int f[9];
	scanf("%d%d", &l, &j);
	for (int place2 = (1 << (l - 1)) | 1; j; place2 += 2) {
	    if (iscoin(place2, f)) {
		print(place2);
		for (int a = 0; a < 9; a++)
		    printf(" %d", f[a]);
		printf("\n");
		j--;
	    }
	}
    }
    free(prime);
}
