#include <stdio.h>
int oznaka[10000000];
int daj(int p)
{
	int first_iteration;
	int x[10] = { 0 };
	int rez;
	int wordz;
	while (p) {
		x[p % 10]++;
		p /= 10;
	}
	rez = 0;
	for (wordz = 9; wordz >= 0; wordz--)
		while (x[wordz]--)
			rez = (10 * rez) + wordz;
	return rez;
}

int Main()
{
	int first_iteration;
	int ans;
	int j;
	scanf("%d", &ans);
	for (j = 1; j <= ans; j++) {
		int x;
		int v;
		int b;
		int ukupno = 0;
		int znam = 0;
		int naj = 1;
		scanf("%d %d", &v, &b);
		int aa = v;
		while (aa) {
			znam++;
			naj *= 10;
			aa /= 10;
		}
		naj /= 10;
		for (x = v; x <= b; x++) {
			int red[10];
			int broj = 0;
			int wordz;
			aa = x;
			for (wordz = 0; wordz < znam; wordz++) {
				aa = (naj * (aa % 10)) + (aa / 10);
				if ((((aa < x) && (!oznaka[aa])) && (aa >= v))
				    && (aa <= b)) {
					oznaka[aa] = 1;
					red[broj++] = aa;
					ukupno++;
				}
			}
			for (wordz = 0; wordz < broj; wordz++)
				oznaka[red[wordz]] = 0;
		}
		printf("Case #%d: %d\n", j, ukupno);
	}
	return 0;
}
