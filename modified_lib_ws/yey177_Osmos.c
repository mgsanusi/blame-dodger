#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX(p,q) (((p)>(q))?(p):(q))
int dp[108][108], s[108];
void new_qsort (void *base, size_t num, size_t size,
		int (*compar) (const void *, const void *));

comp (const void *p, const void *q)
{
  


main ()
{
  
  
  
    {
      
      
      
	scanf ("%d", &s[i]);
      
      
      
      
	dp[0][i] = dp[0][i - 1] * 2 - 1;
      
	for (j = 0; j <= n; j++)
	  {
	    
	      dp[i][j] = MAX (dp[i][j], dp[i - 1][j] + s[i]);
	    
	      dp[i][j] = MAX (dp[i][j], dp[i][j - 1] * 2 - 1);
	    
	      {
		
	      
	  
      
	{
	  
	    {
	      r = i;
	      break;
	    }
	
      
    
  



new_qsort (void *base, size_t num, size_t size,
	   int (*compar) (const void *, const void *))
{
  return qsort (base, num, size, compar);
}