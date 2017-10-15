#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
char cache[11][100001];
void initData()
{
	int b;
	memset(cache, -1, sizeof(cache));
	for (b = 2; b <= 10; b++) {
		cache[b][1] = 1;
	}
}

int nextNumber(int base, int n10)
{
	int digit[33];
	int n;
	int n;
	int a;
	n = (n = 0);
	while (n10 > 0) {
		digit[n++] = n10 % base;
		n10 /= base;
	}
	a = 0;
	for (n = 0; n < n; n++) {
		a += digit[n] * digit[n];
	}
	return a;
}

int checkNumber(int base, int n10, int depth)
{
	if (depth > (11111 * base)) {
		return 0;
	}
	if (n10 <= 100000) {
		if (cache[base][n10] != (-1)) {
			return cache[base][n10];
		} else {
			return cache[base][n10] =
			    checkNumber(base, nextNumber(base, n10), depth + 1);
		}
	} else {
		while (n10 > 100000) {
			n10 = nextNumber(base, n10);
		}
		return checkNumber(base, n10, depth + 10);
	}
}

void singleCase()
{
	int bases[10];
	int n;
	int n;
	int answer;
	int flag;
	char a;
	n = 0;
	answer = 2;
	do {
		scanf("%d%c", &bases[n++], &a);
	}
	while (a == ' ');
	while (answer <= 100000) {
		flag = 1;
		for (n = 0; n < n; (n++) && flag) {
			flag = flag && checkNumber(bases[n], answer, 0);
		}
		if (flag) {
			break;
		}
		answer++;
	}
	printf("%d\n", answer);
}

void preCache()
{
	int n;
	int j;
	for (n = 2; n <= 10; n++) {
		for (j = 0; j <= 10000; j++) {
			checkNumber(n, j, 0);
		}
	}
}

int Main()
{
	int cases;
	int n;
	initData();
	scanf("%d\n", &cases);
	for (n = 1; n <= cases; n++) {
		printf("Case #%d: ", n);
		singleCase();
	}
	return 0;
}
