#include <stdio.h>
#include <string.h>
FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
int new_fscanf(FILE * stream, const char *format, ...);
int new_strncmp(const char *str1, const char *str2, size_t num);

{
    
    
    
    
	
    
    else
	
    
	
    
	
    
    else
	
    
	
	
    
    
    
	
	
	
	
	    
	
	    
	
	
	    
	    
	    
	    
		
		
		
		    
		
		    
		    
			 && (dirs[j][pos] == '/' || dirs[j][pos] == 0))
			
		    
		    
		
		    
		    
			
			
			    
			
		    
		    
		    
		
	    
	
	
    
    
    



int new_fclose(FILE * stream);
int new_fscanf(FILE * stream, const char *format, ...);
int new_strncmp(const char *str1, const char *str2, size_t num)
{
    return strncmp(str1, str2, num);
}

FILE *new_fopen(const char *filename, const char *mode)
{
    return fopen(filename, mode);
}

int new_fclose(FILE * stream)
{
    return fclose(stream);
}