#include <stdio.h>
#include <stdlib.h>
#define MAX(u,v) (((u)>(v))?(u):(v)) 
#define MOD (1000002013)
typedef struct pair {
	




{
	
	
		return 1;
	
		return -1;
	



{
	
	
	
	
		
		pn = 0;
		
		
			
			
			
			
			
			    //REC o
			    f = 0;
			
				
					p[j].p += pp;
					f = 1;
					break;
				}
			
			
				
				p[pn++].p = pp;
			
			
			    //Rec e
			    f = 0;
			
				
					p[j].p -= pp;
					f = 1;
					break;
				}
			
			
				
				p[pn++].p = -pp;
			
		
		
		
		
			
				continue;
			
				
			
				
				
					
					
					
					
					    (tmp * n -
					     tmp * (tmp - 1) / 2) % MOD;
					
					    (tmp4 +
					     tmp2 * (p[stack[sn]].p % MOD)) %
					    MOD;
					
					
						f = 0;
						break;
					}
				
				
					
					
					    (tmp * n -
					     tmp * (tmp - 1) / 2) % MOD;
					
					    (tmp4 +
					     tmp2 * ((-p[i].p) % MOD)) % MOD;
					
				
			
		
		
	
	
