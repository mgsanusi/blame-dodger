#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
int new_puts(const char *str);

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
    
    
    
    
    
    
    
	
	
	
	
	
	
	
	
	
	
	
	
	    
	    
	    
		ok = 1;
		break;
	    }
	    
		
		
		
		    break;
		
		
		    dis = len[k];
		
		    
		    
			stin[k] = 1, st[st_size++] = k;
		
	    
	    
		
		
		
		    break;
		
		
		    dis = len[k];
		
		    
		    
			stin[k] = 1, st[st_size++] = k;
		
	    
	
	
	
	    new_puts("YES");
	else
	    new_puts("NO");
    
    



{
    return puts(str);
}