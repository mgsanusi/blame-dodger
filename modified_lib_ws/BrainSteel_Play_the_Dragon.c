
// Google Code Jam 2017
// BrainSteel
// Round 1B
// Problem A
// Compiled with MinGW
  
#define __USE_MINGW_ANSI_STDIO 1
  
#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"
#include "stdint.h"
  
{
  



{
  




{
  
  
   
 
void new_qsort (void *base, size_t num, size_t size,
		int (*compar) (const void *, const void *));

cmppan (const void *a, const void *b) 
{
  
  
  
    
    {
      
    
  
  else if (apan.lateral_area < bpan.lateral_area)
    
    {
      
    
  
  else
    return 0;



main (int argc, char **argv) 
{
  
  
  
  
    
    {
      
      
      
      
      
	
	{
	  
	  
	    2 * M_PI * pancakes[i].R * pancakes[i].H;
	  
	  
	    //printf( "Pancake lateral: %lf, top: %lf\n", pancakes[i].lateral_area, pancakes[i].top_area );
	}
      
	//printf( "Found %d pancakes, selecting %d.\n", N, K );
	new_qsort (pancakes, N, sizeof (Pancake), cmppan);
      
      
      
	
	{
	  
	    pancakes[base].top_area + pancakes[base].lateral_area;
	  
	    //printf( "Initial area at %d: %lf\n", base, area );
	    //printf( "Base radius: %llu\n", pancakes[base].R );
	  int selected = 0;
	  
	    
	    {
	      
		
		{
		  
		  
		
	    
	  
	    //printf( "Current max: %lf\n", max_area );
	    //printf( "New area: %lf\n", area );
	    if (selected == K - 1)
	    
	    {
	      
		
		{
		  
		
	    
	
      
    
  



new_qsort (void *base, size_t num, size_t size,
	   int (*compar) (const void *, const void *))
{
  return qsort (base, num, size, compar);
}