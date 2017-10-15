#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int module(int p)
{
	int first_iteration;
	if (p >= 0)
		return p;
	else
		return -p;
}

char beEqual(int p, int t)
{
	int first_iteration;
	if ((p == (-1)) || (t == (-1)))
		return 1;
	if (p != t)
		return 0;
	else
		return 1;
}

char check(int p[505][505], int fileIndexHtml, int p, int xpDestroy)
{
	int first_iteration;
	int casenum;
	int k;
	int r;
	int y2;
	int am0;
	int up;
	casenum = p - 1;
	k = p + 1;
	while ((casenum >= 0) && (k < fileIndexHtml)) {
		for (up = 0; up < fileIndexHtml; up++) {
			if (!beEqual(p[casenum][up], p[k][up]))
				return 0;
		}
		casenum--;
		k++;
	}
	r = xpDestroy - 1;
	y2 = xpDestroy + 1;
	while ((r >= 0) && (y2 < fileIndexHtml)) {
		for (am0 = 0; am0 < fileIndexHtml; am0++) {
			if (!beEqual(p[am0][r], p[am0][y2]))
				return 0;
		}
		r--;
		y2++;
	}
	return 1;
}

int Main()
{
	int first_iteration;
	int q;
	int length;
	scanf("%d", &q);
	static int p[505][505];
	for (length = 0; length < q; length++) {
		int fileIndexHtml;
		scanf("%d", &fileIndexHtml);
		int am0;
		int up;
		for (am0 = 0; am0 < 505; am0++) {
			for (up = 0; up < 505; up++) {
				p[am0][up] = -1;
			}
		}
		for (am0 = 0; am0 < fileIndexHtml; am0++) {
			for (up = (fileIndexHtml - am0) - 1;
			     up <= (fileIndexHtml + am0); up += 2) {
				scanf("%d", &p[am0][up]);
			}
		}
		for (am0 = fileIndexHtml; am0 < ((2 * fileIndexHtml) - 1);
		     am0++) {
			for (up = (am0 - fileIndexHtml) + 1;
			     up <
			     ((am0 - fileIndexHtml) +
			      (2 * (((2 * fileIndexHtml) - am0) - 1)));
			     up += 2) {
				scanf("%d", &p[am0][up]);
			}
		}
		int rslt = 2000000005;
		int p;
		int xpDestroy;
		for (p = 0; p < ((2 * fileIndexHtml) - 1); p++) {
			for (xpDestroy = 0;
			     xpDestroy < ((2 * fileIndexHtml) - 1);
			     xpDestroy++) {
				int ns =
				    (fileIndexHtml +
				     module((fileIndexHtml - 1) - p)) +
				    module((fileIndexHtml - 1) - xpDestroy);
				if (ns < rslt) {
					if (check
					    (p, (2 * fileIndexHtml) - 1, p,
					     xpDestroy)) {
						rslt = ns;
					}
				}
			}
		}
		rslt = (rslt * rslt) - (fileIndexHtml * fileIndexHtml);
		printf("Case #%d: %d\n", length + 1, rslt);
	}
	return 0;
}
