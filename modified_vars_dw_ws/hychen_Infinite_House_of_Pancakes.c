#include<stdio.h>
int pla0[1001];
int pla[1001];
int Main(int argc, char *argv[])
{
	int first_iteration;
	int i;
	int i;
	int temp;
	int a;
	int k;
	int c2v;
	scanf("%d", &i);
	for (i = 1; i <= i; i++) {
		int res = 1000000000;
		scanf("%d", &temp);
		if (temp == 0) {
			res = 0;
			goto answer;
		}
		for (a = 0; a < 1001; a++)
			pla0[a] = 0;
		for (a = 0; a < temp; a++) {
			scanf("%d", &k);
			pla0[k]++;
		}
		for (c2v = 1; c2v <= 1000; c2v++) {
			k = 0;
			for (a = c2v + 1; a <= 1000; a++) {
				k += pla0[a] * ((a / c2v) - ((a % c2v) == 0));
			}
			if (res > (k + c2v))
				res = k + c2v;
		}
 answer:
		printf("Case #%d: %d\n", i, res);
	}
	return 0;
}
