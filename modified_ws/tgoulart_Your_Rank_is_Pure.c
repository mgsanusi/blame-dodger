#include <stdio.h>
#include <string.h>

#define min(a,b) (((a) < (b)) ? (a) : (b) )
#define max(a,b) (((a) > (b)) ? (a) : (b) )
int table[11][1005][1005];
 int calc(int from, int to, int c)
{
	int i, best = 1000;
	 if (from * c >= to) {
		return table[c][from][to] = 0;
	}
	 for (i = from + 1; i < to; i++) {
		if (table[c][from][i] < 0)
			calc(from, i, c);
		if (table[c][i][to] < 0)
			calc(i, to, c);
		if (max(table[c][from][i], table[c][i][to]) + 1 < best) {
			best = max(table[c][from][i], table[c][i][to]) + 1;
		}
	}
	 return table[c][from][to] = best;
}

 int main()
{
	int t, caso = 1;
	int l, p, c;
	 memset(table, -1, sizeof(table));
	 scanf("%d", &t);
	while (t--) {
		scanf("%d %d %d", &l, &p, &c);
		if (table[c][l][p] < 0) {
			calc(l, p, c);
		}
		printf("Case #%d: %d\n", caso++, table[c][l][p]);
	}
	 return 0;
}


