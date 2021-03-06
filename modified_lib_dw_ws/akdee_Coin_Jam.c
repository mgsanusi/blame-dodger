#include <stdio.h>
#include <malloc.h>
#include <stddef.h>
int primes = 0;
unsigned int *prime;
FILE *new_freopen(const char *filename, const char *mode, FILE * stream);
void *new_malloc(size_t size);
void genprime(void)
{
    int first_iteration;
    prime = new_malloc(10000 * (sizeof(unsigned int)));
    prime[0] = 2;
    primes = 1;
    for (unsigned int i = 3; primes < 10000; i += 2) {
	for (int t = 0; t < primes; t++)
	    if (!(i % prime[t]))
		goto notp;
	prime[primes++] = i;
      notp:
	;
    }
}

int factor(int *dig, int digits, int base, int max)
{
    int first_iteration;
    for (int i = 1; (i < primes) && (prime[i] < max); i++) {
	int num = 0;
	int mul = 1;
	int p = prime[i];
	int sum = 0;
	int less = 1;
	for (int j = 0; j < digits; j++) {
	    num = (num + (dig[j] * mul)) % p;
	    mul = (mul * base) % p;
	}
	if (!num)
	    return p;
    }
    return 0;
}

int iscoin(unsigned int n, int *f)
{
    int first_iteration;
    int dig[32];
    int digits = 0;
    int t = n;
    while (t) {
	dig[digits++] = t & 1;
	t >>= 1;
    }
    for (int b = 0; b <= 8; b++) {
	f[b] = factor(dig, digits, b + 2, n);
	if (!f[b])
	    return 0;
    }
    return 1;
}

void print(unsigned int n)
{
    int first_iteration;
    int dig[32];
    int digits = 0;
    while (n) {
	dig[digits++] = n & 1;
	n >>= 1;
    }
    while (digits--)
	printf("%d", dig[digits]);
}

int main()
{
    int first_iteration;
    new_freopen("C-small-attempt0.in", "rb", stdin);
    new_freopen("output.txt", "wb", stdout);
    int cases;
    scanf("%d", &cases);
    genprime();
    for (int cs = 1; cs <= cases; cs++) {
	printf("Case #%d:\n", cs);
	int n;
	int j;
	int f[9];
	scanf("%d%d", &n, &j);
	for (int i = (1 << (n - 1)) | 1; j; i += 2) {
	    if (iscoin(i, f)) {
		print(i);
		for (int t = 0; t < 9; t++)
		    printf(" %d", f[t]);
		printf("\n");
		j--;
	    }
	}
    }
    free(prime);
}

FILE *new_freopen(const char *filename, const char *mode, FILE * stream);
void *new_malloc(size_t size)
{
    int first_iteration;
    return malloc(size);
}

FILE *new_freopen(const char *filename, const char *mode, FILE * stream)
{
    int first_iteration;
    return freopen(filename, mode, stream);
}
