#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
int s[160], t[160], u[160];
int new_memcmp(const void *ptr1, const void *ptr2, size_t num);
void new_qsort(void *base, size_t num, size_t size,
	       int (*compar) (const void *, const void *));

{
	

{
	
	
	
	
		
		
		
			
			
			
				if (tmps[j] == '1')
					s[i] |= (1 << (l - 1 - j));
		
		
			
			
			
				if (tmps[j] == '1')
					t[i] |= (1 << (l - 1 - j));
		
		
		
			
				u[j] = t[j] ^ i;
			
			
				
				tmp = 0;
				
					
						tmp++;
					
				
				
					res = tmp;
			
		
		
			printf("Case #%d: NOT POSSIBLE\n", k);
		
		else
			printf("Case #%d: %d\n", k, res);
	
	



void new_qsort(void *base, size_t num, size_t size,
	       int (*compar) (const void *, const void *))
{
	return qsort(base, num, size, compar);
}

int new_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	return memcmp(ptr1, ptr2, num);
}