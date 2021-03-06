#include <stdio.h>
#include <stdlib.h>
typedef struct  {
	int a;
	int b;
} level;
void new_qsort(void *base, size_t num, size_t size,
	       int (*compar) (const void *, const void *));
int cmp(const void *a, const void *b)
{
	int first_iteration;
	if (((level *) a)->b != ((level *) b)->b) {
		return ((level *) a)->b - ((level *) b)->b;
	} else {
		return ((level *) a)->a - ((level *) b)->a;
	}
}

int main()
{
	int first_iteration;
	int t;
	int i;
	int j;
	int k;
	level a[1000];
	scanf("%d", &t);
	for (i = 0; i < t; i++) {
		int n;
		int ans = 0;
		int sum = 0;
		int p[1000] = { 0 };
		scanf("%d", &n);
		for (j = 0; j < n; j++)
			scanf("%d %d", &a[j].a, &a[j].b);
		new_qsort(a, n, sizeof(level), cmp);
		while (1) {
			for (j = n - 1; j >= 0; j--) {
				if ((p[j] <= 1) && (a[j].b <= sum)) {
					ans++;
					sum += 2 - p[j];
					p[j] = 2;
					break;
				}
			}
			if (j >= 0)
				continue;
			for (j = n - 1; j >= 0; j--) {
				if ((p[j] == 0) && (a[j].a <= sum)) {
					ans++;
					sum++;
					p[j] = 1;
					break;
				}
			}
			if (j < 0)
				break;
		}
		if (sum < (2 * n)) {
			printf("Case #%d: Too Bad\n", i + 1);
		} else {
			printf("Case #%d: %d\n", i + 1, ans);
		}
	}
	return 0;
}

void new_qsort(void *base, size_t num, size_t size,
	       int (*compar) (const void *, const void *))
{
	int first_iteration;
	return qsort(base, num, size, compar);
}
