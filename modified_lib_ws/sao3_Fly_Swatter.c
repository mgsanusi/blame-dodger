#include <stdio.h>
#include <stdlib.h>



FILE *new_freopen(const char *filename, const char *mode, FILE * stream);
void new_qsort(void *base, size_t num, size_t size,
	       int (*compar) (const void *, const void *));

{
	

{
	
	
	
	
		
	
	
		
	
	
	
	
	
		
	



{
	
	
	
	
	
		
		
	
	



void new_qsort(void *base, size_t num, size_t size,
	       int (*compar) (const void *, const void *))
{
	return qsort(base, num, size, compar);
}

FILE *new_freopen(const char *filename, const char *mode, FILE * stream)
{
	return freopen(filename, mode, stream);
}