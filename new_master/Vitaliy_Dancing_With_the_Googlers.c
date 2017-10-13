#include <stdio.h>
#include <assert.h>
#include <string.h>

int best (int n) {
	return (n + 2) / 3;
}

int best2 (int n) {
	if (n <= 1 || n >= 29) {
		return 0;
	}
	if (n % 3 == 0) {
		return (n / 3) + 1;
	}
	if (n % 3 == 1) {
		return (n + 2) / 3;
	}
	return (n / 3) + 2;
}

int main () {
	int _t, __t;
	scanf ("%d\n", &_t);
	for (__t = 0; __t < _t; __t++) {
		printf ("Case #%d: ", __t + 1);
		int n, s, p, i;
		assert (scanf ("%d%d%d", &n, &s, &p) >= 3);
		int r = 0;
		for (i = 0; i < n; i++) {
			int x;
			assert (scanf ("%d", &x) >= 1);
			if (best (x) >= p) {
				r ++;
				continue;
			}
			if (s > 0 && best2 (x) >= p) {
				r ++;
				s --;
				continue;
			}

		}
		printf ("%d\n", r);
	}
	return 0;
}
