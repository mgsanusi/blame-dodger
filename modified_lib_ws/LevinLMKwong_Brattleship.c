#include<stdio.h>
#include<string.h>
#include <stddef.h>
FILE *new_freopen(const char *filename, const char *mode, FILE * stream);
void *new_memset(void *ptr, int value, size_t num);
char *new_strncpy(char *destination, const char *source, size_t num);

{
	
	
	
	
		
		
			
		
	
	



{
	
	
	
	
	
	
	
	
		
		
		
		
		
		
			
			
		
		
		
			
		
		
		
			
			
			
			
			
				
			
				
			
		
		
		
		
			
				
				
			
		
		
			
			count = 0;
			
				
					j = 0;
				
					
					
				
					
				
			
			
			    //printf("count:%d\n",count);
			    ans1 = 1;
			
				
			
			
			
			    //printf("ans:%d\n",ans1);
			    ans = (double)ans1;
			
				
			
			
			    //printf("ans:%f\n",ans);
			    ans = count - ans;
		
		
	


FILE *new_freopen(const char *filename, const char *mode, FILE * stream);
void *new_memset(void *ptr, int value, size_t num);
char *new_strncpy(char *destination, const char *source, size_t num)
{
	return strncpy(destination, source, num);
}

FILE *new_freopen(const char *filename, const char *mode, FILE * stream)
{
	return freopen(filename, mode, stream);
}

void *new_memset(void *ptr, int value, size_t num)
{
	return memset(ptr, value, num);
}