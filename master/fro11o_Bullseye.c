#include <stdio.h>

int T, E, R, N, v[10], max, first;

void bt(int index, int e, int cur) {
	if(index == N) {
		if(first) {
			max = cur;
			first = 0;
		}
		else
			max = cur > max?cur:max;
		return;
	}
	int i;
	for(i = 0; i <= e; i++) {
		cur += i * v[index];
		bt(index + 1, e - i + R > E?E:e - i + R, cur);
		cur -= i * v[index];
	}
}

int main() {
	int i, j;
	scanf("%d", &T);
	for(i = 0; i < T; i++) {
		scanf("%d %d %d", &E, &R, &N);
		for(j = 0; j < N; j++)
			scanf("%d", &v[j]);
		first = 1;
		bt(0, E, 0);
		printf("Case #%d: %d\n", i + 1, max);
	}
	return 0;
}
