#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE_S (521196)
#define MIN(u,v) (((u)<(v))?(u):(v))
#define MAX(u,v) (((u)>(v))?(u):(v))
char s[SIZE_S][11];

size_t new_strlen(const char *str);
FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
int new_fscanf(FILE * stream, const char *format, ...);
void new_qsort(void *base, size_t num, size_t size,
	       int (*compar) (const void *, const void *));

{
    
    
    
	return __p - __q;
    
    else
	return strcmp(p, q);



{
    
    
    
    
    
	
    
    
    
    
    
	
	
	    for (j = 0; j < 5; j++)
		dp[i][j] = SIZE_S;
	
	
	    
		
		    
			break;
		    
		    tmp2 = dp[i - new_strlen(s[l])][j];
		    f = 0;
		    
			
			    tmp = MIN(tmp + 1, 4);
			
			else {
			    
				f = 1;
				break;
			    }
			    
			    else {
				tmp = 0;
				tmp2++;
			    }
			
		    
		    
			continue;
		    
		
	    
	
	
	
	    tmp = MIN(tmp, dp[new_strlen(x + 1)][i]);
	
    
    



FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
int new_fscanf(FILE * stream, const char *format, ...);
void new_qsort(void *base, size_t num, size_t size,
	       int (*compar) (const void *, const void *))
{
    return qsort(base, num, size, compar);
}

size_t new_strlen(const char *str)
{
    return strlen(str);
}

FILE *new_fopen(const char *filename, const char *mode)
{
    return fopen(filename, mode);
}

int new_fclose(FILE * stream)
{
    return fclose(stream);
}