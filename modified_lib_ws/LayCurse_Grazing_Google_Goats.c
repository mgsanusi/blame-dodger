#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define N 200
int now[N][N], next[N][N];

{
	
	
	
	
	
		
		
		
			
			
		
		
		res = 0;
		
			
			n = 0;
			
			
				
				     && (now[i - 1][j] || now[i][j - 1]))
					next[i][j] = 1, n++;
				
				     && (now[i - 1][j] && now[i][j - 1]))
					next[i][j] = 1, n++;
			
			
		
		
	
	


