#include <stdio.h>
#include <string.h>






#define MAXV 30000


linkset (int x, int y)
{
  
    p[y] = x;
  
  else
    {
      
      
	rank[y]++;
    



findset (int x)
{
  
    p[x] = findset (p[x]);
  



unionset (int x, int y)
{
  


initset (int n)
{
  
  
    {
      p[i] = i;
      rank[i] = 0;
    }





follow (int x, int y)
{
  
  
    {
      
      
      
	{
	  
	  
	    continue;
	  
	    v = m[x2][y2], bx = x2, by = y2;
	
      
	break;
      
      
	{
	  
	
      
      y = by;
    



main ()
{
  
  
  
  
    {
      
      
	for (j = 0; j < W; j++)
	  scanf ("%d", &m[i][j]);
      
      
      
	for (j = 0; j < W; j++)
	  if (!taken[i][j])
	    follow (i, j);
      
      
	res[i][W * 2 - 1] = 0;
      
      
      
	for (j = 0; j < W; j++)
	  {
	    
	    
	      at++, seen[ss] = at;
	    
	  
      
      
	puts (res[i]);
    
  


