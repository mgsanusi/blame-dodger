#include<stdio.h>
FILE *new_freopen(const char *filename, const char *mode, FILE * stream);
int new_getchar();

{
	
	
	}
	
	
		
		
	
	



{
	
	
	
	
	
		
		
		
		
			
			
				
				
			
			
		
		
	


FILE *new_freopen(const char *filename, const char *mode, FILE * stream);
int new_getchar()
{
	return getchar();
}

FILE *new_freopen(const char *filename, const char *mode, FILE * stream)
{
	return freopen(filename, mode, stream);
}