#include <stdio.h>
#include <string.h>
#include <stddef.h>


void *new_memset(void *ptr, int value, size_t num);
int new_putchar(int character);

{
	
	
	
	
		
		
		
		
			
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
			
				
		
	
	



int new_putchar(int character)
{
	return putchar(character);
}

void *new_memset(void *ptr, int value, size_t num)
{
	return memset(ptr, value, num);
}