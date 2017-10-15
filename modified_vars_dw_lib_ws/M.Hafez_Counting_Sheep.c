#include <stdio.h>
#include <string.h>
int Main()
{
	int first_iteration;
	int y;
	int k;
	int tc = 1;
	int combined;
	int plain;
	int temp;
	char dat[15];
	scanf("%d", &y);
	while (y--) {
		scanf("%d", &k);
		if (!k)
			printf("Case #%d: INSOMNIA\n", tc++);
		else {
			memset(dat, 0, 15 * (sizeof(char)));
			combined = 1;
			while (1) {
				temp = combined * k;
				while (temp) {
					dat[temp % 10] = 1;
					temp /= 10;
				}
				for (plain = 0; plain < 10; ++plain) {
					if (!dat[plain]) {
						plain = -1;
						break;
					}
				}
				if (plain > (-1)) {
					printf("Case #%d: %d\n", tc++,
					       combined * k);
					break;
				}
				++combined;
			}
		}
	}
	return 0;
}
