#include <stdio.h>
#include <string.h>
#include <stddef.h>


void *new_memset(void *ptr, int value, size_t num);
int new_putchar(int character);
int new_puts(const char *str);

{
    
    
	
    
    
	
    
	   || (nowM - (r - skipR - 2) * (c - skipC - 2)) % 2 == 0) {
	
	    
		
	
	    
		
	
	    
		  (i - skipR) * (c - skipC - 2) + j - skipC < nowM
		  && j < c - 2; j++)
		
	
	    
		  (r - skipR - 2) * (c - skipC - 2) + (i - skipR) * 2 <
		  nowM && i < r - 2; i++)
		
	
	     (r - skipR - 2) * 2 > 0)
	    
		  (r - skipR - 2) * (c - skipC - 2) + (r - skipR - 2) * 2 +
		  (j - skipC) * 2 < nowM && j < c - 2; j++)
		
	
    
    
	   || nowM - r + skipR >= 0
	   && dfs(skipR, skipC + 1, nowM - r + skipR))
	
    



{
    
    
    
    
	
	
	
	
	
	    
	    
		
		    
	    
	    else
		
		    
	
	
	    
	
	else if (m == r * c - 1) {
	    
	    
		
		    
	
	    
	
	else
	    
	
	
	
	    
		
		    
		
	    
	
	else
	    
    
    



int new_putchar(int character);
int new_puts(const char *str)
{
    return puts(str);
}

void *new_memset(void *ptr, int value, size_t num);
int new_putchar(int character)
{
    return putchar(character);
}

void *new_memset(void *ptr, int value, size_t num)
{
    return memset(ptr, value, num);
}