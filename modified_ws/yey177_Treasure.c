#include <stdio.h>
#include <string.h>
char dp[1048576][21], tmp[21];



{
	
	
	
		
		
		
		
		
			
			
		
		
			
			
				
				
					minu[i]++;
			
		
		
			
			
				
					
						nw[o[j][x]]++;
					
				
			
			
			r = n + 1;
			
				
					
						
						     (dp[i],
						      dp[i ^ (1 << j)]) > 0) {
							
								dp[i ^
								   (1 << j)]);
							
						
					
				
			
			
				continue;
			
			
			dp[i][sl + 1] = 0;
		
		
			puts("IMPOSSIBLE");
		
		else {
			
				printf("%d%c", (int)dp[(1 << n) - 1][i],
				       i == n - 1 ? '\n' : ' ');
	
