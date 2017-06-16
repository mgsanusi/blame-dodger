#include <stdio.h>
#include <stdlib.h>

int digit_ror(int n)
{
	int i, t, z;
	
	z = 0;
	while(n%10 == 0) {
		z++;
		n /= 10;
	}
	t = n%10;
	n /= 10;
	
	for(i=1; i<=n; i*=10);
	for(;z;z--) i*=10;
	
	return t*i+n;
}

int main()
{
	int test, testc;
	int m, n, i, j, ans;
	
	freopen("gcj1_3.in", "r", stdin);
	freopen("gcj1_3.out", "w", stdout);
	
	scanf("%d\n", &testc);
	for(test=1; test<=testc; test++) {
		scanf("%d%d", &m, &n);
		ans = 0;
		for(i=m; i<=n; i++) {
			for(j=digit_ror(i); j!=i; j=digit_ror(j)) {
				if(j <= i || j > n || j < m) continue;
				ans++;
			}
		}
		printf("Case #%d: %d\n", test, ans);
	}
	
	return 0;
}
