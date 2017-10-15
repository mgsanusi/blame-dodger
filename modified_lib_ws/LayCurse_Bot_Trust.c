#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
 int main()
{
	int i, j, k, l, m, n;
	int size, count = 0;
	char mode[1000];
	int in[1000];
	int now1, now2, tar, tm;
	int go1, go2, p1, p2;
	 scanf("%d", &size);
	while (size--) {
		scanf("%d", &n);
		rep(i, n) scanf("%s%d", mode + i, in + i);
		now1 = now2 = 1;
		tar = 0;
		tm = 0;
		while (tar < n) {
			tm++;
			go1 = go2 = -1;
			REP(i, tar, n) {
				if (mode[i] == 'B' && go1 == -1)
					go1 = in[i];
				if (mode[i] == 'O' && go2 == -1)
					go2 = in[i];
			}
			 p1 = p2 = 0;
			if (mode[tar] == 'B' && now1 == in[tar])
				p1 = 1;
			if (mode[tar] == 'O' && now2 == in[tar])
				p2 = 1;
			if (p1 || p2)
				tar++;
			 if (p1 == 0 && go1 > now1)
				now1++;
			if (p1 == 0 && go1 < now1)
				now1--;
			if (p2 == 0 && go2 > now2)
				now2++;
			if (p2 == 0 && go2 < now2)
				now2--;
		}
		 printf("Case #%d: %d\n", ++count, tm);
	}
	  return 0;
}


