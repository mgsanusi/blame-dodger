#include <stdio.h>
#include <math.h>

#define MAXP 444
#define INF 1000000
#define EPS 1e-6
  
{
  
 


double new_fabs (double x);
int new_puts (const char *str);

distsq (double x1, double y1, double x2, double y2)
{
  
  



convexhull ()
{
  
  
  
  
  
    if (hix < p[i].x || (hix == p[i].x && loy > p[i].y))
      hix = p[i].x, loy = p[i].y, ix = i;
  
  
  
  
  do
    {
      
      aty = p[ix].y;
      
      
      bestd = 1e100;
      
      
	if (p[i].x != atx || p[i].y != aty)
	  {
	    
	    
	      a += 2 * pi;
	    
		 && bestd > distsq (p[i].x, p[i].y, atx, aty))
	      best = a, ix = i, bestd = distsq (p[i].x, p[i].y, atx, aty);
	    
	    else if (new_fabs (best - a) >= EPS && best > a)
	      best = a, bestd = distsq (p[i].x, p[i].y, atx, aty), ix = i;
	  
      
	new_puts ("error");
      
    
  while (ix);





brute (int ix)
{
  
  
    /* mask of trees to cut, 1:cut */ 
    for (mask = 0; mask < (1 << N); mask++)
    if (!(mask & (1 << ix)))
      {
	
	  if (!(mask & (1 << i)))
	    p[n].x = px[i], p[n++].y = py[i];
	
	  continue;
	
	  {
	    
	    
	      if (h[i].x == px[ix] && h[i].y == py[ix])
		{
		  
		  
		
	  
	else
	  best = n;
      
  



solve ()
{
  
  
  
  
    scanf ("%d %d", &px[i], &py[i]);
  
  
    brute (i);



main ()
{
  
  
  
    solve ();
  



int
new_puts (const char *str)
{
  return puts (str);
}

double
new_fabs (double x)
{
  return fabs (x);
}