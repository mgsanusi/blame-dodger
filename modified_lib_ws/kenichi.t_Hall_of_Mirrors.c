/* common *********************************************************************/
     
#define _CRT_SECURE_NO_WARNINGS
#define ASC 0
#define DESC 1
#define LLI long long int
#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<math.h>
    FILE * new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
int new_fscanf(FILE * stream, const char *format, ...);
int new_abs(int x);

{
	
	
	
		
			break;
		
			break;
		
			*p = '\0';
			break;
		}
	
	



/******************************************************************************/ 

{
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
		
		
		
		
			
			
				
				
					
					
				
					
					
//                                      ROOM[ii][jj] = (ii-1)*(H-2) + jj;
					    RXi = ii;
					
					
				
					
					
//                                      ROOM[ii][jj] = (ii-1)*(H-2) + jj;
					    break;
				
			
		
		
		    /* check */ 
		    for (ii = 0; ii < H; ii++) {
			
				
					
				
					
				
			
			
		
		
			
				
				
				
					b += 1;
				
					a += H - 2;
				
				
				
				
					b += 1;
				
					a += W - 2;
				
				
							    && Rj ==
							    RXj) ? 1 : 0;
				
//                              SIGHT[D+ii][D+jj] = ROOM[Ri][Rj];
			}
		
		
		
			
				
					
					     && new_abs(jj) != dd)
						continue;
					
						continue;
					
						
						
						    /* Since light does not travel through you, looking directly up only shows you one image of yourself. */ 
						    for (kk = -D; kk <= D; kk++) {
							
								continue;
							
							      ll++) {
								
								     0)
									continue;
								
								     jj * kk)
									SIGHT[D
									      +
									      kk]
									    [D +
									     ll]
									    = 0;
							
						
					
				
			
		
		
	
	
	



int new_fclose(FILE * stream);
int new_fscanf(FILE * stream, const char *format, ...);
int new_abs(int x)
{
	return abs(x);
}

FILE *new_fopen(const char *filename, const char *mode)
{
	return fopen(filename, mode);
}

int new_fclose(FILE * stream)
{
	return fclose(stream);
}