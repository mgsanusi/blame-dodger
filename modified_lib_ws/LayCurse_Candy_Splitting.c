#include<stdio.h>
#include<stdlib.h>
#include<math.h>
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
    }
    intSort(d, i);
    intSort(d + j + 1, s - j - 1);
}


{
    
    
    
    
    
	
	
	
	
	
	
	    new_puts("NO");
	    continue;
	}
	
	
	
    
    



{
    return puts(str);
}