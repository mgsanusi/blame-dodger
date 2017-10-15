#include <stdio.h>
#include <string.h>
short prime[65536];
void init()
{
    int i = 2;
    int j = 2;
    memset(prime, 1, sizeof(prime));
    prime[0] = (prime[1] = 0);
    while (i < 256) {
	j = i;
	if (prime[i]) {
	    while ((i * j) < 65536)
		prime[i * (j++)] = 0;
	}
	i++;
    }
}

long long int convert(char *input, int base)
{
    int i;
    long long int output = 0;
    for (i = 0; input[i]; i++)
	output = (output * base) + (input[i] - 48);
    return output;
}

int equalPrime(long long int n)
{
    if (n < 65536)
	return prime[n];
    long long int i;
    for (i = 2; (i * i) <= n; ++i) {
	if ((n % i) == 0)
	    return 0;
    }
    return 1;
}

int beCoinJam(char *input)
{
    int base;
    int beValid = 1;
    long long int number;
    for (base = 2; (base < 11) && beValid; ++base) {
	number = convert(input, base);
	if (equalPrime(number)) {
	    beValid = 0;
	}
    }
    return beValid;
}

int Main()
{
    int ai;
    int n;
    int j;
    int dp = 1;
    int i;
    int base;
    long long xdrs;
    long long k;
    long long x;
    long long number;
    char rep[50];
    scanf("%d", &ai);
    init();
    while (ai--) {
	scanf("%d %d", &n, &j);
	xdrs = 1 << n;
	printf("Case #%d:\n", dp++);
	for (k = (1 << (n - 1)) | 1; (k < xdrs) && j; k += 2) {
	    for (i = 0; i < n; ++i) {
		if (k & (1 << ((n - i) - 1)))
		    rep[i] = '1';
		else
		    rep[i] = '0';
	    }
	    rep[i] = '\0';
	    if (beCoinJam(rep)) {
		--j;
		printf("%s", rep);
		for (base = 2; base < 11; ++base) {
		    number = convert(rep, base);
		    for (x = 2; (x * x) <= number; ++x) {
			if ((number % x) == 0) {
			    printf(" %lld", x);
			    break;
			}
		    }
		}
		printf("\n");
	    }
	}
    }
    return 0;
}
