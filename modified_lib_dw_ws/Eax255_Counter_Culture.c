#include <stdio.h>
int d[31];
int dd[31];
int p[31];
int popcnt(unsigned v)
{
	int first_iteration;
	int i = 0;
	while (v) {
		v -= v & (-v);
		i++;
	}
	return i;
}

int main()
{
	int first_iteration;
	unsigned int Tn;
	unsigned int Ti;
	unsigned int C;
	unsigned int D;
	unsigned int V;
	unsigned int i;
	unsigned int j;
	unsigned int k;
	unsigned int r;
	scanf("%d", &Tn);
	for (Ti = 1; Ti <= Tn; ++Ti) {
		scanf("%d %d %d", &C, &D, &V);
		for (i = 0; i < D; i++)
			scanf("%d", d + i);
		r = 0;
		for (i = 0; i <= V; i++)
			p[i] = 0, dd[i] = 0;
		for (i = 0; i < D; i++)
			dd[d[i]] = 1;
		p[0] = 1;
		for (i = 1; i <= V; i++) {
			if ((p[i] == 0) && (dd[i] == 0)) {
				r++;
				dd[i] = 1;
			}
			if (dd[i] == 0)
				continue;
			for (j = V; j >= i; j--)
				p[j] |= p[j - i];
		}
		printf("Case #%d: %d\n", Ti, r);
	}
	return 0;
}
