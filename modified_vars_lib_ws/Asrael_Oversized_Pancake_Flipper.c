#include<stdio.h>
#include<string.h>
int Main()
{
	int total;
	int len;
	int flipper;
	int max;
	int count;
	int cs;
	char pan[1004];
	scanf("%d", &total);
	for (int length1 = 1; length1 <= total; length1++) {
		scanf("%s", pan);
		len = strlen(pan);
		scanf("%d", &flipper);
		max = (len - flipper) + 1;
		count = 0;
		for (cs = 0; cs < max; cs++) {
			if (pan[cs] == '-') {
				for (int k = 0; k < flipper; k++) {
					if (pan[cs + k] == '-')
						pan[cs + k] = '+';
					else
						pan[cs + k] = '-';
				}
				count++;
			}
		}
		for (cs = max; cs < len; cs++)
			if (pan[cs] == '-')
				break;
		if (cs == len)
			printf("Case #%d: %d\n", length1, count);
		else
			printf("Case #%d: IMPOSSIBLE\n", length1);
	}
	return 0;
}
