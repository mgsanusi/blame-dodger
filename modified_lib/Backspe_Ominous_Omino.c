#include <stdio.h>

int main() {
	int T, t;
	int x, r, c;
	int a;
	scanf("%d", &T);
	for(t = 1; t <= T; t++) {
		a = 0;
		scanf ("%d %d %d", &x, &r, &c);
		if (x == 1) {
			a = 1;
		}
		else if (x == 2) {
			a = (r * c % 2 == 0);
		}
		else if (x == 3) {
			a = (r * c % 3 == 0) && (r != 1) && (c != 1);
		}
		else if (x == 4) {
			a = (r * c % 4 == 0) && (r > 2) && (c > 2);
		}
		printf("Case #%d: %s\n", t, a?"GABRIEL":"RICHARD");
	}
	return 0;
}
