#include <stdio.h>
#include <string.h>



FILE *new_freopen (const char *filename, const char *mode, FILE * stream);


max (int a, int b)
{
  return a > b ? a : b;
}


backtrack (int left, int pos, int col, int mask, int newmask)
{
  
  
    
  
    {
      
	
	  continue;
      
	
	  continue;
      
	continue;
      
	continue;
      
	max (res,
	     backtrack (x, pos, col + 1, mask,
			newmask | ((1 << col) * x)) + x);
    
  



solve (int pos, int mask)
{
  
    return 0;
  
    return din[pos][mask];
  



{
  
  
  
  
    {
      
      
	{
	  
	
      
      
    
  



{
  return freopen (filename, mode, stream);
}