#include <stdio.h>
#include <stdlib.h>

{
  
   
 
int new_puts (const char *str);
void new_qsort (void *base, size_t num, size_t size,
		int (*compar) (const void *, const void *));

cmp (const void *a, const void *b) 
{
  



maximum (int a, int b) 
{
  
    {
      
    
  else
    {
      
    



main () 
{
  
  
  
  
  
    {
      
      
      
	{
	  
	  
	  
	
      
      
      
      
	{
	  
	  
	    {
	      
		{
		  
		  
		
	      
	      
	      
	      
	    
	  
	    break;
	
      
      
	printf (" %d %d", a[j][0], a[j][1]);
      
    
  



void
new_qsort (void *base, size_t num, size_t size,
	   int (*compar) (const void *, const void *))
{
  return qsort (base, num, size, compar);
}

int
new_puts (const char *str)
{
  return puts (str);
}