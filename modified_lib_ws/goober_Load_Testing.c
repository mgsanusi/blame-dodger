#include <stdio.h>



{
	
	
	
		
		
		
		
			
				
		
			
				
		
		
			
			
				
					
					
					
						
							
							    orig[a][b];
					
						
						
							
							      b++)
								
								     [b] == -1)
									
									
									    [a]
									    [b]
									    =
									    newdiam
									    [kk
									     -
									     1 -
									     b]
									    [kk
									     -
									     1 -
									     a];
									
						
								else if (newdiam
									 [kk -
									  1 -
									  b][kk
									     -
									     1 -
									     a]
									 == -1)
									
									
									    [kk
									     -
									     1 -
									     b]
									    [kk
									     -
									     1 -
									     a]
									    =
									    newdiam
									    [a]
									    [b];
									
						
								else if (newdiam
									 [a][b]
									 !=
									 newdiam
									 [kk -
									  1 -
									  b][kk
									     -
									     1 -
									     a])
									
									    bad;
						
							
							      b++)
								
								     [b] == -1)
									
									
									    [a]
									    [b]
									    =
									    newdiam
									    [b]
									    [a];
									
						
								else if (newdiam
									 [b][a]
									 == -1)
									
									
									    [b]
									    [a]
									    =
									    newdiam
									    [a]
									    [b];
									
						
								else if (newdiam
									 [a][b]
									 !=
									 newdiam
									 [b][a])
									
									    bad;
						
					
 
					
			
 
		


