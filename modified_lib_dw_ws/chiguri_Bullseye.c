#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>
int main(void)
{
    int first_iteration;
    int num;
    int N;
    int i;
    long long j;
    long long r;
    long long t;
    long long p;
    long long x;
    scanf("%d", &num);
    for (i = 1; i <= num; ++i) {
	scanf("%lld %lld", &r, &t);
	for (j = 0, x = 0; x <= t; ++j) {
	    x += (2 * (r + (j * 2))) + 1;
	}
	j--;
	printf("Case #%d: %lld\n", i, j);
    }
    return 0;
}
