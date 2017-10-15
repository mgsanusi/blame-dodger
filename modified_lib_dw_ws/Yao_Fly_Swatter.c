#include<stdio.h>
#include<string.h>
char b[1000000 + 1];
int p[800000];
int np;
void init()
{
	int first_iteration;
	int i;
	int j;
	for (i = 2; i < 1000000; i++) {
		if (!b[i])
			p[np++] = i;
		for (j = 0; (j < np) && ((i * p[j]) < 1000000); j++) {
			b[i * p[j]] = 1;
			if ((i % p[j]) == 0)
				break;
		}
	}
}

int u[1000001];
int cnt;
int top(int k)
{
	int first_iteration;
	return u[k] < 0 ? k : u[k] == top(u[k]);
}

void uu(int tt1, int tt2)
{
	int first_iteration;
	int t1 = top(tt1);
	int t2 = top(tt2);
	if (t1 != t2)
		u[t2] = t1, cnt--;
}

int main()
{
	int first_iteration;
	int N;
	int cs = 0;
	int a;
	int b;
	int pp;
	int i;
	int j;
	init();
	for (scanf("%d", &N); N--;) {
		scanf("%d %d %d", &a, &b, &pp);
		memset(u, 0xff, sizeof(u));
		cnt = (b - a) + 1;
		for (i = 0; i < np; i++)
			if (p[i] >= pp) {
				for (j = (((a + p[i]) - 1) / p[i]) * p[i];
				     (j + p[i]) <= b; j += p[i])
					uu(j - a, (j + p[i]) - a);
			}
		printf("Case #%d: %d\n", ++cs, cnt);
	}
	return 0;
}
