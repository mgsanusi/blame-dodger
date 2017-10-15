#include <stdio.h>

typedef long long ll;

int main() {
	int t, T;
	char s[1024];
	char a[2048];
	int i, j;
	int l, r;
	scanf("%d", &T);
	for(t = 1; t <= T; t++) {
		scanf("%s", s);
		printf("Case #%d: ", t);
		l = 1024; r = 1025;
		for(i = 0; i < 2018; i++) a[i] = '\0';
		a[1024] = s[0]; 
		for(i = 1; s[i] != '\0'; i++) {
			if(s[i] > a[l]) {
				a[--l] = s[i];
			} else if(s[i] < a[l]) {
				a[r++] = s[i];
			} else {
				for(j = l; a[j] != '\0'; j++) {
					if(a[j] > a[j+1]) {
						a[--l] = s[i];
						break;
					} else if(a[j] < a[j+1]) {
						a[r++] = s[i];
						break;
					}
				}
			}
		}
		printf("%s", a+l);
		printf("\n");
	}
}
