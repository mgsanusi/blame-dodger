#include <stdio.h>
char visited[6103][6103];





{
	
	
	
	
	
		
			
				
				
			
		
		
		
		
		
		
			
			
				
					
					
						
						
						
					
						
					
						
					
				
			
		
		
			
			
				
				     || (visited[j + 1][k] & 8)) {
					
				
			
			
				
				     || (visited[j + 1][k] & 8)) {
					
					
					    //printf("A: %d %d %d %d\n",j,k,visited[j][k],visited[j+1][k]);
					    if (cnt % 2 == 1 && cnt != 1) {
						
						    //printf("A %d %d %d\n",j,gap,cnt);
						    tot += gap + 1;
					
					
				
					
				
				
					
			
		
		
		    //printf("%d\n",visited[3003][3002]);
		    for (j = 1; j < 6102; j++) {
			
			
				
				     || (visited[k][j + 1] & 4)) {
					
					    //printf("%d %d\n",k,j);
					    cnt++;
					
						
						    //printf("B %d %d %d\n",j,gap,cnt);
						    tot += gap;
					
					
				
				
					
			
		
		
		
	


