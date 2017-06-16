#include "stdio.h"
#include "assert.h"
#include "string.h"

int main () {
	int tn;
	scanf ("%d", &tn);
	int tt;
	char s[200];
	int a[26][26];
	int b[26][26];
	char st[200];
	int i, j;
	for (tt = 0; tt < tn; tt++) {
		for (i = 0; i < 26; i++)
			for (j = 0; j < 26; j++) {
				a[i][j] = -1;
				b[i][j] = 0;
			}
		int n;
		scanf ("%d", &n);
		for (i = 0; i < n; i++) {
			scanf ("%s", s);
			assert (strlen (s) == 3);
			a[s[0] - 'A'][s[1] - 'A'] = s[2] - 'A';
			a[s[1] - 'A'][s[0] - 'A'] = s[2] - 'A';
		}
		scanf ("%d", &n);
		for (i = 0; i < n; i++) {
			scanf ("%s", s);
			assert (strlen (s) == 2);
			b[s[0] - 'A'][s[1] - 'A'] = 1;
			b[s[1] - 'A'][s[0] - 'A'] = 1;
		}
		scanf ("%d", &n);
		scanf ("%s", s);
		assert (strlen (s) == n);
		int ss = 0;
		for (i = 0; i < n; i++) {
			st[ss++] = s[i] - 'A';
			if (ss >= 2) {
				if (a[st[ss - 1]][st[ss - 2]] >= 0) {
					st[ss - 2] = a[st[ss - 1]][st[ss - 2]];
					ss--;
				} else {
					for (j = 0; j < ss - 1; j++) 
						if (b[st[j]][st[ss - 1]]) {
							ss = 0;
							break;
						}
				}
			}
		} 
		printf ("Case #%d: [", tt + 1);
		for (i = 0; i < ss; i++) {
			printf ("%c", st[i] + 'A');
			if (i < ss - 1) {
				printf (", ");
			}
		}
		printf ("]\n");
	}
}
