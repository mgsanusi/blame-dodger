#include <stdio.h>
#include <string.h>

#define MAXN 12
#define MAXE 10
int v[MAXN];


{
    
    
    
	
	
	    scanf("%d", &v[i]);
	
	
	
	    for (j = 0; j <= E; j++)
		if (dp[i][j] > -1) {
		    
			
			
			    z = E;
			
			    dp[i + 1][z] = dp[i][j] + k * v[i];
		    
		
	
	
	    if (ans < dp[N][i])
		ans = dp[N][i];
	
    
    


