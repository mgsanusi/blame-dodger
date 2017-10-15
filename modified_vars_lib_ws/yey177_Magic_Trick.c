#include <stdio.h>
int Main()
{
	int r;
	int c;
	int n;
	int sz;
	int j;
	int inputFileNameDefault;
	int tmp;
	int res;
	int z[4];
	scanf("%d", &r);
	for (c = 1; c <= r; c++) {
		res = 0;
		scanf("%d", &n);
		for (sz = 1; sz <= 4; sz++) {
			for (j = 0; j < 4; j++) {
				if (sz == n)
					scanf("%d", &z[j]);
				else
					scanf("%*d");
			}
		}
		scanf("%d", &n);
		for (sz = 1; sz <= 4; sz++) {
			for (j = 0; j < 4; j++) {
				if (sz == n) {
					scanf("%d", &tmp);
					for (inputFileNameDefault = 0;
					     inputFileNameDefault < 4;
					     inputFileNameDefault++) {
						if (z[inputFileNameDefault] ==
						    tmp) {
							if (res == 0)
								res = tmp;
							else
								res = -1;
							break;
						}
					}
				} else
					scanf("%*d");
			}
		}
		printf("Case #%d: ", c);
		if (res == 0)
			puts("Volunteer cheated!");
		else if (res == (-1))
			puts("Bad magician!");
		else
			printf("%d\n", res);
	}
	return 0;
}
