#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning(disable: 4996)






FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
int new_fscanf(FILE * stream, const char *format, ...);
int new_fprintf(FILE * stream, const char *format, ...);
void new_qsort(void *base, size_t num, size_t size,
	       int (*compar) (const void *, const void *));

{
	
	
	
		return -1;
	
		return 0;
	



{
	
	
	
	
	
		
		
		
		
			
			
			
		
		
		
			
				
				
				
			
				
					 'A' - 1 + S[1]);
				
				
				
				
				
		
		
			
			
		
			
		
		
	
	
	


FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
int new_fscanf(FILE * stream, const char *format, ...);
int new_fprintf(FILE * stream, const char *format, ...);
void new_qsort(void *base, size_t num, size_t size,
	       int (*compar) (const void *, const void *))
{
	return qsort(base, num, size, compar);
}

FILE *new_fopen(const char *filename, const char *mode)
{
	return fopen(filename, mode);
}

int new_fclose(FILE * stream)
{
	return fclose(stream);
}