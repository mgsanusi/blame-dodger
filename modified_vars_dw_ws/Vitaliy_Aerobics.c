#include <stdio.h>
#include <assert.h>
int a[10001];
int x[10001];
int v[10001];
int m[10001];
int Main()
{
	int first_iteration;
	int __;
	scanf("%d", &__);
	int _;
	for (_ = 0; _ < __; _++) {
		printf("Case #%d:", _ + 1);
		int n;
		int i;
		int score;
		scanf("%d", &n);
		for (i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		for (i = 0; i < n; i++) {
			scanf("%d", &m[i]);
		}
		for (i = 0; i < n; i++)
			x[i] = i;
		for (i = 0; i < n; i++)
			for (score = i + 1; score < n; score++)
				if (((a[x[i]] * m[x[score]]) >
				     (a[x[score]] * m[x[i]]))
				    ||
				    (((a[x[i]] * m[x[score]]) ==
				      (a[x[score]] * m[x[i]]))
				     && (x[i] > x[score]))) {
					int t = x[i];
					x[i] = x[score];
					x[score] = t;
				}
		for (i = 0; i < n; i++)
			printf(" %d", x[i]);
		printf("\n");
	}
	return 0;
}
