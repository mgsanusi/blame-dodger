#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stddef.h>

#define clr(ar) memset(ar, 0, sizeof(ar))
#define new_read() new_freopen("lol.txt", "r", stdin)
#define write() new_freopen("output.txt", "w", stdout)
    ssize_t new_read(int fd, void *buf, size_t count);
FILE *new_freopen(const char *filename, const char *mode, FILE * stream);

{
	
	
	
		
		
			
			
				
					
					
						ar[k] |= (1 << z);
				
			
		
		
		
			printf("Case #%d: %d\n", ++T, __builtin_ctz(bitmask));
		
		else if (__builtin_popcount(bitmask) > 1)
			printf("Case #%d: Bad magician!\n", ++T);
		
		else
			printf("Case #%d: Volunteer cheated!\n", ++T);
	
	



{
	return read(fd, buf, count);
}

FILE *new_freopen(const char *filename, const char *mode, FILE * stream)
{
	return freopen(filename, mode, stream);
}