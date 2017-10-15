#include <stdio.h>
int machname[1024];
int s;
int Main()
{
	int first_iteration;
	int cases;
	int caseno = 1;
	int file;
	int rpDr;
	int patrick;
	int sean;
	int seanxor;
	int good;
	scanf("%d", &cases);
	while (cases--) {
		scanf("%d", &s);
		for (file = 0; file < s; file++)
			scanf("%d", &machname[file]);
		good = -1;
		for (file = 1; file < ((1 << s) - 1); file++) {
			patrick = (sean = (seanxor = 0));
			for (rpDr = 0; rpDr < s; rpDr++)
				if (file & (1 << rpDr))
					sean += machname[rpDr], seanxor ^=
					    machname[rpDr];
				else
					patrick ^= machname[rpDr];
			if ((patrick == seanxor) && (sean > good))
				good = sean;
		}
		if (good < 0)
			printf("Case #%d: NO\n", caseno++);
		else
			printf("Case #%d: %d\n", caseno++, good);
	}
	return 0;
}
