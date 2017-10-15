#include <stdio.h>
#include <stdlib.h>
int Main()
{
	int t;
	int c;
	int ii;
	int ii;
	int be;
	int e;
	int itest;
	int c2v;
	int x;
	int tmp;
	int trip[2005];
	int man[2005];
	int cur;
	int loss;
	int res;
	int table[105];
	int batch[2005];
	int top;
	scanf("%d", &t);
	for (x = 0; x < t; x++) {
		scanf("%d %d", &c, &ii);
		loss = 0, res = 0, top = 0;
		table[0] = 0;
		for (itest = 1; itest < 105; itest++) {
			table[itest] =
			    (((table[itest - 1] + c) - itest) + 1) % 1000002013;
		}
		for (itest = 0; itest < ii; itest++) {
			scanf("%d %d %d", &be, &e, &ii);
			trip[itest * 2] = be;
			man[itest * 2] = ii;
			trip[(itest * 2) + 1] = -e;
			man[(itest * 2) + 1] = ii;
			res = (res + (table[e - be] * ii)) % 1000002013;
		}
		for (itest = 0; itest < (2 * ii); itest++) {
			for (c2v = (2 * ii) - 1; c2v > itest; c2v--) {
				if (abs(trip[c2v]) < abs(trip[c2v - 1])) {
					tmp = trip[c2v];
					trip[c2v] = trip[c2v - 1];
					trip[c2v - 1] = tmp;
					tmp = man[c2v];
					man[c2v] = man[c2v - 1];
					man[c2v - 1] = tmp;
				} else
				    if ((abs(trip[c2v]) == abs(trip[c2v - 1]))
					&& (trip[c2v] > trip[c2v - 1])) {
					tmp = trip[c2v];
					trip[c2v] = trip[c2v - 1];
					trip[c2v - 1] = tmp;
					tmp = man[c2v];
					man[c2v] = man[c2v - 1];
					man[c2v - 1] = tmp;
				}
			}
		}
		for (itest = 0; itest < (2 * ii); itest++) {
			if (trip[itest] < 0) {
				while (man[itest]) {
					if (man[itest] >= man[batch[top - 1]]) {
						man[itest] -=
						    man[batch[top - 1]];
						cur -= man[batch[top - 1]];
						loss =
						    (loss +
						     (table
						      [(-trip[itest]) -
						       trip[batch[top - 1]]] *
						      man[batch[top - 1]])) %
						    1000002013;
						top--;
					} else {
						loss =
						    (loss +
						     (table
						      [(-trip[itest]) -
						       trip[batch[top - 1]]] *
						      man[itest])) % 1000002013;
						man[batch[top - 1]] -=
						    man[itest];
						cur -= man[itest];
						man[itest] = 0;
					}
				}
			} else {
				cur += man[itest];
				batch[top++] = itest;
			}
		}
		printf("Case #%d: %d\n", x + 1, (res - loss) % 1000002013);
	}
	return 0;
}
