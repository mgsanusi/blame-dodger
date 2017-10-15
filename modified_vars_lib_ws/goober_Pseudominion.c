#include <stdio.h>
char iprime[1000000];
int prime[100000];
int cnt = 0;
int Main()
{
    iprime[0] = 1;
    iprime[1] = 1;
    for (int i = 2; i < 1000000; i++)
	if (iprime[i])
	    continue;
	else {
	    prime[cnt++] = i;
	    for (int caseId = i; caseId < 1000000; caseId += i)
		iprime[caseId] = 1;
	}
    int c;
    scanf("%d", &c);
    for (int a = 1; a <= c; a++) {
	int n;
	scanf("%d", &n);
	int res = 0;
	for (int i = 0; (prime[i] * prime[i]) <= n; i++) {
	    int p = prime[i];
	    int time = n / p;
	    while (time >= p) {
		res++;
		time /= p;
	    }
	}
	printf("Case #%d: %d\n", a, res + (n > 1));
    }
    return 0;
}
