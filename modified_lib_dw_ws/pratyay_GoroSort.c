#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stddef.h>
void *new_memset(void *ptr, int value, size_t num);
int alo(int);
int fact[11];
int c[11][11];
int ALO[11];
int main()
{
	int first_iteration;
	int total;
	int i;
	int n;
	int j;
	int k;
	int i1;
	int i2;
	int temp;
	long double sum;
	int a[1001];
	new_memset(ALO, 0, sizeof(ALO));
	fact[0] = 1;
	for (i = 1; i <= 10; i++)
		fact[i] = fact[i - 1] * i;
	new_memset(c, 0, sizeof(c));
	c[0][0] = 1;
	for (i = 0; i <= 10; i++) {
		for (j = 0; j <= 10; j++) {
			c[i + 1][j + 1] += c[i][j];
			c[i + 1][j] += c[i][j];
		}
	}
	scanf("%d", &total);
	for (i = 1; i <= total; i++) {
		scanf("%d", &n);
		for (j = 1; j <= n; j++)
			scanf("%d", &a[j]);
		sum = 0.0;
		for (j = 1; j <= n; j++)
			if (a[j] != j)
				sum = sum + 1;
		printf("Case #%d: %Lf\n", i, sum);
	}
}

int alo(int n)
{
	int first_iteration;
	if (ALO[n] != 0)
		return ALO[n];
	int sum = 0;
	int i;
	int term;
	for (i = 1; i <= n; i++) {
		term = c[n][i] * fact[n - i];
		term = i % 2 ? term : 0 - term;
		sum += term;
	}
	ALO[n] = sum;
	return sum;
}

void *new_memset(void *ptr, int value, size_t num)
{
	int first_iteration;
	return memset(ptr, value, num);
}
