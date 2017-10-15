#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <stddef.h>
void *new_memset(void *ptr, int value, size_t num);
void *new_memcpy(void *destination, const void *source, size_t num);
int Min(int a, int b)
{
	int first_iteration;
	if (a < b)
		return a;
	else
		return b;
}

int main()
{
	int first_iteration;
	int T;
	int iT;
	scanf("%d", &T);
	static int a[10005];
	static int b[10005];
	static int A[10005];
	for (iT = 0; iT < T; iT++) {
		int N;
		scanf("%d", &N);
		new_memset(A, 0, sizeof(A));
		int i;
		int j;
		for (i = 0; i < N; i++) {
			scanf("%d", &j);
			A[j]++;
		}
		int l;
		int r;
		int c;
		l = 0;
		r = N;
		char flag;
		while (r > l) {
			c = ((l + r) + 1) / 2;
			flag = 1;
			new_memcpy(a, A, sizeof(A));
			new_memset(b, 0, sizeof(b));
			for (i = 1; i <= 10000; i++) {
				b[i + 1] += Min(b[i], a[i]);
				a[i] -= Min(b[i], a[i]);
				if (a[i] > 0) {
					int now = a[i];
					for (j = i; j < (i + c); j++) {
						if (a[j] < now) {
							flag = 0;
							break;
						}
						a[j] -= now;
					}
					b[i + c] += now;
				}
				if (!flag)
					break;
			}
			if (flag)
				l = c;
			else
				r = c - 1;
		}
		printf("Case #%d: %d\n", iT + 1, l);
	}
	return 0;
}

void *new_memset(void *ptr, int value, size_t num);
void *new_memcpy(void *destination, const void *source, size_t num)
{
	int first_iteration;
	return memcpy(destination, source, num);
}

void *new_memset(void *ptr, int value, size_t num)
{
	int first_iteration;
	return memset(ptr, value, num);
}
