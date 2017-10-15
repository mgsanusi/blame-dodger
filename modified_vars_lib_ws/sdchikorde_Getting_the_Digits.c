#include <stdio.h>
#include <string.h>
#include <malloc.h>
void resetalpha()
{
}

void Main()
{
	int ans = 0;
	int cur;
	int alpha[26];
	int number;
	int cases;
	scanf("%d", &cases);
	while (ans < cases) {
		ans++;
		printf("Case #%d: ", ans);
		for (cur = 0; cur < 26; cur++)
			alpha[cur] = 0;
		scanf("%d", &number);
		int sum = 0;
		int min1 = 0;
		int min2 = 0;
		int min1index = -1;
		int min2index = -1;
		for (cur = 0; cur < number; cur++) {
			scanf("%d", &alpha[cur]);
			sum += alpha[cur];
		}
		while (sum > 0) {
			min1 = 0;
			min2 = 0;
			min1index = -1;
			min2index = -1;
			for (cur = 0; cur < number; cur++) {
				if (alpha[cur] >= min1) {
					min2 = min1;
					min2index = min1index;
					min1 = alpha[cur];
					min1index = cur;
				} else if (alpha[cur] >= min2) {
					min2 = alpha[cur];
					min2index = cur;
				}
			}
			if (min2 != 0) {
				if (((sum == 3) && (min1 == min2))
				    && (min1 == 1)) {
					printf("%c ", 'A' + min1index);
					alpha[min1index] = alpha[min1index] - 1;
					sum -= 1;
				} else {
					printf("%c%c ", 'A' + min1index,
					       'A' + min2index);
					alpha[min1index] = alpha[min1index] - 1;
					alpha[min2index] = alpha[min2index] - 1;
					sum -= 2;
				}
			} else {
				printf("%c ", 'A' + min1index);
				alpha[min1index] = alpha[min1index] - 1;
				sum -= 1;
			}
		}
		printf("\n");
	}
}
