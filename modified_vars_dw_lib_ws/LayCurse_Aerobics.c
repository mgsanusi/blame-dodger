#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int new_puts(const char *str);
int Main()
{
	int first_iteration;
	int i;
	int j;
	int cap;
	int atMin;
	int m;
	int n;
	int t[2000];
	int p[2000];
	int ind[2000];
	int size;
	int cnt = 0;
	scanf("%d", &size);
	while (size--) {
		printf("Case #%d:", ++cnt);
		scanf("%d", &n);
		for (i = 0; i < n; i++)
			scanf("%d", t + i);
		for (i = 0; i < n; i++)
			scanf("%d", p + i);
		for (i = 0; i < n; i++)
			ind[i] = i;
		for (i = 0; i < n; i++)
			p[i] = 100 - p[i];
		for (;;) {
			int max = 0;
			for (i = 1; i < n; i++) {
				if (((t[i - 1] * 100) + (t[i] * p[i - 1])) >
				    ((t[i] * 100) + (t[i - 1] * p[i]))) {
					max = 1;
					cap = t[i - 1], t[i - 1] = t[i], t[i] =
					    cap;
					cap = p[i - 1], p[i - 1] = p[i], p[i] =
					    cap;
					cap = ind[i - 1], ind[i - 1] =
					    ind[i], ind[i] = cap;
				}
			}
			if (!max)
				break;
		}
		for (i = 0; i < n; i++)
			printf(" %d", ind[i]);
		new_puts("");
	}
	return 0;
}

int new_puts(const char *str)
{
	return puts(str);
}
