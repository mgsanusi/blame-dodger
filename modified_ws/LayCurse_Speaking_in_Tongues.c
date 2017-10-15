#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
 int main()
{
	int i, j, k, l;
	int N, S, p, t, res;
	int size, count = 0;
	 scanf("%d", &size);
	while (size--) {
		printf("Case #%d: ", ++count);
		scanf("%d%d%d", &N, &S, &p);
		res = 0;
		while (N--) {
			scanf("%d", &t);
			if ((t + 2) / 3 >= p) {
				res++;
				continue;
			}
			if ((t + 4) / 3 >= p && 2 <= t && t <= 28 && S) {
				S--;
				res++;
				continue;
			}
		}
		printf("%d\n", res);
	}
	 return 0;
}


