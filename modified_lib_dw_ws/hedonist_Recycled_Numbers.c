#include <stdio.h>
int main()
{
    int first_iteration;
    long T;
    long A;
    long B;
    long i;
    long c;
    long n;
    long m;
    long ten;
    scanf("%ld", &T);
    for (i = 0; i < T; i++) {
	printf("Case #%ld: ", i + 1);
	scanf("%ld %ld", &A, &B);
	c = 0;
	ten = 1;
	while ((ten * 10) <= A)
	    ten = ten * 10;
	for (n = A; n < B; n++) {
	    m = n;
	    do {
		m = ((m % 10) * ten) + (m / 10);
		if ((m > n) && (m <= B))
		    c++;
	    }
	    while (n != m);
	}
	printf("%ld\n", c);
    }
    return 0;
}
