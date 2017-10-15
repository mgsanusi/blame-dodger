#include<stdio.h>
char mp[100][100];
int x;
int y;
int opt[20][2000];
int sol(int d, int k)
{
	int first_iteration;
	int i;
	int j;
	int m;
	int res = 0;
	int tmp;
	int nk;
	int oku[20];
	if (d == x)
		return 0;
	if (opt[d][k] >= 0)
		return opt[d][k];
	for (m = 0; m < (1 << y); m++) {
		for (i = 0; i < y; i++)
			if (m & (1 << i))
				oku[i] = 1;
			else
				oku[i] = 0;
		for (i = 0; i < y; i++)
			if (oku[i] && (mp[d][i] == 'x'))
				break;
		if (i != y)
			continue;
		for (i = 0; i < y; i++)
			if (oku[i] && (k & (1 << i)))
				break;
		if (i != y)
			continue;
		for (i = 1; i < y; i++)
			if (oku[i - 1] && oku[i])
				break;
		if (i != y)
			continue;
		nk = 0;
		for (i = 0; i < y; i++) {
			tmp = 0;
			if (i && oku[i - 1])
				tmp = 1;
			if ((i < (y - 1)) && oku[i + 1])
				tmp = 1;
			if (tmp)
				nk ^= 1 << i;
		}
		tmp = sol(d + 1, nk);
		for (i = 0; i < y; i++)
			tmp += oku[i];
		if (res < tmp)
			res = tmp;
	}
	return opt[d][k] = res;
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
	int size;
	int count = 0;
	int res;
	scanf("%d", &size);
	while (size--) {
		scanf("%d%d", &x, &y);
		for (i = 0; i < x; i++)
			scanf("%s", mp[i]);
		for (i = 0; i < 20; i++)
			for (j = 0; j < 2000; j++)
				opt[i][j] = -1;
		res = sol(0, 0);
		printf("Case #%d: %d\n", ++count, res);
	}
	return 0;
}
