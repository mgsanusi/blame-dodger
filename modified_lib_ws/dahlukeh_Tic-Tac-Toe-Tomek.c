#include <stdio.h>
#include <stdlib.h>

#define TRUE         1
#define FALSE        0
    
#define XWON         0
#define OWON         1
#define NO_WON       2
#define BLANK        3
    FILE * new_freopen(const char *filename, const char *mode, FILE * stream);







{
	
	
	
	
	
	
		
		
	
	




{
	
	
	
		
			
			
			
			
				
			
				
			
				
			
				
				
			
			
		
	
	
		
			
				
				
					
					
				
					
					
				
			
		
	
	
		
	
		
	



{
	
	
	
		
			
		
		
			
		
		
			
				
			
				
			
		
		
		
	
	


FILE *new_freopen(const char *filename, const char *mode, FILE * stream)
{
	return freopen(filename, mode, stream);
}