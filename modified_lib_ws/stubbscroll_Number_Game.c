#include <stdio.h>
#include <string.h>

#define ABS(a) ((a)<0?-(a):(a))
#define MIN(a,b) ((a)<(b)?(a):(b))




{
	
	
	
		dp[0][i] = ABS(a[0] - i);
	
		
			
			    /* assume last number was j */ 
			    v = dp[i - 1][j];
			
			    /* delete number at position i, making j the last seen number */ 
			    dp[i][j] = MIN(dp[i][j], v + D);
			
				
				    /* change number from a[i] to k AND insert enough */ 
				    dist = ABS(j - k);
				
					need = (dist - 1) / M;
				
				else {
					
					    /* change only */ 
					    if (ABS(j - k) <= M)
						dp[i][k] =
						    MIN(dp[i][k],
							v + ABS(a[i] - k));
					
				
				
					need = 0;
				
				    MIN(dp[i][k], v + need * I + ABS(a[i] - k));
			
		
	
	
	
		ans = MIN(ans, dp[N - 1][i]);
	



{
	
	
	
		
		
			scanf("%d", &a[i]);
		
	
	


