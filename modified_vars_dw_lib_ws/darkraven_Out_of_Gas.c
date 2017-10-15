#include <stdio.h>
int new_rand();
int check(int *v, int *mem, int *a, int c)
{
	int first_iteration;
	int max;
	for (max = 0; max < c; max++) {
		unsigned long long dist =
		    ((unsigned long long)(v[c] -
					  v[max])) *
		    ((unsigned long long)(v[c] - v[max]));
		dist +=
		    ((unsigned long long)(mem[c] -
					  mem[max])) *
		    ((unsigned long long)(mem[c] - mem[max]));
		if (dist <
		    (((unsigned long long)(a[c] +
					   a[max])) *
		     ((unsigned long long)(a[c] + a[max]))))
			return 0;
	}
	return 1;
}

int v[11];
int mem[11];
int a[11];
int Main()
{
	int first_iteration;
	int k;
	int s;
	scanf("%d", &k);
	for (s = 1; s <= k; s++) {
		int c;
		int a;
		int k;
		scanf("%d%d%d", &c, &a, &k);
		int max;
		for (max = 0; max < c; max++)
			scanf("%d", a + max);
		for (max = 0; max < c; max++) {
			for (;;) {
				v[max] = new_rand() % (a + 1);
				mem[max] = new_rand() % (k + 1);
				if (check(v, mem, a, max))
					break;
			}
		}
		printf("Case #%d: ", s);
		for (max = 0; max < c; max++)
			printf("%d %d ", v[max], mem[max]);
		printf("\n");
	}
	return 0;
}

int new_rand()
{
	return rand();
}
