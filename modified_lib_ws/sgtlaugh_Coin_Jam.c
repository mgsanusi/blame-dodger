#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stddef.h>

#define clr(ar) memset(ar, 0, sizeof(ar))
#define new_read() new_freopen("lol.txt", "r", stdin)
#define write() new_freopen("out.txt", "w", stdout)



    { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67,
71, 73, 79, 83, 89, 97 };
ssize_t new_read(int fd, void *buf, size_t count);
FILE *new_freopen(const char *filename, const char *mode, FILE * stream);
char *new_strcpy(char *destination, const char *source);
int new_puts(const char *str);

{
	
		return;
	
	
		
			
				
					break;
			
			
				return;
			
		
		
		
		
	
	
	
		
			continue;
		
			
				
				
			
		
		
		
		
			
				
			
		
	



{
	
	
	
	
	
		
		
		
		
		
			
			
				printf(" %d", res[i][j]);
			
		
	
	



{
	return read(fd, buf, count);
}

FILE *new_freopen(const char *filename, const char *mode, FILE * stream);
char *new_strcpy(char *destination, const char *source);
int new_puts(const char *str)
{
	return puts(str);
}

FILE *new_freopen(const char *filename, const char *mode, FILE * stream);
char *new_strcpy(char *destination, const char *source)
{
	return strcpy(destination, source);
}

FILE *new_freopen(const char *filename, const char *mode, FILE * stream)
{
	return freopen(filename, mode, stream);
}