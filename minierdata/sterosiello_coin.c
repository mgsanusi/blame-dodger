#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

uint64_t isprime(uint64_t n)
{
	uint64_t i = 0;

	if(!(n % 2))
		return 2;

	if(!(n % 3))
		return 3;

	for(i = 5; i*i <= n; i+=6)
	{
		if(!(n % i))
			return i;

		if(!(n % (i+2)))
			return i+2;
	}

	return 0;
}

uint64_t tobase(uint64_t value, uint8_t base)
{
	uint64_t r = 0;
	uint64_t pow = 1;
	while(value)
	{
		r += (value & 1) * pow;
		value >>= 1;
		pow *= base;
	}
	return r;
}

char *int2bin(uint64_t value) {
	static char buf[65];
	int i = 0;
	for(i = 0; i < 64; i++)
		buf[i] = '\0';
    char* buffer = buf+63;

    for (i = 63; i >= 0; i--) {
        *buffer-- = (value & 1) + '0';
        value >>= 1;
    }

    return strchr(buffer+1, '1');
}


int main(int argc, char* argv[])
{
	int T = 1, iT = 1;
	FILE* fi = fopen(argv[1], "r");
	FILE* fo = fopen("output.txt", "w");
	int n = 16;
	int j = 50, ij = 1;

	fscanf(fi, "%d%d%d", &T, &n, &j);

	while(iT <= T)
	{
		fprintf(fo, "Case #%d:\n", iT);

		uint64_t cur = 0;
		int i;
		while(ij <= j)
		{
			uint64_t value = 1 + (1ull << (n-1)) + (cur << 1);
			uint64_t divisors[11];
			uint8_t is_coin = 1;

			for (i = 2; i < 11; i++)
			{
				uint64_t r = tobase(value, i);
				uint64_t divisor = isprime(r);
				if(divisor)
				{
					divisors[i] = divisor;
				}
				else
				{
					is_coin = 0;
					break;
				}
			}

			if(is_coin)
			{
				fprintf(fo, "%s", int2bin(value));
				for(i = 2; i < 11; i++)
					fprintf(fo, " %llu", divisors[i]);
				fprintf(fo, "\n");
				printf("%d\n", ij);
				ij++;
			}
			cur++;
		}
		iT++;
	}

	return 0;
}
