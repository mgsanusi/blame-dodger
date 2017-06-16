#include <stdio.h>

#define MAX_N 1000005
#define SWAP(a, b) a=a+b; b=a-b; a=a-b;

int T, x, s, r, t, n;
int b[MAX_N], e[MAX_N], w[MAX_N];

int main()
{
	int T_count;
	scanf("%d", &T_count);
	for (T = 1; T <= T_count; T++)
	{
		scanf("%d %d %d %d %d", &x, &s, &r, &t, &n);
		
		int i, j;
		for (i = 0; i < n; i++)
			scanf("%d %d %d", &b[i], &e[i], &w[i]);
		
		int len = x;
		for (i = 0; i < n; i++)
			len -= e[i] - b[i];
		
		b[n] = 0;
		e[n] = len;
		w[n] = 0;
		n++;
		
		for (i = 0; i < n; i++)
			for (j = i + 1; j < n; j++)
				//if ((e[i] - b[i]) * 1.0 / (w[i] + r) - (e[i] - b[i]) * 1.0 / (w[i] + s)
				//	>
				//	(e[j] - b[j]) * 1.0 / (w[j] + r) - (e[j] - b[j]) * 1.0 / (w[j] + s))
				if (w[i] > w[j])
				{
					SWAP(b[i], b[j]);
					SWAP(e[i], e[j]);
					SWAP(w[i], w[j]);
				}
		
		double ans = 0;
		double tx = t;
		
		for (i = 0; i < n; i++)
			if ((r + w[i]) * tx >= e[i] - b[i])
			{
				ans += (e[i] - b[i]) * 1.0 / (r + w[i]);
				tx -= (e[i] - b[i]) * 1.0 / (r + w[i]);
			}
			else
			{
				ans += tx + (e[i] - b[i] - (w[i] + r) * tx) / (s + w[i]);
				tx = 0;		
			}
		
		printf("Case #%d: %.10f\n", T, ans);
	}
	return 0;	
}