#include "stdio.h"
#include "assert.h"
#include "string.h"

#define MAXN (1 << 20)
int main () {
	int tn;
	scanf ("%d", &tn);
	int tt;
	int a[MAXN];
	int b[10000];
	int i;
	for (tt = 0; tt < tn; tt++) {
		int n; 
		scanf ("%d", &n);
		int z = 0;
		int s = 0;
		int x = 1000000000;
		for (i = 0; i < n; i++) {
			scanf ("%d", &b[i]);
			z = z ^ b[i];
			s += b[i];
			if (x > b[i]) {
				x = b[i];
			}
		
		}
		printf ("Case #%d: ", tt + 1);
		if (z) {
			printf ("NO\n");
		} else {
			printf ("%d\n", s - x); 
		}

	}
}
