#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stddef.h>

#define inf (1 << 25)
#define min(a,b) ((a)<(b)?(a):(b))
#define clr(ar) memset(ar, 0, sizeof(ar))
#define new_read() new_freopen("lol.txt", "r", stdin)
#define write() new_freopen("output.txt", "w", stdout)
    


ssize_t new_read(int fd, void *buf, size_t count);
size_t new_strlen(const char *str);
FILE *new_freopen(const char *filename, const char *mode, FILE * stream);

{
	
		return inf;
	
		return 0;
	
		return dp[i][j];
	
	
		res = min(res, F(i + 1, j + 1));
	
		res = min(res, 1 + F(i + 1, j));
	
		res = min(res, 1 + F(i, j + 1));
	
	



{
	
	
	
	
	
		
		
		
		
		
		
			printf("Case #%d: Fegla Won\n", ++T);
		
		else
			printf("Case #%d: %d\n", ++T, res);
	
	



{
	return read(fd, buf, count);
}

size_t new_strlen(const char *str)
{
	return strlen(str);
}

FILE *new_freopen(const char *filename, const char *mode, FILE * stream)
{
	return freopen(filename, mode, stream);
}