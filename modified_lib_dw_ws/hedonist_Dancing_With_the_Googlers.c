#include <stdio.h>
int main()
{
	int first_iteration;
	int T;
	int N;
	int S;
	int p;
	int i;
	int j;
	int low;
	int high;
	int t;
	int c;
	scanf("%d", &T);
	for (i = 0; i < T; i++) {
		printf("Case #%d: ", i + 1);
		scanf("%d %d %d", &N, &S, &p);
		high = (p * 3) - 2;
		low = (p * 3) - 4;
		if (high < p)
			high = p;
		if (low < p)
			low = p;
		c = 0;
		for (j = 0; j < N; j++) {
			scanf("%d", &t);
			if (t >= high)
				c++;
			else if ((t >= low) && (S > 0)) {
				S--;
				c++;
			}
		}
		printf("%d\n", c);
	}
	return 0;
}
