#include <stdio.h>

#define INF 1e100






solve ()
{
  
  
  
  
    scanf ("%d %d", &hr[i], &hs[i]);
  
    for (j = 0; j < n; j++)
      scanf ("%d", &g[i][j]);
  
    {
      
      
	for (j = 0; j < n; j++)
	  dp[i][j] = INF;
      
      
      
	for (j = 0; j < i; j++)
	  if (dp[i][j] < INF)
	    {
	      
		/* take new horse */ 
		if (g[i][i + 1] <= hr[i])
		{
		  
		  
		    dp[i + 1][i] = tid, dpleft[i + 1][i] =
		      hr[i] - g[i][i + 1];
		
	      
		/* use old horse */ 
		if (dpleft[i][j] < g[i][i + 1])
		continue;
	      
	      
		dp[i + 1][j] = tid, dpleft[i + 1][j] =
		  dpleft[i][j] - g[i][i + 1];
	    
      
      
	if (tid > dp[n - 1][i])
	  tid = dp[n - 1][i];
      
      
	printf (" ");
    
  



main ()
{
  
  
  
    printf ("Case #%d: ", caseno++), solve ();
  


