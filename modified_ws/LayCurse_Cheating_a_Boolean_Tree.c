#include<stdio.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define INF 1000000






{
	
	
	
		return;
	
		
			opt0[node] = 0;
			opt1[node] = INF;
		}
		
		else {
			opt0[node] = INF;
			opt1[node] = 0;
		}
		
	
	
	
	solve(node * 2 + 2);
	
	
		opt0[node] = tmp0;
	
	
		opt1[node] = tmp1;
	
	
	
		tmp0 = tmp1;
	tmp1 = tmp0;
	
		if (opt1[node] > tmp0)
			opt1[node] = tmp0;
	
		if (opt0[node] > tmp0)
			opt0[node] = tmp0;
	
		
			opt0[node] = tmp0 + 1;
		
			opt1[node] = tmp0 + 1;
	



{
	
	
	
	
		
		
		n2 = (n + 1) / 2;
		
			
			
			change[i] = k;
		
		
			
			
		
		
		
		
		
			m = opt0[0];
		else
			m = opt1[0];
		
			puts("IMPOSSIBLE");
		
		else
			printf("%d\n", m);
	
	


