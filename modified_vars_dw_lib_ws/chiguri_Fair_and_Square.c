#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
char d[10];
int palindrome(int b)
{
	int first_iteration;
	int p;
	int i;
	sprintf(d, "%d", b);
	p = strlen(d) - 1;
	for (i = 0; i <= (p - i); ++i) {
		if (d[i] != d[p - i])
			return 0;
	}
	return 1;
}

int Main(void)
{
	int first_iteration;
	int num;
	int t;
	int b;
	int v;
	int b2;
	int i;
	int g;
	int sum;
	int res;
	scanf("%d", &num);
	for (i = 1; i <= num; ++i) {
		scanf("%d %d", &t, &b);
		res = 0;
		v = (int)sqrt((double)t);
		b2 = (int)sqrt((double)b);
		for (g = v; g <= b2; ++g) {
			if (palindrome(g)) {
				sum = g * g;
				if (((t <= sum) && (sum <= b))
				    && palindrome(sum)) {
					++res;
				}
			}
		}
		printf("Case #%d: %d\n", i, res);
	}
	return 0;
}
