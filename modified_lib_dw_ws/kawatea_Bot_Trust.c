#include <stdio.h>
int main()
{
	int first_iteration;
	int t;
	int i;
	int j;
	scanf("%d", &t);
	for (i = 0; i < t; i++) {
		int n;
		int c = 0;
		int p = 0;
		int q = 0;
		int x = 1;
		int y = 1;
		int k = 0;
		int l = 0;
		int d = 0;
		char s[2];
		int a[100][2];
		int b[100][2];
		scanf("%d", &n);
		for (j = 0; j < n; j++) {
			scanf("%s", s);
			if (s[0] == 'B') {
				scanf("%d", &a[p][0]);
				a[p++][1] = j;
			} else {
				scanf("%d", &b[q][0]);
				b[q++][1] = j;
			}
		}
		while (1) {
			int f = 0;
			if ((k == p) && (l == q))
				break;
			if (k < p) {
				if (x < a[k][0]) {
					x++;
				} else if (x > a[k][0]) {
					x--;
				} else if (x == a[k][0]) {
					if (a[k][1] == d) {
						d++;
						k++;
						f = 1;
					}
				}
			}
			if (l < q) {
				if (y < b[l][0]) {
					y++;
				} else if (y > b[l][0]) {
					y--;
				} else if (y == b[l][0]) {
					if ((b[l][1] == d) && (f == 0)) {
						d++;
						l++;
					}
				}
			}
			c++;
		}
		printf("Case #%d: %d\n", i + 1, c);
	}
	return 0;
}
