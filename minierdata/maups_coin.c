#include <stdio.h>

int N, coin[64];
long long int values[11], evidence[11];

int isprime(long long int n, int b) {
	long long int i;
	if(n != 2 && n%2 == 0) {
		evidence[b] = 2;
		return 0;
	}
	for(i=3; i*i <= n; i+=2)
		if(n%i == 0) {
			evidence[b] = i;
			return 0;
		}
	return 1;
}

int getvalues() {
	int i, j, r=0;
	long long int b;
	for(i=2; i <= 10; i++) {
		values[i] = 0;
		for(j=0, b=1; j < N; j++, b*=i)
			values[i] += coin[j]*b;
		if(isprime(values[i],i))
			r++;
//		printf("%u(%d", values[i], isprime(values[i],i));
//		printf(",%u) ", evidence[i]);
	}
//	printf("\n");
	return r;
}

int main() {
	int t, i, k, l, J;
	long long int j;

	scanf("%d", &t);
	for(i=1; i <= t; i++) {
		scanf("%d%d", &N, &J);
		printf("Case #%d:\n", i);
		for(j=(1<<(N-1))+1; J; j+=2) {
			k=j; l=0;
			while(k > 0) {
				coin[l] = k%2;
		//		printf("%d", coin[l]);
				k /= 2;
				l++;
			}
		//	printf(" ");
			if(getvalues() == 0) {
				printf("%lld ", values[10]);
				for(k=2; k < 10; k++)
					printf("%lld ", evidence[k]);
				printf("%lld\n", evidence[10]);
				J--;
			}
		}
	}
}
