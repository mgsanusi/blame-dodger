#include <stdio.h>
#include <string.h>
#include <stddef.h>




FILE *new_fopen(const char *filename, const char *mode);
void *new_memset(void *ptr, int value, size_t num);
int new_fscanf(FILE * stream, const char *format, ...);

{
	
	
	



{
	
	
	
	
	
	
	
	
	
		
		
		
		
		
		
			
		
		
		
		
			
			
			
				
				
					
					
					
					
				
			
		
		
	
	



{
	return fopen(filename, mode);
}

void *new_memset(void *ptr, int value, size_t num)
{
	return memset(ptr, value, num);
}