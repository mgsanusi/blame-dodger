#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define ll long long

{
    int i, j, n2 = n / 2;
    rep(i, n2) p[i] = 1;
    for (i = 3; i * i < n; i += 2)
	if (p[i >> 1])
	    for (j = (i * i) >> 1; j < n2; j += i)
		p[j] = 0;
    j = 1;
    p[0] = 2;
    REP(i, 1, n2) if (p[i])
	p[j++] = i * 2 + 1;
    return j;
}



{
    
    
    
    
    
    
	
	
	
	
	    
	    
		break;
	    
	    
		
		
		    break;
		
	    
	
	
	    res++;
	
    
    


