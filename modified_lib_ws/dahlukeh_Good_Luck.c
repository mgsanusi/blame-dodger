#include <stdio.h>
#include <stdlib.h>

#define TRUE      1
#define FALSE     0
#define MOD       1000002013ll
  
{
  
   
   
   
 






FILE *new_freopen (const char *filename, const char *mode, FILE * stream);


min (int n1, int n2)
{
  



sort (int start, int end, struct range *p)
{
  
    {
      
    
  
  
  
  
  
  
  
  
    {
      
	{
	  
	
      else if (place2 > end)
	{
	  
	
      else
	{
	  
		&& (p[place1].s < p[place2].s
		    || (p[place1].s == p[place2].s
			&& p[place1].e < p[place2].e))) || (typeSort == 1
							    && (p[place1].e >
								p[place2].e
								|| (p[place1].
								    e ==
								    p[place2].
								    e
								    &&
								    p[place1].
								    s >
								    p[place2].
								    s))))
	    {
	      
	    
	  else
	    {
	      
	    
	
    
  
    {
      
    



main ()
{
  
  
  
  
  
  
    {
      
      
    
  



findAmo (int s, int e)
{
  
    {
      
    
  
  
  
    ((lN * (lN + 1ll)) / 2ll) - (((lN - diff) * (lN + 1ll - diff)) / 2ll);
  



getSwapAmo (int s1, int e1, int s2, int e2)
{
  
  
  
  




handlecase ()
{
  
  
  
    {
      
    
  
  
  
    {
      
	// Find person intersecting and furthest away
      int furEnd = 0;
      
      
	{
	  
	       && people[j].e > people[i].e && people[j].p > 0)
	    {
	      
		{
		  
		  
		
	    
	
      
	// Make a swap
	if (ind != -1)
	{
	  
	    {
	      
		// We swap completely with them, cloning us
	      long long sw =
		(long long) getSwapAmo (people[i].s, people[i].e,
					people[ind].s, people[ind].e);
	      
	      
	      
	      
	      
		// Set up new group
		people[nP].s = people[ind].s;
	      
	      
	      
	      
	      
	      
	    
	  else
	    {
	      
		(long long) getSwapAmo (people[i].s, people[i].e,
					people[ind].s, people[ind].e);
	      
	      
	      
	      
	      
		// Set up new group
		people[nP].s = people[i].s;
	      
	      
	      
	      
	      
	      
	
    

			  FILE * stream)
{
  return freopen (filename, mode, stream);
}