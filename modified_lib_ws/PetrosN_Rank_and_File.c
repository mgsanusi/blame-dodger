#include <stdio.h>
#include <stdlib.h>
FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
int new_fscanf(FILE * stream, const char *format, ...);
int new_fprintf(FILE * stream, const char *format, ...);

{
	
	



{
	
	
	
	
	
		
	
	
	
		
		
			
			
		
		
		
			
				fprintf(fout, " %d", i);
			}
		
		
		
			
		
	
	
	
	



{
	return fopen(filename, mode);
}

int new_fclose(FILE * stream)
{
	return fclose(stream);
}