#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define ll long long
#define INF 100000000000000000LL




{
	
	
	
	
		
		
					   w[x - 1 - i] + j, t[x - 1 - i] + j);
		
			
			
				t[i][j] += s[i][j] + w[i][j];
		
		
		dp[0][0][0] = 0;
		
			
			
				
				now = dp[i][j][k];
				
					dp[i - 1][j][2] = now + 2, fg++;
				
					dp[i][j - 1][1] = now + 2, fg++;
				
				
					add = 1;
				else
					add = s[i][j] + w[i][j] - g + 1;
				
					dp[i][j][2] = now + add, fg++;
				
					add = 1;
				else
					add = s[i][j] - g + 1;
				
					dp[i][j][1] = now + add, fg++;
				
				now = dp[i][j][k];
				
					dp[i - 1][j][3] = now + 2, fg++;
				
					dp[i][j + 1][0] = now + 2, fg++;
				
				
					add = 1;
				else
					add = s[i][j] + w[i][j] - g + 1;
				
					dp[i][j][3] = now + add, fg++;
				
					add = 1;
				else
					add = s[i][j] - g + 1;
				
					dp[i][j][0] = now + add, fg++;
				
				now = dp[i][j][k];
				
					dp[i + 1][j][0] = now + 2, fg++;
				
					dp[i][j - 1][3] = now + 2, fg++;
				
				
					add = 1;
				else
					add = s[i][j] + w[i][j] - g + 1;
				
					dp[i][j][0] = now + add, fg++;
				
					add = 1;
				else
					add = s[i][j] - g + 1;
				
					dp[i][j][3] = now + add, fg++;
				
				now = dp[i][j][k];
				
					dp[i + 1][j][1] = now + 2, fg++;
				
					dp[i][j + 1][2] = now + 2, fg++;
				
				
					add = 1;
				else
					add = s[i][j] + w[i][j] - g + 1;
				
					dp[i][j][1] = now + add, fg++;
				
					add = 1;
				else
					add = s[i][j] - g + 1;
				
					dp[i][j][2] = now + add, fg++;
			
			
				break;
		
		
	
	


