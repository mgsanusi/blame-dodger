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

{
	
	
	
		
			break;
		
			break;
		
			*p = '\0';
			break;
		}
	
	



/******************************************************************************/ 

{
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
		
		
		
		
		
			
			
			
			
				sum++;
			}
			
			else if (a == p - 1 && b != 0) {
				sum++;
			}
			
			else if (a == p - 1 && b == 0 && S > 0 && a > 0) {
				sum++;
				S--;
			}
			
			else if (a == p - 2 && b == 2 && S > 0) {
				sum++;
				S--;
			}
			
//                      printf("%d %d %d: %d/3=%d...%d", sum, S, p, TotalScore, a, b);
//                      printf("\n");
		}
		
//              printf("\n");
		    
	
	
	



{
	return fopen(filename, mode);
}

int new_fclose(FILE * stream)
{
	return fclose(stream);
}