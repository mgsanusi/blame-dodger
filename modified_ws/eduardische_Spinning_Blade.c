#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXN 2005

{
  
   
 

{
  
 

sort1 (struct datanode a[MAXN], int l, int r) 
{
  
  
  
  j = r;
  x = a[(l + r) / 2].l;
  
    
    {
      
	i++;
      
	j--;
      
	
	{
	  
	  a[i] = a[j];
	  a[j] = y;
	  
	  j--;
	
    
  
    sort1 (a, l, j);
  
    sort1 (a, i, r);



Module (double a) 
{
  
    return -1.0 * a;
  
  else
    return a;



sort2 (struct node a[MAXN], int l, int r) 
{
  
  
  
  j = r;
  x = a[(l + r) / 2];
  
    
    {
      
	i++;
      
	j--;
      
	//while (((a[i].t2 - 1E-9) > x.t2) || ((Module(a[i].t2 - x.t2) < 1E-9) && (a[i].s < x.s))) i++;
	//while (((a[j].t2 + 1E-9) < x.t2) || ((Module(a[i].t2 - x.t2) < 1E-9) && (a[j].s > x.s))) j--;
	if (i <= j)
	
	{
	  
	  a[i] = a[j];
	  a[j] = y;
	  
	  j--;
	
    
  
    sort2 (a, l, j);
  
    sort2 (a, i, r);



main () 
{
  
  
  
  
  
  
    
    {
      
      
      
      
	
	{
	  
	
      
      
      
      
	
	{
	  
	    
	    {
	      
	      
	      
	      
	      
	      
	    
	  
	  
	  
	  
	  
	  
      
	
	{
	  
	  
	  
	  
	  
	
      
      
      
      
	
	{
	  
	    res += a[i].t;
	  
	  else if ((a[i].t2 + 1E-9) <= rem)
	    
	    {
	      
	      
	    
	  
	  else
	    
	    {
	      
	      
	      
	      
	
    


