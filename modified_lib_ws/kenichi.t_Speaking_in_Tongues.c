/* common *********************************************************************/
     
#define _CRT_SECURE_NO_WARNINGS
#define ASC 0
#define DESC 1
#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<math.h>
    FILE * new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
int new_fprintf(FILE * stream, const char *format, ...);
char *new_fgets(char *str, int num, FILE * stream);
int new_atoi(const char *str);

{
    
    
    
	
	    break;
	
	    break;
	
	    *p = '\0';
	    break;
	}
    
    



/******************************************************************************/ 

{
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
	
	
	
	
	    
		
	    
		
	    
	
	
    
    
    



int new_fclose(FILE * stream);
int new_fprintf(FILE * stream, const char *format, ...);
char *new_fgets(char *str, int num, FILE * stream);
int new_atoi(const char *str)
{
    return atoi(str);
}

FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
int new_fprintf(FILE * stream, const char *format, ...);
char *new_fgets(char *str, int num, FILE * stream)
{
    return fgets(str, num, stream);
}

FILE *new_fopen(const char *filename, const char *mode)
{
    return fopen(filename, mode);
}

int new_fclose(FILE * stream)
{
    return fclose(stream);
}