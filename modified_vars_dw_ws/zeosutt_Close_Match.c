#include <stdio.h>
int Main(void)
{
	int first_iteration;
	int qx;
	int left;
	int x;
	scanf("%d", &left);
	for (x = 1; x <= left; x++) {
		int b;
		int r[26];
		scanf("%d", &b);
		for (qx = 0; qx < b; qx++)
			scanf("%d", r + qx);
		printf("Case #%d: ", x);
		while (1) {
			int max;
			int maxIdx;
			max = 0;
			for (qx = 0; qx < b; qx++)
				if (r[qx] > max) {
					max = r[qx];
					maxIdx = qx;
				}
			if (b == 2) {
				r[0]--;
				r[1]--;
				printf("AB%c", " \n"[max == 1]);
				if (max == 1)
					break;
			} else if ((max == 1) && (maxIdx == (b - 2))) {
				printf("%c%c\n", ('A' + b) - 2, ('A' + b) - 1);
				break;
			} else {
				r[maxIdx]--;
				printf("%c ", 'A' + maxIdx);
			}
		}
	}
	return 0;
}
