#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int start[128];
int r;
int v[1024];
int f;
int w[1024];
int Main(void)
{
	int count;
	int sizeCount;
	int x;
	int t;
	int mutexBuf;
	int total;
	int caseno;
	int lb;
	for (scanf("%d", &count), sizeCount = 1; sizeCount <= count;
	     sizeCount++) {
		scanf("%d%d%d%d%d", &f, &r, &x, &t, &mutexBuf);
		for (caseno = 0; caseno < r; caseno++) {
			scanf("%d", &start[caseno]);
		}
		for (caseno = 0; caseno < f; caseno++) {
			v[caseno] = start[caseno % r];
			start[caseno % r] =
			    ((((long long)x) * start[caseno % r]) +
			     (((long long)t) * (caseno + 1))) % mutexBuf;
		}
		w[0] = 1;
		total = w[0];
		for (caseno = 1; caseno < f; caseno++) {
			w[caseno] = 1;
			for (lb = 0; lb < caseno; lb++) {
				if (v[lb] < v[caseno]) {
					w[caseno] =
					    (w[caseno] + w[lb]) % 1000000007;
				}
			}
			total = (total + w[caseno]) % 1000000007;
		}
		printf("Case #%d: %d\n", sizeCount, total);
	}
	return 0;
}
