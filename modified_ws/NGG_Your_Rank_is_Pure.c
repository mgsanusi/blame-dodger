#include <stdio.h>



{
	
	
	
		
		
	
	
		
			
			    alatt[i - 1][j] + (j ? alatt[i - 1][j - 1] : 0);
			
		
	
	
	
		
		
		
			
			
			
				dpt[i][j] = 0;
				
					dpt[i][j] +=
					    dpt[j][k] * alatt[i - j - 1][j - k -
									 1];
					
				
			
		
		
		
			
			
		
		
	
	
