#include <stdio.h>
#define MAX 200
#define min(a,b) ((a)<(b)?(a):(b))
double correct[MAX];


{
	
	
	
	
	
	
	
	
	
		
		
		
			
			
			
			
		
		
		    //give up
		    cons = min(cons, b + 2);
		
		    //finish it
		    temp =
		    (b - a + 1) * correct[a] + (1 - correct[a]) * (2 * b - a +
								   2);
		
		
		    //delete some
		    for (i = 1; i <= a; i++)
			
			
			    (b - a + 1 + 2 * i) * correct[a - i] + (1 -
								    correct[a -
									    i])
			    * (2 * i + 2 * b - a + 2);
			
			
		
		
	


