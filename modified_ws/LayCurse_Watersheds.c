#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

unionInit (int d[], int s)
{
  int i;
  rep (i, s) d[i] = i;
} 

unionGet (int d[], int n)
{
  int t = n, k;
  while (d[t] != t)
    t = d[t];
  while (d[n] != n)
    k = d[n], d[n] = t, n = k;
  return n;
}


unionConnect (int d[], int a, int b)
{
  a = unionGet (d, a);
  b = unionGet (d, b);
  if (a == b)
    return 0;
  d[a] = b;
  return 1;
}


main ()
{
  
  
  
  
  {
  0, -1, 1, 0};
  
  
  
  
    {
      
      xy = x * y;
      
      
      
      {
	
	ny = j;
	
	{
	  
	  sy = j + dy[k];
	  
	    continue;
	  
	    nx = sx, ny = sy;
	
	
      
      
      
      k = 0;
      
      {
	
	
	  use[m] = k++;
	
	
	  putchar (' ');
	else
	  putchar ('\n');
      
    
  


