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
	t = m[i];
	m[i] = m[j];
	m[j] = t;
    }
    intIntSort(d, m, i);
    intIntSort(d + j + 1, m + j + 1, s - j - 1);
}





{
    
    
    
    
    
	
    
	
    
    
    
    
    
	
	    putX = 0;
	
	else
	    putX = nowX + r[ind[i]];
	
	    putY = 0;
	
	else
	    putY = nowY + r[ind[i]];
	
	    break;
	
	    nowX = next;
	    nowY = 0;
	    i--;
	    continue;
	}
	
	
	
	
	
	    next = putX;
	
    
    
	return 1;
    
    
	
	    putX = 0;
	
	else
	    putX = nowX + r[ind[i]];
	
	    putY = 0;
	
	else
	    putY = nowY + r[ind[i]];
	
	    break;
	
	    nowY = next;
	    nowX = 0;
	    i--;
	    continue;
	}
	
	
	
	
	
	    next = putY;
	
    
    
	return 1;
    



{
    
    
    
    
	
	
	
	
	
	    
		break;
	    
	
	
	
	
    
    


