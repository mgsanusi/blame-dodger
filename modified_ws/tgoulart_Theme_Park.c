#include <stdio.h>
#include <string.h>
 int main()
{
	int t, caso = 1, r, k, n;
	int first, i, j;
	long long g[1005], done[1005];
	long long aux, total, steps, ans = 0;
	 scanf("%d", &t);
	 while (t--) {
		scanf("%d %d %d", &r, &k, &n);
		for (i = 0; i < n; i++) {
			scanf("%I64d\n", &g[i]);
		}
		 memset(done, -1, sizeof(done));
		 first = total = 0;
		 for (i = 0; i < r && done[first] == -1; i++) {
			aux = 0;
			for (j = 0; j < n && aux + g[(first + j) % n] <= k;
			      j++) {
				aux += g[(first + j) % n];
			}
			total += aux;
			first = (first + j) % n;
		}
		 steps = i;
		 if (i < r) {
			ans = (r / steps) * total;
			for (i = r / steps * steps; i < r; i++) {
				aux = 0;
				for (j = 0;
				      j < n && aux + g[(first + j) % n] <= k;
				      j++) {
					aux += g[(first + j) % n];
				}
				first = (first + j) % n;
				ans += aux;
			}
		}
		
		else {
			ans = total;
		}
		 printf("Case #%d: %I64d\n", caso++, ans);
	}
	 return 0;
}


