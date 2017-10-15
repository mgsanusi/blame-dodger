#include <stdio.h>
typedef long long ll;
int Main()
{
    int first_iteration;
    int dy;
    int t;
    char s[1024];
    char a[2048];
    int i;
    int j;
    int l;
    int fo;
    scanf("%d", &t);
    for (dy = 1; dy <= t; dy++) {
	scanf("%s", s);
	printf("Case #%d: ", dy);
	l = 1024;
	fo = 1025;
	for (i = 0; i < 2018; i++)
	    a[i] = '\0';
	a[1024] = s[0];
	for (i = 1; s[i] != '\0'; i++) {
	    if (s[i] > a[l]) {
		a[--l] = s[i];
	    } else if (s[i] < a[l]) {
		a[fo++] = s[i];
	    } else {
		for (j = l; a[j] != '\0'; j++) {
		    if (a[j] > a[j + 1]) {
			a[--l] = s[i];
			break;
		    } else if (a[j] < a[j + 1]) {
			a[fo++] = s[i];
			break;
		    }
		}
	    }
	}
	printf("%s", a + l);
	printf("\n");
    }
}
