#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define HELL (1000000007)
#define MIN(p,q) (((p)<(q))?(p):(q))
int a[1008];





{
    

{
    
    
	
	
    
    



{
    
	
	
    



{
    
    
    
    
	
	
	    scanf("%d", &a[i]);
	
	
	
	
	    
		
		    
		    break;
		
	    
	
	
	    //for(i=0;i<n;i++)printf("%d ",a[i]);
	    for (i = 1; i <= n; i++)
	    add(i, 1);
	
	    
		
		    
		    
		
	    
	    
	    
	    
		//printf("(%d,%d,%d)",mini,tmp1,tmp2);
		dp[i][0] = dp[i - 1][0] + tmp1;
	    
	    
		
		    MIN(dp[i - 1][j] + tmp1, dp[i - 1][j - 1] + tmp2);
	    
	    
	
	
	
	    
		tmp1 = dp[n][i];
	
	
    
    


