#include<stdio.h>
int t;
int dp;
int r;
int b;
int m;
int n;
int start;
int stop;
long long tmp;
long long result;
long long num_first;
long long r;
long long w;
long long profit[10008];
long long total_profit[10008];
long long e_a[10008];
long long e_u[10008];
void bar(int s);
int Main()
{
    scanf("%d", &dp);
    for (t = 1; t <= dp; t++) {
	scanf("%lld", &w);
	scanf("%lld", &r);
	scanf("%lld", &num_first);
	result = 0;
	for (r = 0; r < num_first; r++)
	    scanf("%lld", &profit[r]);
	for (r = 0; r < num_first; r++) {
	    e_a[r] = w;
	    e_u[r] = 0;
	    total_profit[r] = 0;
	}
	e_u[num_first] = 0;
	bar(0);
	printf("Case #%d: %lld\n", t, result);
    }
    return 0;
}

void bar(int s)
{
    int j;
    if (s == num_first) {
	if (total_profit[s] > result)
	    result = total_profit[s];
	return;
    }
    for (j = 0; j <= e_a[s]; j++) {
	total_profit[s + 1] = total_profit[s] + (profit[s] * j);
	e_u[s] = j;
	e_a[s + 1] = (e_a[s] + r) - j;
	if (e_a[s + 1] > w)
	    e_a[s + 1] = w;
	bar(s + 1);
    }
}
