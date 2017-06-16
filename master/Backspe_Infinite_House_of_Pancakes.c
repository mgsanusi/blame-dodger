#include <stdio.h>

int main() {
	int T, t;
	int D;
	int a, pm, s;
	int i, j, flag;
	int c[1001];
	scanf("%d", &T);
	for(t = 1; t <= T; t++) {
		scanf ("%d", &D);
		for(i = 1; i < 1000; i++) c[i] = 0;
		c[0] = 2147483647;
		pm = 0;
		for(i = 0; i < D; i++) {
			scanf ("%d", &s);
			c[s]++;
			if(s > pm) pm = s;
		}
		a = pm;
		for(i = 1; i <= pm; i++) {

		}
		for(i = 1; i <= pm; i++) {
			s = 0;
			for(j = i + 1; j <= pm; j++) {
				s += c[j] * ((j - 1) / i);
			}
			if (a > s + i) a = s + i;
		}
		/*
		a = 0;
		flag = 1;
		i = pm;
		while(flag) {
			s = c[i];
			j = i - 1;
			while(j > 0) {
				while(c[j] == 0 && j * 2 > i + 1) j--;
				if (i - j >= s) {
					for(;i > j; i--) {
						a += c[i];
						printf("%d %d개 쪼갬\n", i, c[i]);
						c[i/2] += c[i];
						c[(i+1)/2] += c[i];
						c[i] = 0;
					}
					break;
				} else if (j <= (i + 1) / 2) {
					flag = 0;
					break;
				} else {
					s += c[j];
					j--;
				}
			}
			if (j == 0) break;
		}
		a += i;
		*/
		printf("Case #%d: %d\n", t, a);
	}
	return 0;
}
