#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)


{
    int i = -1, j = s, k, t;
    if (s <= 1)
	return;
    k = (d[0] + d[s - 1]) / 2;
    for (;;) {
	while (d[++i] < k);
	while (d[--j] > k);
	if (i >= j)
	    break;
	t = d[i];
	d[i] = d[j];
	d[j] = t;
    }
    intSort(d, i);
    intSort(d + j + 1, s - j - 1);
}


{
    
    
	return '0' + i;
    



{
    
    
    
    
    
    
    
	
	
	
	
	
	
	    
		break;
	    
	    
	    
	    
		app[a][in[i]] = 1;
	    
		app[in[i - 1]][b] = 1;
	    
		app[a][b] = 1;
	
	
	    
	    
	    deg[j]--;
	
	
	    
	    
		
		
		deg[299]--;
	    
	    
	    else if (deg[0] < -1 && deg[298] > 0) {
		
		
		deg[298]--;
	    
	    
	    else if (deg[1] < 0 && deg[299] > 1) {
		
		
		deg[299]--;
	    
	    
	    else if (deg[1] < 0 && deg[298] > 0) {
		
		
		deg[298]--;
	    
	    
	    else
		break;
	
	
    
    


