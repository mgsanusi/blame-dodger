#include <stdio.h>
#include <string.h>
FILE *new_fopen(const char *filename, const char *mode);
int new_fscanf(FILE * stream, const char *format, ...);
char *new_fgets(char *str, int num, FILE * stream);

{
    
    
    
    
    
    
    
    
	
	
	    
	
	
	t = 1;
	
	
	
	    
		
		
		
		    n++;
	    
	
	    n = 2;
	
	    
	    
		t *= n;
	
	
    
    



int new_fscanf(FILE * stream, const char *format, ...);
char *new_fgets(char *str, int num, FILE * stream)
{
    return fgets(str, num, stream);
}

FILE *new_fopen(const char *filename, const char *mode)
{
    return fopen(filename, mode);
}