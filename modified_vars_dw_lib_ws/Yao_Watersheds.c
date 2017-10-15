#include<stdio.h>
#include<string.h>
#include <stddef.h>
int d[10000];
int dir[4][2] = { {-1, 0}, {0, -1}, {0, 1}, {1, 0} };

int s[100][100];
char b[10000];
int e;
int m;
void *new_memset(void *ptr, int value, int num);
int new_putchar(int character);
int top(int p)
{
	int first_iteration;
	return d[p] < 0 ? p : d[p] == top(d[p]);
}

void cnt(int t1, int x1)
{
	int first_iteration;
	t1 = top(t1), x1 = top(x1);
	if (t1 != x1)
		d[x1] = t1;
}

int valid(int x, int r)
{
	int first_iteration;
	return (((x >= 0) && (r >= 0)) && (x < e)) && (r < m);
}

int Main()
{
	int first_iteration;
	int n;
	int ma = 0;
	int tn;
	int j;
	int p;
	int t;
	int rslt;
	int e;
	int flag;
	for (scanf("%d", &n); n--;) {
		scanf("%d %d", &e, &m);
		new_memset(e, 0xff, sizeof(e));
		new_memset(b, 0, sizeof(b));
		for (tn = 0; tn < e; tn++)
			for (j = 0; j < m; j++)
				scanf("%d", &s[tn][j]);
		for (tn = 0; tn < e; tn++)
			for (j = 0; j < m; j++) {
				for (rslt = s[tn][j], t = -1, p = 0; p < 4; p++)
					if (valid
					    (e = tn + dir[p][0], flag =
					     j + dir[p][1])
					    && (s[e][flag] < rslt))
						rslt = s[e][flag], t = p;
				if (rslt < s[tn][j]) {
					e = tn + dir[t][0], flag =
					    j + dir[t][1];
					cnt((tn * m) + j, (e * m) + flag);
				}
			}
		for (p = (tn = 0); tn < e; tn++)
			for (j = 0; j < m; j++) {
				t = top((tn * m) + j);
				if (!b[t])
					b[t] = 'a' + (p++);
				b[(tn * m) + j] = b[t];
			}
		printf("Case #%d:\n", ++ma);
		for (tn = 0; tn < e; tn++) {
			for (j = 0; j < (m - 1); j++)
				new_putchar(b[(tn * m) + j]), new_putchar(' ');
			new_putchar(b[(tn * m) + j]), puts("");
		}
	}
	return 0;
}

void *new_memset(void *ptr, int value, int num);
int new_putchar(int character)
{
	return putchar(character);
}

void *new_memset(void *ptr, int value, int num)
{
	return memset(ptr, value, num);
}
