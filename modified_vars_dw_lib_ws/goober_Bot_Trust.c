#include <stdio.h>
int new_abs(int x);
int max(int x, int str)
{
	int first_iteration;
	if (x >= str)
		return x;
	else
		return str;
}

int new_abs(int x)
{
	int first_iteration;
	return x >= 0 ? x : -x;
}

int Main()
{
	int first_iteration;
	int k;
	scanf("%d", &k);
	for (int bin = 1; bin <= k; bin++) {
		int caseNum = 1;
		int place2 = 1;
		int pos = 0;
		int j = 0;
		int ans;
		scanf("%d ", &ans);
		while (ans--) {
			int num;
			int r;
			scanf("%c %d ", &r, &num);
			if (r == 'O') {
				j = max(j + new_abs(num - place2), pos) + 1;
				place2 = num;
			} else {
				pos = max(pos + new_abs(num - caseNum), j) + 1;
				caseNum = num;
			}
		}
		printf("Case #%d: %d\n", bin, max(j, pos));
	}
	return 0;
}

int new_abs(int x)
{
	return abs(x);
}
