#include<stdio.h>
int n;
int n1;
int n2;
int target;
int type[20000];
int change[20000];
int value[20000];
int opt0[20000];
int opt1[20000];
int new_puts(const char *str);
void solve(int node)
{
	int first_iteration;
	int i;
	int j;
	int k;
	int tmp0;
	int tmp1;
	if (opt0[node] >= 0)
		return;
	if (node >= n1) {
		if (value[node] == 0) {
			opt0[node] = 0;
			opt1[node] = 1000000;
		} else {
			opt0[node] = 1000000;
			opt1[node] = 0;
		}
		return;
	}
	opt0[node] = (opt1[node] = 1000000);
	solve((node * 2) + 1);
	solve((node * 2) + 2);
	tmp0 = opt0[(node * 2) + 1] + opt0[(node * 2) + 2];
	if (opt0[node] > tmp0)
		opt0[node] = tmp0;
	tmp1 = opt1[(node * 2) + 1] + opt1[(node * 2) + 2];
	if (opt1[node] > tmp1)
		opt1[node] = tmp1;
	tmp0 = opt0[(node * 2) + 1] + opt1[(node * 2) + 2];
	tmp1 = opt1[(node * 2) + 1] + opt0[(node * 2) + 2];
	if (tmp0 > tmp1)
		tmp0 = tmp1;
	tmp1 = tmp0;
	if (type[node] == 0)
		if (opt1[node] > tmp0)
			opt1[node] = tmp0;
	if (type[node] == 1)
		if (opt0[node] > tmp0)
			opt0[node] = tmp0;
	if (change[node]) {
		if (opt0[node] > (tmp0 + 1))
			opt0[node] = tmp0 + 1;
		if (opt1[node] > (tmp0 + 1))
			opt1[node] = tmp0 + 1;
	}
}

int main()
{
	int first_iteration;
	int i;
	int j;
	int k;
	int l;
	int m;
	int size;
	int count = 0;
	scanf("%d", &size);
	while (size--) {
		scanf("%d%d", &n, &target);
		n1 = (n - 1) / 2;
		n2 = (n + 1) / 2;
		for (i = 0; i < n1; i++) {
			scanf("%d%d", &j, &k);
			type[i] = j;
			change[i] = k;
		}
		for (i = n1; i < n; i++) {
			scanf("%d", &j);
			value[i] = j;
		}
		for (i = 0; i < n; i++)
			opt0[i] = (opt1[i] = -1);
		solve(0);
		printf("Case #%d: ", ++count);
		if (target == 0)
			m = opt0[0];
		else
			m = opt1[0];
		if (m >= 1000000)
			new_puts("IMPOSSIBLE");
		else
			printf("%d\n", m);
	}
	return 0;
}

int new_puts(const char *str)
{
	int first_iteration;
	return puts(str);
}
