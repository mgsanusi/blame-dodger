#include <stdio.h>




#define get(t, i0, i1, j0, j1) (commsum[i1+1][j1+1][t]-commsum[i0][j1+1][t]-commsum[i1+1][j0][t]+commsum[i0][j0][t])
  
good (ll k, ll a, ll b) 
{
  
  
/*
	if (k == 5 && a == 1 && b == 1) {
		fprintf(stderr, ".");
	}
*/ 
    sum =
    get (0, a, a + k - 1, b,
	 b + k - 1) - mass[a][b] - mass[a + k - 1][b] - mass[a][b + k - 1] -
    mass[a + k - 1][b + k - 1];
  
    get (1, a, a + k - 1, b,
	 b + k - 1) - a * mass[a][b] - (a + k - 1) * mass[a + k - 1][b] -
    a * mass[a][b + k - 1] - (a + k - 1) * mass[a + k - 1][b + k - 1];
  
    get (2, a, a + k - 1, b,
	 b + k - 1) - b * mass[a][b] - b * mass[a + k - 1][b] - (b + k -
								 1) *
    mass[a][b + k - 1] - (b + k - 1) * mass[a + k - 1][b + k - 1];
  
    {
      
    
  
    {
      
    
  



main (void) 
{
  
  
  
    {
      
      
      
	{
	  
	  
	    {
	      
	    
	
      
	commsum[i][0][0] = commsum[i][0][1] = commsum[i][0][2] = 0;
      
	commsum[0][i][0] = commsum[0][i][1] = commsum[0][i][2] = 0;
      
	{
	  
	    {
	      
	      
		commsum[i][j - 1][1] + (i - 1) * mass[i - 1][j - 1];
	      
		commsum[i][j - 1][2] + (j - 1) * mass[i - 1][j - 1];
	    
	  
	    {
	      
	      
	      
	    
	
      
      
      
	{
	  
	    {
	      
		{
		  
		    {
		      
		      
		    
		
	    
	
      
    
    
  
