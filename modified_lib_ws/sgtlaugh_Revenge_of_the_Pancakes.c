#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stddef.h>
#include <stddef.h>

#define MAX 12
#define clr(ar) new_memset(ar, 0, sizeof(ar))
#define new_read() new_freopen("lol.txt", "r", stdin)
#define write() new_freopen("out.txt", "w", stdout)


ssize_t new_read(int fd, void *buf, size_t count);
FILE *new_freopen(const char *filename, const char *mode, FILE * stream);
void *new_memset(void *ptr, int value, size_t num);

{
	
	
	
	
		
		
			return dis[mask];
		
			
			
				x ^= (1 << j), y &= (~(1 << j));
			
				
					y |= (1 << k);
			
			
				
				
			
		
	
	



{
	
	
	
	
	
		
		
		
			
				mask |= (1 << i);
		
		
	
	



{
	return read(fd, buf, count);
}

FILE *new_freopen(const char *filename, const char *mode, FILE * stream)
{
	return freopen(filename, mode, stream);
}

void *new_memset(void *ptr, int value, size_t num)
{
	return memset(ptr, value, num);
}