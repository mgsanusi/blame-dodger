#include <stdio.h>



getxy (int p, int *x2, int *y2, int *dx, int *dy)
{
  
    {
      *x2 = p, *y2 = 0, *dx = 0, *dy = 1;
      return;
    }
  
  
    {
      *x2 = x - 1, *y2 = p, *dx = -1, *dy = 0;
      return;
    }
  
  
    {
      *x2 = x - p - 1, *y2 = y - 1, *dx = 0, *dy = -1;
      return;
    }
  
  
  *y2 = y - p - 1;
  *dx = 1;
  *dy = 0;



check ()
{
  
  
    {
      
      
      do
	{
	  
	    dy = -dx, dx = 0;
	  
	  else if (dx && g[y2][x2] == '\\')
	    dy = dx, dx = 0;
	  
	  else if (dy && g[y2][x2] == '/')
	    dx = -dy, dy = 0;
	  
	  else if (dy && g[y2][x2] == '\\')
	    dx = dy, dy = 0;
	  
	  y2 += dy;
	
      while (x2 >= 0 && y2 >= 0 && x2 < x && y2 < y);
      
	out = x2;
      
      else if (x2 == x)
	out = y2 + x;
      
      else if (y2 == y)
	out = x + y + x - x2 - 1;
      
      else
	out = x + y + x + y - y2 - 1;
      
	return 0;
    
  



solve ()
{
  
  
  
  
  
    scanf ("%d", &par[i]), par[i]--;
  
    {
      
	if (mask & (1 << i))
	  g[i % y][i / y] = '/';
      
	else
	  g[i % y][i / y] = '\\';
      
	{
	  
	    {
	      
		putchar (g[i][j]);
	      
	    
	  
	
    
  



main ()
{
  
  
  
    printf ("Case #%d:\n", caseno++), solve ();
  


