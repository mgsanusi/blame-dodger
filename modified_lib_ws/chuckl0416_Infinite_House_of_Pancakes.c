#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>





  { {0, 1, 2, 3}, {1, 4, 3, 6}, {2, 7, 4, 1}, {3, 2, 5, 4} };

FILE *new_freopen (const char *filename, const char *mode, FILE * stream);
int new_puts (const char *str);

XMod (int In)
{
  
  
    return (x + 12);
  
    return (x + 8);
  
    return (x + 4);
  



Check (int Level)
{
  
  
    {
      
	{
	  
	  
	
      
	return 1;
      
    
  
    {
      
      
      
	break;
    
  
    return Check (Level + 1);
  



Transform (char ch)
{
  
    return 0;
  
    return 1;
  
    return 2;
  
    return 3;



main ()
{
  
  
  
    for (x = 0; x < 4; x++)
      StateTable[y][x + 4] = (StateTable[y][x] + 4) % 8;
  
    for (x = 0; x < 8; x++)
      StateTable[y + 4][x] = (StateTable[y][x] + 4) % 8;
  
  
    {
      
      
      
      
      
	Input[i] = Transform (InputT[i]);
      
	{
	  
	  
	    Input[LT + x] = Input[x];
	
      
      
      
	new_puts ("YES");
      
      else
	new_puts ("NO");
    
  



int
new_puts (const char *str)
{
  return puts (str);
}

FILE *
new_freopen (const char *filename, const char *mode, FILE * stream)
{
  return freopen (filename, mode, stream);
}