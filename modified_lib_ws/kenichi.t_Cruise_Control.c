/* common *********************************************************************/
   
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#include<math.h>
  FILE * new_fopen (const char *filename, const char *mode);
int new_fclose (FILE * stream);
int new_fscanf (FILE * stream, const char *format, ...);
int new_fprintf (FILE * stream, const char *format, ...);
void new_qsort (void *base, size_t num, size_t size,
		int (*compar) (const void *, const void *));

GenerateFilename (char *out, char *in, char *add)
{
  
  
  
    {
      
	break;
      
	break;
      
	{
	  *p = '\0';
	  break;
	}
    
  



/******************************************************************************/ 
  
sort1 (const void *data1, const void *data2)
{
  
  
  
    return 1;
  
    return -1;
  



sort0 (const void *data1, const void *data2)
{
  
  
  
    return 1;
  
    return -1;
  



main (int argc, char *argv[])
{
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
    {
      
      
      
      
	{
	  
	  
	  
	  
	
      
      
      
	{
	  
	    {
	      
		{
		  
		  
		
	    
	  else
	    {
	      
		{
		  
		
	      
	    
	
      
	{
	  
	    {
	      
	
      
      
      
	{
	  
	
      
      
    
  
  



int new_fclose (FILE * stream);
int new_fscanf (FILE * stream, const char *format, ...);
int new_fprintf (FILE * stream, const char *format, ...);
void
new_qsort (void *base, size_t num, size_t size,
	   int (*compar) (const void *, const void *))
{
  return qsort (base, num, size, compar);
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