#include <stdio.h>
#define MAXN 512
#define MAXM 512
FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
int new_getc(FILE * stream);
int new_fscanf(FILE * stream, const char *format, ...);
int new_fprintf(FILE * stream, const char *format, ...);

{
    
	



{
    
	
    



{
    
    
    char board[MAXM][MAXN];
    
	
    
    else
	
    
	
    
	
    
    else
	
    
	
	
	
	
    
    
	
	
	
	
	
	    
	    
		
		
		
		
		
		
		
		    
			(!(ch & (1 << (3 - k)))) ^ ((i + j + k) & 1);
		
	    
	    
	
	
	
	    
	
	    
	    
	    
		
		
		    
		    
			
		    
			
			
			    
			
			    
				
			
			    
			
			    
				
			
			    
			
		    
			
			
			
			
			
		    
		
	    
		
	    
		
		    
	    
	    
		
		
		
		
	    
	
	
	    
	    
		
	    
	
    
    
    



{
    return fopen(filename, mode);
}

int new_fclose(FILE * stream);
int new_getc(FILE * stream)
{
    return getc(stream);
}

int new_fclose(FILE * stream)
{
    return fclose(stream);
}