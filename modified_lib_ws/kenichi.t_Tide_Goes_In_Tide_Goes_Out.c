/* common *********************************************************************/
     
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#include<math.h>
    FILE * new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
int new_fscanf(FILE * stream, const char *format, ...);
int new_fprintf(FILE * stream, const char *format, ...);
void new_free(void *ptr);

{
    
    
    
	
	    break;
	
	    break;
	
	    *p = '\0';
	    break;
	}
    
    



/******************************************************************************/ 


    
    
    
    


{
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
	
	
	
	    
	
	
	    
	    
		(ST_NODE **) calloc(node_p->parent_num, sizeof(ST_NODE *));
	    
		  node_pp1 < node_p->parent + node_p->parent_num;
		  node_pp1++) {
		
		
	    
	
	
	    
		
	    
	    
	    
	    
	    
	    
		
		      node_pp3 <
		      (*node_pp2)->parent + (*node_pp2)->parent_num;
		      node_pp3++) {
		    
			break;
		    
		    
		    
		
		
		     (*node_pp2)->parent + (*node_pp2)->parent_num)
		    break;
	    
	    
		break;
	
	
	    
	
	    
	
	
	    
	
	
    
    
    
    



int new_fclose(FILE * stream);
int new_fscanf(FILE * stream, const char *format, ...);
int new_fprintf(FILE * stream, const char *format, ...);
void new_free(void *ptr)
{
    return free(ptr);
}

FILE *new_fopen(const char *filename, const char *mode)
{
    return fopen(filename, mode);
}

int new_fclose(FILE * stream)
{
    return fclose(stream);
}