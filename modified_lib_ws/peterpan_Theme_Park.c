#include <stdio.h>

#define MAXN 1000
    FILE * new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
int new_fscanf(FILE * stream, const char *format, ...);
int new_getchar();

{
    
    
    
    
	/*i=0;
	   while(1)
	   {
	   printf("2^%d = %d",i,((int) 1)<<i);
	   i++;
	   new_getchar();
	   } */ 
	if (argc > 1)
	
    
    else
	
    
	
    
	
    
    else
	
    
	
	
    
    
    
	
	
	
	
	
	    
	
	
	
	
	    
	    
	    
	    
		
		
		
		    
		
		    
		
	    
		
	    
	    
	    
		
		
		
		
	    
	
	
    
    
    



int new_fclose(FILE * stream);
int new_fscanf(FILE * stream, const char *format, ...);
int new_getchar()
{
    return getchar();
}

FILE *new_fopen(const char *filename, const char *mode)
{
    return fopen(filename, mode);
}

int new_fclose(FILE * stream)
{
    return fclose(stream);
}