#include <stdio.h>
#include <string.h>




{
	
	
		v = v * 10 + st[i];
	



{
	
	
		st[i] = v % 10, v /= 10;



/* element d represents the largest non-starting stack and cannot be split */ 
void bfs()
{
	
	
	
	
		cur[i] = p[i];
	
	
	
	
	
		
		
		
		
			if (cur[i])
				goto more;
		
		
 
		    /* eat */ 
		    for (i = 0; i <= d; i++)
			next[i] = cur[i];
		
			if (next[i])
				next[i]--;
		
		
			q[qe++] = val, dist[val] = moves + 1;
		
		    /* special, split a stack */ 
		    for (i = 0; i < d; i++)
			if (cur[i] > 1)
				for (j = 1; j < cur[i]; j++) {
					
						next[k] = cur[k];
					
					
						next[d] = j;
					
					
						q[qe++] = val, dist[val] =
						    moves + 1;
				
	



{
	
	
	
		scanf("%d", &p[i]);
	



{
	
	
	
		printf("Case #%d: ", caseno++), solve();
	


