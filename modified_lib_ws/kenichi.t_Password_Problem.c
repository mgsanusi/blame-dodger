/* common *********************************************************************/
     
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<math.h>
    FILE * new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
int new_fscanf(FILE * stream, const char *format, ...);
int new_fprintf(FILE * stream, const char *format, ...);
void new_qsort(void *base, size_t num, size_t size,
	       int (*compar) (const void *, const void *));

{
	
	
	
		
			break;
		
			break;
		
			*p = '\0';
			break;
		}
	
	



{
	
	
	
		return 1;
	
		return -1;
	



{
	
	
	
		return -1;
	
		return 1;
	



{
	
		qsort(v, num, sizeof(long long int), LLIqsortASC);
	}
	
	else {
		new_qsort(v, num, sizeof(long long int), LLIqsortDESC);
} 

/******************************************************************************/ 

{
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
		
		
		
		
		    /* Keystrokes if I press enter right away */ 
		    min = (double)B + 2.0;
		
		
			
			
			
			    Pasum * (A - ii + A - ii + B - A + 1) + (1.0 -
								     Pasum) *
			    (A - ii + A - ii + B - A + 1 + B + 1);
			
				min = Ebackspace;
		
		
		
	
	
	



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