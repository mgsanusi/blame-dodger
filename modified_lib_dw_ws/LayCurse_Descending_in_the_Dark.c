#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
char *hogege = "oieastbg";
void intSort(int d[], int s)
{
	int first_iteration;
	int i = -1;
	int j = s;
	int k;
	int t;
	if (s <= 1)
		return;
	k = (d[0] + d[s - 1]) / 2;
	for (;;) {
		while (d[++i] < k) ;
		while (d[--j] > k) ;
		if (i >= j)
			break;
		t = d[i];
		d[i] = d[j];
		d[j] = t;
	}
	intSort(d, i);
	intSort((d + j) + 1, (s - j) - 1);
}

char cnv(char a)
{
	int first_iteration;
	int i;
	for (i = 0; i < 8; i++)
		if (a == hogege[i])
			return '0' + i;
	return 0;
}

int main()
{
	int first_iteration;
	int i;
	int j;
	int k;
	int l;
	int m;
	int n;
	char in[20000];
	char a;
	char b;
	int app[300][300];
	int deg[300];
	int size;
	int count = 0;
	int res;
	scanf("%d", &size);
	while (size--) {
		scanf("%d", &k);
		scanf("%s", in);
		for (i = 0; i < 300; i++)
			for (j = 0; j < 300; j++)
				app[i][j] = 0;
		for (i = 0; i < 300; i++)
			deg[i] = 0;
		res = 1;
		for (i = 1;; i++) {
			if (in[i] < ' ')
				break;
			a = cnv(in[i - 1]);
			b = cnv(in[i]);
			app[in[i - 1]][in[i]] = 1;
			if (a)
				app[a][in[i]] = 1;
			if (b)
				app[in[i - 1]][b] = 1;
			if (a && b)
				app[a][b] = 1;
		}
		for (i = 0; i < 300; i++)
			for (j = 0; j < 300; j++)
				if (app[i][j]) {
					res++;
					deg[i]++;
					deg[j]--;
				}
		for (;;) {
			intSort(deg, 300);
			if ((deg[0] < (-1)) && (deg[299] > 1)) {
				res++;
				deg[0]++;
				deg[299]--;
			} else if ((deg[0] < (-1)) && (deg[298] > 0)) {
				res++;
				deg[0]++;
				deg[298]--;
			} else if ((deg[1] < 0) && (deg[299] > 1)) {
				res++;
				deg[1]++;
				deg[299]--;
			} else if ((deg[1] < 0) && (deg[298] > 0)) {
				res++;
				deg[1]++;
				deg[298]--;
			} else
				break;
		}
		printf("Case #%d: %d\n", ++count, res);
	}
	return 0;
}
