#include <stdio.h>
#include <stdint.h>
int m[1010];

{
	
	
	
	
		
		
			scanf("%d", m + i);
		
		
		
			c = (a + b) >> 1;
			
			
				j += 1 + c / m[i];
			
				a = c + 1;
			
			else
				b = c - 1;
		
		
		
			j += 1 + a / m[i];
		
		    //printf("%d %d %d\n",a,b,j);
		    /*if(j>n)printf("+");
		       else */ 
		    while (j >= n) {
			
			    //printf("-"),
			    a--;
			
			
				j += 1 + a / m[i];
		
		
			
			    //printf("-"),
			    a++;
			
			
				j += 1 + a / m[i];
		
		
		    //else printf(".");
		    for (i = B; i > 0; i--) {
			
			    //printf("%d %d\n",a/m[i-1],(a-1)/m[i-1]);
			    if (a / m[i - 1] > (a - 1) / m[i - 1])
				--j;
			
				break;
		
		
			printf("Case #%d: %d\n", Ti, i);
		
		else
			printf("Case #%d: %d\n", Ti, n);
	
	


