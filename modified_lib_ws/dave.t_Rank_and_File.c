#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning(disable: 4996)





FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
int new_fscanf(FILE * stream, const char *format, ...);
int new_fprintf(FILE * stream, const char *format, ...);

{
    
    
    
    
    
	
	
	
	    
	
	
	
	    
	    
	
	
	    
		
	    
	
	
    
    
    


FILE *new_fopen(const char *filename, const char *mode)
{
    return fopen(filename, mode);
}

int new_fclose(FILE * stream)
{
    return fclose(stream);
}