#include<stdio.h>
FILE *new_freopen(const char *filename, const char *mode, FILE * stream);

{
    
    
    
    
    
	
	
	
	
	
	    
	
	
    


FILE *new_freopen(const char *filename, const char *mode, FILE * stream)
{
    return freopen(filename, mode, stream);
}