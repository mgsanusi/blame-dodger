#include <string.h>
#include <stdio.h>
#include <assert.h>

int main () {
	int a[100];
	int b[100];
	int pt[2];
	int pp[2];
	int ct = 0;
	int tn = 0;
	scanf ("%d\n", &tn);
	int tt;
	for (tt = 0; tt < tn; tt++) {
		printf ("Case #%d: ", tt + 1);
		int m;
		scanf ("%d", &m);
		ct = 0;
		pt[0] = 0;
		pt[1] = 0;
		pp[0] = 1;
		pp[1] = 1;
		int i;
		for (i = 0; i < m; i++) {
			char s[1000];
			scanf ("%s", s);
			int x;
			scanf ("%d", &x);
			assert (s[0] == 'O' || s[0] == 'B');
			int cc;
			if (s[0] == 'O') {
				cc = 0;
			} else {
				cc = 1;
			}
			int time = pt[cc] + abs (pp[cc] - x) + 1;
			if (time > ct) {
				ct = time;
			}  else {
				time = ++ct;
			}
			pt[cc] = time;
			pp[cc] = x;
		}
		printf ("%d\n", ct);
	}
	return 0;
}
