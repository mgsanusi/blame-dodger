#include <stdio.h>
#include <assert.h>
#include <string.h>

char *s = "yhesocvxduiglbkrztnwjpfmaq";
int main () {
	int n, i, j;
	char t[1000];
	scanf ("%d\n", &n);
	assert (strlen (s) == 26);
	for (i = 0; i < n; i++) {
		gets (t);
		printf ("Case #%d: ", i + 1);
		int l = strlen (t);
		for (j = 0; j < l; j++) {
			if (t[j] == ' ') {
				printf (" ");
				continue;
			}
			if (t[j] >= 'a' && t[j] <= 'z') {
				printf ("%c", s[t[j] - 'a']);
				continue;
			}
			assert (t[j] == '\n' || t[j] == '\r');
		}
		printf ("\n");
	}
	return 0;
}
