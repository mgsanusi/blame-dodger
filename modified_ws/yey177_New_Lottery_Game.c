#include <stdio.h>
#include <string.h>
#define MAX(p,q) (((p)>(q))?(p):(q))
long long dp[8][32], pow2[64];


/*
dp0..a full b full k part
dp1..a part b full k part
dp2..a full b part k part
dp3..a part b part k part
*/ 
  
main ()
{
  
  
  
  
    pow2[i] = 2 * pow2[i - 1];
  
    {
      
      
      b--;
      k--;
      
      
      
      
      
      cnta = 0;
      
	{
	  as[cnta++] = (tmp & 1);
	  tmp >>= 1;
	}
      
      cntb = 0;
      
	{
	  bs[cntb++] = (tmp & 1);
	  tmp >>= 1;
	}
      
      cntk = 0;
      
	{
	  ks[cntk++] = (tmp & 1);
	  tmp >>= 1;
	}
      
      
      
      
      
      
	{
	  
	    {
	      
	      
		{
		  
		  
		  
		
	      else if (as[i] == 1 && bs[i] == 0)
		{
		  
		  
		  
		
	      else if (as[i] == 0 && bs[i] == 1)
		{
		  
		  
		  
		
	      else
		{
		  
		  
		  
		
	    
	  else
	    {
	      
	      
		{
		  
		  
		  
		
	      else if (as[i] == 1 && bs[i] == 0)
		{
		  
		    dp[0][i - 1] * 2 + dp[1][i - 1] + ((a & (pow2[i] - 1)) +
						       1) * pow2[i];
		  
		  
		
	      else if (as[i] == 0 && bs[i] == 1)
		{
		  
		  
		    dp[0][i - 1] * 2 + dp[2][i - 1] +
		    pow2[i] * ((b & (pow2[i] - 1)) + 1);
		  
		
	      else
		{
		  
		    dp[0][i - 1] * 2 + dp[1][i - 1] + ((a & (pow2[i] - 1)) +
						       1) * pow2[i];
		  
		    dp[0][i - 1] * 2 + dp[2][i - 1] +
		    pow2[i] * ((b & (pow2[i] - 1)) + 1);
		  
		    dp[0][i - 1] + dp[1][i - 1] + dp[2][i - 1] +
		    ((a & (pow2[i] - 1)) + 1) * ((b & (pow2[i] - 1)) + 1);
		
	    
	
      
	       (long long) (a + 1) * (b + 1) - dp[3][cnt]);
    


