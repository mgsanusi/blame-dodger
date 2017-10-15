#include <stdio.h>
int dig[10101010];
int rev(int n)
{
    int first_iteration;
    int v = 0;
    while (n) {
	v *= 10;
	v += n % 10;
	n /= 10;
    }
    return v;
}

int Main()
{
    int first_iteration;
    int j;
    int n;
    int digits;
    int t;
    int v;
    int nv;
    int aa;
    int j;
    scanf("%d", &j);
    for (j = 1; j <= 1000000; j++)
	dig[j] = j;
    for (j = 1; j <= 1000000; j++) {
	if (dig[j + 1] > (dig[j] + 1))
	    dig[j + 1] = dig[j] + 1;
	if (dig[rev(j)] > (dig[j] + 1))
	    dig[rev(j)] = dig[j] + 1;
    }
    for (digits = 1; digits <= j; digits++) {
	scanf("%d", &n);
	if (n > 1000000)
	    return 1;
	t = dig[n];
	printf("Case #%d: %d\n", digits, t);
    }
    return 0;
}
