#include <stdio.h>
#include <stdlib.h>
FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
int new_fscanf(FILE * stream, const char *format, ...);
int new_fprintf(FILE * stream, const char *format, ...);
int new_fgetc(FILE * stream);

{
	
	
	
	
	
	
	
	
		
		
		
		
		
			
				A[first - 1] = c;
				first--;
			}
			
			else {
				A[last + 1] = c;
				last++;
			}
		
		
		
			
		
		
	
	
	
	



int new_fclose(FILE * stream);
int new_fscanf(FILE * stream, const char *format, ...);
int new_fprintf(FILE * stream, const char *format, ...);
int new_fgetc(FILE * stream)
{
	return fgetc(stream);
}

FILE *new_fopen(const char *filename, const char *mode)
{
	return fopen(filename, mode);
}

int new_fclose(FILE * stream)
{
	return fclose(stream);
}