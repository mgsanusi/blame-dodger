#include <stdio.h>

#define INF 10000
#define MAXH 720
#define MAX (MAXH+MAXH)



solve ()
{
  
  
  
  
    act[i] = 0;
  
    {
      
      
	act[j] = 1;
    
  
    {
      
      
	act[j] = 2;
    
  
    for (j = 0; j < MAXH + 1; j++)
      for (k = 0; k < 2; k++)
	dp[i][j][k] = INF;
  
  
    for (j = 0; j <= MAXH; j++)
      for (k = 0; k < 2; k++)
	if (dp[i][j][k] < INF)
	  {
	    
	    
	      continue;		/* wrong person */
	    
	    j2 = j;
	    k2 = k;
	    
	      j2++;
	    
	      continue;
	    
	      /* don't change */ 
	      if (dp[i2][j2][k2] > dp[i][j][k])
	      dp[i2][j2][k2] = dp[i][j][k];
	    
	      /* change */ 
	      k2 ^= 1;
	    
	      dp[i2][j2][k2] = dp[i][j][k] + 1;
	  
  
  
    ans = dp[MAX][MAXH][1];
  
    ans++;
  



main ()
{
  
  
  
    printf ("Case #%d: ", caseno++), solve ();
  


