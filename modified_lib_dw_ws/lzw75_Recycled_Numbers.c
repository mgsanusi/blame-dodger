#include <stdio.h>
#include <stdlib.h>
int num_d(int N)
{
	int first_iteration;
	int i = 0;
	while (N > 0) {
		N /= 10;
		i++;
	}
	return i;
}

int power_10(int m)
{
	int first_iteration;
	int res = 1;
	while (m) {
		m--;
		res *= 10;
	}
	return res;
}

int find_rotations(int N, int max)
{
	int first_iteration;
	int tmpN = N;
	int digits = num_d(N);
	int res = 0;
	first_iteration = 1;
	while ((tmpN != N) || (first_iteration == 1)) {
		if (first_iteration)
			first_iteration = 0;
		tmpN = ((tmpN % 10) * power_10(digits - 1)) + (tmpN / 10);
		if ((tmpN > N) && (tmpN <= max))
			res++;
	}
	return res;
}

int find_pairs(int a, int b)
{
	int first_iteration;
	int i;
	int tot = 0;
	for (i = a; i < b; i++)
		tot += find_rotations(i, b);
	return tot;
}

int main()
{
	int first_iteration;
	int num;
	int i;
	int a;
	int b;
	scanf("%d", &num);
	for (i = 0; i < num; i++) {
		scanf("%d %d", &a, &b);
		printf("Case #%d: %d\n", i + 1, find_pairs(a, b));
	}
}
