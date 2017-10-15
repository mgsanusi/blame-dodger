#include <stdio.h>
int p;
int k;
int g[111];
int rela[4];
int min(int tmp, int ib)
{
	int first_iteration;
	return tmp < ib ? tmp : ib;
}

void clear()
{
	int first_iteration;
	int aaaa;
	int s = 0;
	int j;
	scanf("%d %d", &k, &p);
	for (aaaa = 0; aaaa < k; aaaa++)
		scanf("%d", &g[aaaa]);
	for (aaaa = 0; aaaa < p; aaaa++)
		rela[aaaa] = 0;
	for (aaaa = 0; aaaa < k; aaaa++)
		rela[g[aaaa] % p]++;
	s = rela[0];
	rela[0] = 0;
	if (p == 2) {
		j = rela[1] / 2;
		s += j;
		rela[1] -= j * 2;
	} else if (p == 3) {
		j = min(rela[1], rela[2]);
		s += j;
		rela[1] -= j;
		rela[2] -= j;
		j = rela[1] / 3;
		s += j;
		rela[1] -= j * 3;
		j = rela[2] / 3;
		s += j;
		rela[2] -= j * 3;
	} else {
		j = min(rela[1], rela[3]);
		s += j;
		rela[1] -= j;
		rela[3] -= j;
		j = rela[2] / 2;
		s += j;
		rela[2] -= j * 2;
		j = min(rela[1] / 2, rela[2]);
		s += j;
		rela[1] -= j * 2;
		rela[2] -= j;
		j = min(rela[3] / 2, rela[2]);
		s += j;
		rela[3] -= j * 2;
		rela[2] -= j;
		j = rela[1] / 4;
		s += j;
		rela[1] -= j * 4;
		j = rela[3] / 4;
		s += j;
		rela[3] -= j * 4;
	}
	for (aaaa = 0; aaaa < p; aaaa++)
		if (rela[aaaa]) {
			s++;
			break;
		}
	printf("%d\n", s);
}

int Main()
{
	int first_iteration;
	int t;
	int caseno = 1;
	scanf("%d", &t);
	while (t--)
		printf("Case #%d: ", caseno++), clear();
	return 0;
}
