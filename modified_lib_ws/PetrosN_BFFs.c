#include <stdio.h>
#include <stdlib.h>
FILE *new_fopen (const char *filename, const char *mode);
int new_fclose (FILE * stream);
int new_fscanf (FILE * stream, const char *format, ...);
int new_fprintf (FILE * stream, const char *format, ...);
int new_fgetc (FILE * stream);

main () 
{
  
  
  
  
  
  
  
  
    {
      
	dgt[j] = 0;
      
	{
	  
	    dgt[0]++;
	  
	  else if (c == 'W')
	    dgt[2]++;
	  
	  else if (c == 'U')
	    dgt[4]++;
	  
	  else if (c == 'X')
	    dgt[6]++;
	  
	  else if (c == 'G')
	    dgt[8]++;
	  
	  else if (c == 'H')
	    dgt[3]++;
	  
	  else if (c == 'V')
	    dgt[7]++;
	  
	  else if (c == 'F')
	    dgt[5]++;
	  
	  else if (c == 'I')
	    dgt[9]++;
	  
	  else if (c == 'O')
	    dgt[1]++;
	
      
      
      
      
      
      
      
	{
	  
	    {
	      
	    
	
      
    
  
  
  



int new_fclose (FILE * stream);
int new_fscanf (FILE * stream, const char *format, ...);
int new_fprintf (FILE * stream, const char *format, ...);
int
new_fgetc (FILE * stream)
{
  return fgetc (stream);
}

FILE *
new_fopen (const char *filename, const char *mode)
{
  return fopen (filename, mode);
}

int
new_fclose (FILE * stream)
{
  return fclose (stream);
}