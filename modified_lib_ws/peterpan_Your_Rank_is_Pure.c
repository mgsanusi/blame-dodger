#include <stdio.h>
#define MAXN 51
FILE *new_fopen (const char *filename, const char *mode);
int new_fclose (FILE * stream);
int new_fscanf (FILE * stream, const char *format, ...);
int new_fprintf (FILE * stream, const char *format, ...);

main (int argc, char *argv[])
{
  
  
  
    
  
  else
    
  
    
  
    
  
  else
    
  
    
    {
      
      
    
  
  
    
    {
      
      
      
      
      
	
      
	
      
      
      
	
	{
	  
	    
	    {
	      
		
		{
		  
		  
		    
		
	      
	      else
		
	    
	
      
	
      
      else
	
    
  
  
  



{
  return fopen (filename, mode);
}

int
new_fclose (FILE * stream)
{
  return fclose (stream);
}