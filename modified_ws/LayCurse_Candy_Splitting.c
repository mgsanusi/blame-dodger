#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
 void intSort(int d[], int s)
{
	int i = -1, j = s, k, t;
	if (s <= 1)
		return;
	k = (d[0] + d[s - 1]) / 2;
	for (;;) {
		while (d[++i] < k) ;
		while (d[--j] > k) ;
		if (i >= j)
			break;
		t = d[i];
		d[i] = d[j];
		d[j] = t;
	}
	intSort(d, i);
	intSort(d + j + 1, s - j - 1);
}

 int main()
{
	int i, j, k, l, m, n;
	int in[1200], sum, x;
	int size, count = 0;
	 scanf("%d", &size);
	while (size--) {
		scanf("%d", &n);
		rep(i, n) scanf("%d", in + i);
		x = sum = 0;
		rep(i, n) x ^= in[i], sum += in[i];
		 printf("Case #%d: ", ++count);
		if (x) {
			puts("NO");
			continue;
		}
		intSort(in, n);
		sum -= in[0];
		printf("%d\n", sum);
	}
	  return 0;
}


