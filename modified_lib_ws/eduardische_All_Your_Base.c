#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAXN 505
#define EPSILON 1E-9

{
  
 

{
  
 

GetVec (struct point a[MAXN], int N) 
{
  
  
  
  
  
  
    
    {
      
      
      
    
  
  
  
  
  
  
  
    
    {
      
      
      
    
  
  
  
  
  
  
  


double new_sqrt (double x);

GetDist (struct vec a, double t) 
{
  
  
  
  
  
    x *= -1;
  
    y *= -1;
  
    z *= -1;
  
  



main () 
{
  
  
  
  
  
  
  
  
  
    
    {
      
      
	scanf ("%d %d %d %d %d %d", &(a[i].x), &(a[i].y), &(a[i].z),
	       &(a[i].vx), &(a[i].vy), &(a[i].vz));
      
      
      r = 2500020.0;
      
      
      
	
	{
	  
	    //printf("(%.8f ; %.8f)\n",l,r);
	    c1 = l + ((r - l) / 3);
	  
	  
	  
	  
	    ta = 0;
	  else
	    ta = 1;
	  
	    tb = 0;
	  else
	    tb = 1;
	  
	    tc = 0;
	  else
	    tc = 1;
	  
	    
	    {
	      
	      
	    
	  
	  else if (tb)
	    
	    {
	      
	      
	    
	  
	  else if (tc)
	    
	    {
	      
	      
	    
	  
	  else
	    
	    {
	      
	      
	    
	
      
      
      
    
  



new_sqrt (double x)
{
  return sqrt (x);
}