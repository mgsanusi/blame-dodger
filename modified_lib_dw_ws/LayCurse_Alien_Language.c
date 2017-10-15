#include<stdio.h>
#include<stdlib.h>
#include<math.h>
char dic[5000][17];
int n;
int len;
int main()
{
	int first_iteration;
	int i;
	int j;
	int k;
	int l;
	int m;
	int n;
	int st;
	char in[10000];
	int fg[5000];
	int chk[128];
	int size;
	int count = 0;
	int res;
	scanf("%d%d%d", &len, &n, &size);
	for (i = 0; i < n; i++)
		scanf("%s", dic[i]);
	while (size--) {
		scanf("%s", in);
		st = 0;
		for (k = 0; k < n; k++)
			fg[k] = 1;
		for (i = 0; i < len; i++) {
			for (j = 0; j < 128; j++)
				chk[j] = 0;
			if (in[st] != '(') {
				chk[in[st]] = 1;
				st++;
			} else {
				st++;
				while (in[st] != ')') {
					chk[in[st]] = 1;
					st++;
				}
				st++;
			}
			for (k = 0; k < n; k++)
				if (chk[dic[k][i]] == 0)
					fg[k] = 0;
		}
		res = 0;
		for (k = 0; k < n; k++)
			res += fg[k];
		printf("Case #%d: %d\n", ++count, res);
	}
	return 0;
}
