#include <stdio.h>
char ch, b[110][110];

0, -1, 1, 0}, a[110][110];

FILE *new_fopen(const char *filename, const char *mode);
int new_fscanf(FILE * stream, const char *format, ...);
int new_fprintf(FILE * stream, const char *format, ...);
int new_getchar();

{
	
	
		return;
	
	
	    //  printf("(%d , %d)   \n",x,y);
	    for (i = 0; i < 4; i++) {
		
		y0 = y + dy[i];
		
			continue;
		
		
			
			y1 = y0 + dy[j];
			
				
		
		
			
			y1 = y0 + dy[j];
			
				
		
		
		    //printf("%d %d   %d->  %d %d    %d            %d\n  ",x0,y0,a[x0][y0],x1,y1,a[x1][y1],min);
		    if ((min < a[x0][y0]) && (x1 == x) && (y1 == y))
			Flood1(x0, y0);
	



{
	
	
		return;
	
	
		
		y0 = y + dy[i];
		
			
	
	
		
		y0 = y + dy[i];
		
			
	
	
		Flood(x0, y0);
	
	
	



{
	
	
	
	
	
		
		
		
			
				
		
			
				
		
		
			
				
					
					
				
		
		
			
				
			
		
	
	
	    //  getchar();
	    return 0;



int new_fscanf(FILE * stream, const char *format, ...);
int new_fprintf(FILE * stream, const char *format, ...);
int new_getchar()
{
	return getchar();
}

FILE *new_fopen(const char *filename, const char *mode)
{
	return fopen(filename, mode);
}