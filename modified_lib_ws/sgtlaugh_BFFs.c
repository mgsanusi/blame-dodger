#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stddef.h>

#define MAX 20
#define min(a,b) ((a)<(b) ? (a):(b))
#define max(a,b) ((a)>(b) ? (a):(b))
#define clr(ar) memset(ar, 0, sizeof(ar))
#define new_read() new_freopen("lol.txt", "r", stdin)
#define write() new_freopen("out.txt", "w", stdout)


ssize_t new_read(int fd, void *buf, size_t count);
FILE *new_freopen(const char *filename, const char *mode, FILE * stream);
int new_abs(int x);

{
	
		
			backtrack(1, 0, x, y);
		
		else {
			
			
				res = z, a = x, b = y;
			
			else if (z == res && x < a)
				a = x, b = y;
			
			else if (z == res && x == a && y < b)
				b = y;
		
		
	
	
	
		
			
			
				d = C[j] - 48;
			
		
		
		else {
			
			
				d = J[j] - 48;
			
		
	



{
	
		return 1;
	
	
		
		
	
	



{
	
	
	
	
	
		
		
		
		
		
			printf("0");
		
		
			printf("0");
		
	
	



FILE *new_freopen(const char *filename, const char *mode, FILE * stream);
int new_abs(int x)
{
	return abs(x);
}

ssize_t new_read(int fd, void *buf, size_t count)
{
	return read(fd, buf, count);
}

FILE *new_freopen(const char *filename, const char *mode, FILE * stream)
{
	return freopen(filename, mode, stream);
}