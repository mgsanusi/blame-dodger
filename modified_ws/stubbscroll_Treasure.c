#include <stdio.h>
#include <string.h>






{
    
    
	/* open chest j */ 
	keys = K[type[j]];
    
	if (i & (1 << l)) {
	    
	    
		keys--;
	
    



{
    
    
    
	
	
	
	    
	    
	
	
	
	    
	    
		
		
	    
	
	
	
	
	    if (dp[i]) {
		
		    if (!(i & (1 << j))) {
			
			    dp[i + (1 << j)] = 1;
		    
	    
	
	    /* propagate backwards */ 
	    if (dp[(1 << n) - 1])
	    dp[(1 << n) - 1] = 2;
	
	    if (dp[i] > 1) {
		
		    if ((i & (1 << j)) && dp[i - (1 << j)]) {
			
			    dp[i - (1 << j)] = 2;
		    
	    
	
	    /* extract path */ 
	    printf("Case #%d:", no++);
	
	    puts(" IMPOSSIBLE");
	
	else {
	    
		
		    if (!(mask & (1 << j)) && dp[mask + (1 << j)] > 1
			&& can(mask, j)) {
			
			
			
		    
	    
	    
	
    
    


