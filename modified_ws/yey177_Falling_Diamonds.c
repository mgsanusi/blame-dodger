#include <stdio.h>
#include <string.h>
#define MAX(u,v) (((u)>(v))?(u):(v))
#define MIN(u,v) (((u)<(v))?(u):(v))
double dp[1000][2000];

{
    
    
    
    
	
	
	    x = -x;
	
	i = 0;
	
	    
	    i++;
	
	
	
	    r = 1.0;
	    goto END;
	}
	
	    r = 0.0;
	    goto END;
	}
	
	    r = 0.0;
	    goto END;
	}
	
	    /*if(y<=n-q*2-1){r=1.0;goto END;}
	       if(y>n){r=0.0;goto END;} */ 
	    //for(i=0;i<1000;i++)for(j=0;j<2000;j++)dp[i][j]=0.0;
	    memset(dp, 0, sizeof(dp));
	
	
	    
		
		    dp[i + 1][j + 1] += dp[i][j];
		
		else if (j == q * 2)
		    dp[i + 1][j] += dp[i][j];
		
		else {
		    
		    
		
	    
	
	
	
	    
	
      
    
    


