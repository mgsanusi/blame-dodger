#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF 1000000000

int less(int cn, int jn, int minabs, int mincn, int minjn) {
	if (abs(cn - jn) == minabs)
		if (cn == mincn)
			return jn < minjn;
		else
			return cn < mincn;
	else
		return abs(cn - jn) < minabs;
}

int main(void) {
	int i0, i1, i2, j0, j1, j2, cs;
	int t;

	scanf("%d ", &t);
	for (cs = 1; cs <= t; cs++) {
		int len, minabs, mincn, minjn;
		char c[4], j[4];
		char minc[4], minj[4];

		scanf("%s%n %s ", c, &len, j);

		minabs = mincn = minjn = INF;
		if (len == 1)
			for (i0 = '0'; i0 <= '9'; i0++)
				for (j0 = '0'; j0 <= '9'; j0++) {
					const char ct[4] = {c[0] == '?' ? i0 : c[0]};
					const char jt[4] = {j[0] == '?' ? j0 : j[0]};
					const int cn = atoi(ct), jn = atoi(jt);
					if (less(cn, jn, minabs, mincn, minjn)) {
						minabs = abs(cn - jn);
						mincn = cn;
						minjn = jn;
						strcpy(minc, ct);
						strcpy(minj, jt);
					}
				}
		else if (len == 2)
			for (i0 = '0'; i0 <= '9'; i0++)
				for (i1 = '0'; i1 <= '9'; i1++)
					for (j0 = '0'; j0 <= '9'; j0++)
						for (j1 = '0'; j1 <= '9'; j1++) {
							const char ct[4] = {c[0] == '?' ? i0 : c[0], c[1] == '?' ? i1 : c[1]};
							const char jt[4] = {j[0] == '?' ? j0 : j[0], j[1] == '?' ? j1 : j[1]};
							const int cn = atoi(ct), jn = atoi(jt);
							if (less(cn, jn, minabs, mincn, minjn)) {
								minabs = abs(cn - jn);
								mincn = cn;
								minjn = jn;
								strcpy(minc, ct);
								strcpy(minj, jt);
							}
						}
		else
			for (i0 = '0'; i0 <= '9'; i0++)
				for (i1 = '0'; i1 <= '9'; i1++)
					for (i2 = '0'; i2 <= '9'; i2++)
						for (j0 = '0'; j0 <= '9'; j0++)
							for (j1 = '0'; j1 <= '9'; j1++)
								for (j2 = '0'; j2 <= '9'; j2++) {
									const char ct[4] = {c[0] == '?' ? i0 : c[0], c[1] == '?' ? i1 : c[1], c[2] == '?' ? i2 : c[2]};
									const char jt[4] = {j[0] == '?' ? j0 : j[0], j[1] == '?' ? j1 : j[1], j[2] == '?' ? j2 : j[2]};
									const int cn = atoi(ct), jn = atoi(jt);
									if (less(cn, jn, minabs, mincn, minjn)) {
										minabs = abs(cn - jn);
										mincn = cn;
										minjn = jn;
										strcpy(minc, ct);
										strcpy(minj, jt);
									}
								}

		printf("Case #%d: %s %s\n", cs, minc, minj);
	}

	return 0;
}
