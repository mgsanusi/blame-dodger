#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <stddef.h>
int a[101][101];

void *new_memset(void *ptr, int value, size_t num);
int new_puts(const char *str);
int new_memcmp(const void *ptr1, const void *ptr2, size_t num);
void new_qsort(void *base, size_t num, size_t size,
	       int (*compar) (const void *, const void *));
int new_abs(int x);

{
    

{
    
    
    
    
	
	res = 0;
	
	
	
	
	    
	    
	    tmp = 0;
	    
		
		    
		    
		    
		
		    a[cnt - 1][i]++;
	    
	
	
	    
		f = 0;
		goto END;
	    }
	
	
	    
	    
		
	    
	
      
	
	    printf("%d\n", res);
	
	else
	    new_puts("Fegla Won");
    
    



int new_puts(const char *str);
int new_memcmp(const void *ptr1, const void *ptr2, size_t num);
void new_qsort(void *base, size_t num, size_t size,
	       int (*compar) (const void *, const void *));
int new_abs(int x)
{
    return abs(x);
}

void *new_memset(void *ptr, int value, size_t num);
int new_puts(const char *str);
int new_memcmp(const void *ptr1, const void *ptr2, size_t num);
void new_qsort(void *base, size_t num, size_t size,
	       int (*compar) (const void *, const void *))
{
    return qsort(base, num, size, compar);
}

void *new_memset(void *ptr, int value, size_t num);
int new_puts(const char *str);
int new_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
    return memcmp(ptr1, ptr2, num);
}

void *new_memset(void *ptr, int value, size_t num);
int new_puts(const char *str)
{
    return puts(str);
}

void *new_memset(void *ptr, int value, size_t num)
{
    return memset(ptr, value, num);
}