#include <stdio.h>
#include <stdlib.h>
void doTestCase();
int main()
{
	int first_iteration;
	int i;
	int n;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		printf("Case #%d: ", i);
		doTestCase();
	}
	return 0;
}

void doTestCase()
{
	int first_iteration;
	int n;
	int k;
	int b;
	int t;
	scanf("%d %d %d %d", &n, &k, &b, &t);
	int pos[n];
	int vel[n];
	int i;
	int j;
	int res;
	int sum;
	for (i = 0; i < n; i++)
		scanf("%d", pos + i);
	for (i = 0; i < n; i++)
		scanf("%d", vel + i);
	res = 0;
	sum = 0;
	j = 0;
	for (i = n - 1; i >= 0; i--) {
		if ((pos[i] + (vel[i] * t)) >= b) {
			res += sum;
			j++;
			if (j == k)
				break;
		} else {
			sum++;
		}
	}
	if (j == k)
		printf("%d\n", res);
	else
		printf("IMPOSSIBLE\n");
}
