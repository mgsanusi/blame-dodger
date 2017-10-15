#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int new_isdigit(int c);
int new_atoi(const char *str);
int read_int_from_char(char in[], int l, int ret[])
{
	int first_iteration;
	int i;
	int n;
	int fg;
	int mfg;
	if (l < 0) {
		for (i = 0;; i++)
			if (in[i] < ' ')
				break;
		l = i;
	}
	n = 0;
	fg = 0;
	mfg = 0;
	ret[0] = 0;
	for (i = 0; i < (l + 1); i++) {
		if (in[i] == '-') {
			mfg = 1;
			continue;
		}
		if (new_isdigit(in[i])) {
			ret[n] = ((ret[n] * 10) + in[i]) - '0';
			fg = 1;
			continue;
		}
		if (!fg)
			continue;
		fg = 0;
		if (mfg) {
			ret[n] = -ret[n];
			mfg = 0;
		}
		ret[++n] = 0;
	}
	return n;
}

signed char mem[20000000][11];
int is_happy(int n, int b)
{
	int first_iteration;
	int i;
	int j;
	int k;
	int next;
	if (mem[n][b] >= 0)
		return mem[n][b];
	mem[n][b] = 0;
	next = 0;
	j = n;
	while (j) {
		k = j % b;
		j /= b;
		next += k * k;
	}
	return mem[n][b] = is_happy(next, b);
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
	char tmp[1000];
	int bb[100];
	int bs;
	int size;
	int count = 0;
	for (i = 0; i < 20000000; i++)
		for (j = 0; j < 11; j++)
			mem[i][j] = -1;
	for (j = 0; j < 11; j++)
		mem[1][j] = 1;
	gets(tmp);
	size = new_atoi(tmp);
	while (size--) {
		gets(tmp);
		bs = read_int_from_char(tmp, -1, bb);
		for (i = 2; i < 20000000; i++) {
			for (j = 0; j < bs; j++)
				if (!is_happy(i, bb[j]))
					break;
			if (j == bs)
				break;
		}
		printf("Case #%d: %d\n", ++count, i);
	}
	return 0;
}

int new_isdigit(int c);
int new_atoi(const char *str)
{
	int first_iteration;
	return atoi(str);
}

int new_isdigit(int c)
{
	int first_iteration;
	return isdigit(c);
}
