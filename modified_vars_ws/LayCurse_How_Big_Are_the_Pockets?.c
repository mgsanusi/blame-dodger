#include<stdio.h>
int smallest[600][600];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int stX[1000000];
int stY[1000000];
int stSize;
void nul(int ans, int f)
{
	int caseno;
	int t3;
	int k;
	int sol;
	int r;
	stSize = 1;
	stX[0] = ans;
	stY[0] = f;
	smallest[ans][f] = 2;
	while (stSize) {
		caseno = stX[stSize - 1];
		t3 = stY[stSize - 1];
		stSize--;
		for (k = 0; k < 4; k++) {
			sol = caseno + dx[k];
			r = t3 + dy[k];
			if ((((sol < 0) || (r < 0)) || (sol >= 600))
			    || (r >= 600))
				continue;
			if (smallest[sol][r])
				continue;
			smallest[sol][r] = 2;
			stX[stSize] = sol;
			stY[stSize] = r;
			stSize++;
		}
	}
}

int chk(int ans, int f)
{
	int caseno;
	int t3;
	caseno = (t3 = f);
	while (caseno >= 0) {
		if (smallest[ans][caseno] == 1)
			break;
		caseno--;
	}
	while (t3 < 600) {
		if (smallest[ans][t3] == 1)
			break;
		t3++;
	}
	if ((caseno >= 0) && (t3 < 600))
		return 1;
	caseno = (t3 = ans);
	while (caseno >= 0) {
		if (smallest[caseno][f] == 1)
			break;
		caseno--;
	}
	while (t3 < 600) {
		if (smallest[t3][f] == 1)
			break;
		t3++;
	}
	if ((caseno >= 0) && (t3 < 600))
		return 1;
	return 0;
}

int Main()
{
	int caseno;
	int t3;
	int k;
	int t;
	int m;
	int i1;
	int q;
	int c;
	int len;
	int rslt;
	int size;
	int cnt = 0;
	char in[10000];
	int modname;
	int ny;
	int vn;
	scanf("%d", &size);
	while (size--) {
		for (caseno = 0; caseno < 600; caseno++)
			for (t3 = 0; t3 < 600; t3++)
				smallest[caseno][t3] = 0;
		modname = (ny = 300);
		vn = 0;
		rslt = 0;
		scanf("%d", &q);
		while (q--) {
			scanf("%s%d", in, &c);
			for (caseno = 0;; caseno++)
				if (in[caseno] < ' ')
					break;
			len = caseno;
			while (c--) {
				for (caseno = 0; caseno < len; caseno++) {
					if (in[caseno] == 'R')
						vn = (vn + 1) % 4;
					if (in[caseno] == 'L')
						vn = (vn + 3) % 4;
					if (in[caseno] == 'F') {
						modname += dx[vn];
						ny += dy[vn];
						smallest[modname][ny] = 1;
						modname += dx[vn];
						ny += dy[vn];
						smallest[modname][ny] = 1;
					}
				}
			}
		}
		nul(0, 0);
		for (caseno = 1; caseno < 600; caseno += 2)
			for (t3 = 1; t3 < 600; t3 += 2)
				if (smallest[caseno][t3] == 2) {
					rslt += chk(caseno, t3);
				}
		printf("Case #%d: %d\n", ++cnt, rslt);
	}
	return 0;
}
