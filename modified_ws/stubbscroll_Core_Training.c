#include <stdio.h>





{
    



{
    
    
    
	scanf("%d", &g[i]);
    
	gm[i] = 0;
    
	gm[g[i] % p]++;
    
    gm[0] = 0;
    
	
	r += j;
	gm[1] -= j * 2;
    
	
	    /* 1+2 */ 
	    j = min(gm[1], gm[2]);
	r += j;
	gm[1] -= j;
	gm[2] -= j;
	
	    /* 1+1+1 */ 
	    j = gm[1] / 3;
	r += j;
	gm[1] -= j * 3;
	
	    /* 2+2+2 */ 
	    j = gm[2] / 3;
	r += j;
	gm[2] -= j * 3;
    
	
	    /* 1+3 */ 
	    j = min(gm[1], gm[3]);
	r += j;
	gm[1] -= j;
	gm[3] -= j;
	
	    /* 2+2 */ 
	    j = gm[2] / 2;
	r += j;
	gm[2] -= j * 2;
	
	    /* 1+1+2 */ 
	    j = min(gm[1] / 2, gm[2]);
	r += j;
	gm[1] -= j * 2;
	gm[2] -= j;
	
	    /* 3+3+2 */ 
	    j = min(gm[3] / 2, gm[2]);
	r += j;
	gm[3] -= j * 2;
	gm[2] -= j;
	
	    /* 1+1+1+1 */ 
	    j = gm[1] / 4;
	r += j;
	gm[1] -= j * 4;
	
	    /* 3+3+3+3 */ 
	    j = gm[3] / 4;
	r += j;
	gm[3] -= j * 4;
    
    
	if (gm[i]) {
	    r++;
	    break;
	}
    



{
    
    
    
	printf("Case #%d: ", caseno++), solve();
    


