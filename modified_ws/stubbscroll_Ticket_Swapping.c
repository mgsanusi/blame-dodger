#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MOD 1000002013LL
typedef long long ll;


{
  



compf (const void *A, const void *B)
{
  
  
    return -1;
  
    return 1;
  
    return -1;
  
    return 1;
  



unique ()
{
  
  
    if (from[i].a == from[i - 1].a && from[i].b == from[i - 1].b)
      from[j - 1].c += from[i].c;
  
    else
      from[j].a = from[i].a, from[j].b = from[i].b, from[j++].c = from[i].c;
  



lolsort ()
{
  
  



calccost ()
{
  
  
  
    {
      
      
    
  



overlap (int ix, int iy)
{
  
    && from[ix].b < from[iy].b;



calccost2 ()
{
  
  
  
  do
    {
      
      
      
      
	if (from[i].c > 0)
	  {
	    
	      /* find overlap */ 
	      for (j = i + 1; j < oldM; j++)
	      if (from[j].c && overlap (i, j))
		{
		  
//                              printf("%d (%I64d %I64d %I64d) and %d (%I64d %I64d %I64d) overlap)\n",i,from[i].a,from[i].b,from[i].c,j,from[j].a,from[j].b,from[j].c);
		    num = from[i].c < from[j].c ? from[i].c : from[j].c;
		  
		  
		  
		  from[M].b = from[j].b;
		  from[M++].c = num;
		  
		  from[M].b = from[i].b;
		  from[M++].c = num;
		  
		
	  
    
  while (ch);
  



main ()
{
  
  
  
  
    {
      
      
	scanf ("%I64d %I64d %I64d", &from[i].a, &from[i].b, &from[i].c);
      
      
      
      
      
      
	normalcost += MOD;
      
    
  


