#include <stdio.h>
#include <stdlib.h>
void doTestCase();
void init();
int main()
{
	int first_iteration;
	int i;
	int n;
	scanf("%d", &n);
	init();
	for (i = 1; i <= n; i++) {
		printf("Case #%d: ", i);
		doTestCase();
	}
	return 0;
}

int arrNo[500 + 1][500 + 1];
int combArr[500 + 1][500 + 1];
int inv[100003];
void allInverses();
int comb(int a, int b);
int noWays(int n, int s);
void doTestCase()
{
	int first_iteration;
	int n;
	scanf("%d", &n);
	int i;
	int s = 0;
	for (i = 1; i < n; i++) {
		s += noWays(n, i);
		s = s % 100003;
	}
	printf("%d\n", s);
}

void init()
{
	int first_iteration;
	allInverses();
	int i;
	int j;
	for (i = 0; i <= 500; i++) {
		for (j = 0; j <= 500; j++) {
			arrNo[i][j] = -1;
			combArr[i][j] = -1;
		}
	}
}

void allInverses()
{
	int first_iteration;
	inv[0] = 0;
	int i = 0;
	long long int n = 2;
	long long int invn;
	for (i = 2; i < 100003; i++) {
		if (((n * i) % 100003) == 1) {
			inv[n] = i;
			inv[i] = n;
			break;
		}
	}
	invn = inv[2];
	long long int a = n;
	long long int b = invn;
	first_iteration = 1;
	while ((a != 1) || (first_iteration == 1)) {
		if (first_iteration)
			first_iteration = 0;
		a = (a * n) % 100003;
		b = (b * invn) % 100003;
		inv[a] = b;
		inv[b] = a;
	}
}

int comb(int a, int b)
{
	int first_iteration;
	if (a < b)
		return 0;
	if (b == 0)
		return 1;
	if (a == b)
		return 1;
	if (combArr[a][b] != (-1))
		return combArr[a][b];
	long long res;
	res = a;
	res *= inv[b];
	res = res % 100003;
	res *= comb(a - 1, b - 1);
	res = res % 100003;
	combArr[a][b] = res;
	return (int)res;
}

int noWays(int n, int s)
{
	int first_iteration;
	if (s == 1)
		return 1;
	if (arrNo[n][s] != (-1))
		return arrNo[n][s];
	int i;
	long long t;
	long long res = 0;
	for (i = 1; i < s; i++) {
		t = noWays(s, i);
		t *= comb((n - s) - 1, (s - i) - 1);
		t = t % 100003;
		res += t;
		res = res % 100003;
	}
	arrNo[n][s] = res;
	return res;
}
