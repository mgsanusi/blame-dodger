#include <stdio.h>
#include <stdlib.h>

// Output 0 if no way this guy can get >= bound;
// Output 1 if this guy can get >= bound via surprise;
// Else output 2.
/*
k, k, k   -> 3k
k, k, k+1 -> 3k+1
k, k+1, k+1 -> 3k+2

k, k, k+2 -> 3k+2, only works for scores >= 2 && <= 28
k, k+1, k+2 -> 3k+3
k, k+2, k+2 -> 3k+4
*/ 
  
check_bound (int score, int bound)
{
  
    return 2;
  
  else if (score >= 2 && score <= 28 && (score + 4) / 3 >= bound)
    return 1;
  
  else
    return 0;



// Main
  
main ()
{
  
  
  
    {
      
      
      
	{
	  
	  
	  
	    num++;
	  
	  else if (k == 1)
	    potential++;
	
      
	potential = num_surp;
      
    
  


