#include <stdio.h>
#include <string.h>
#include <stddef.h>





void *new_memset(void *ptr, int value, size_t num);
int new_putchar(int character);
int new_puts(const char *str);

{
	
	
	    /* open chest j */ 
	    keys = K[type[j]];
	
		if (i & (1 << l)) {
			
			
				keys--;
		
	



{
	
	
	
		
		
		
			
			
		
		
		
			
			
				
				
			
		
		
		
		
			if (dp[i]) {
				
					if (!(i & (1 << j))) {
						
							dp[i + (1 << j)] = 1;
					
			
		
		    /* propagate backwards */ 
		    if (dp[(1 << n) - 1])
			dp[(1 << n) - 1] = 2;
		
			if (dp[i] > 1) {
				
					if ((i & (1 << j)) && dp[i - (1 << j)]) {
						
							dp[i - (1 << j)] = 2;
					
			
		
		    /* extract path */ 
		    printf("Case #%d:", no++);
		
			new_puts(" IMPOSSIBLE");
		
		else {
			
				
					if (!(mask & (1 << j))
					    && dp[mask + (1 << j)] > 1
					    && can(mask, j)) {
						
						
						
					
			
			
		
	
	



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