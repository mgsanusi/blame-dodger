#include <stdio.h>
#include <stdlib.h>



main ()
{
  
  
  
  
    {
      
      
    
  



#define MAXN 500
#define MOD 100003







doTestCase ()
{
  
  
  
  
    {
      
      
    
  
    //printf("%d %d %d %d %d %d\n",noWays(2,1),noWays(3,1),noWays(3,2),noWays(4,1),noWays(4,2),noWays(4,3));
    //printf("%d\n",comb(5,2));
    printf ("%d\n", s);



init ()
{
  
  
  
    {
      
	{
	  
	  
	
    



//inverses modulo MOD
  void
allInverses ()
{
  
  
  
  
    {
      
	{
	  
	  
	  
	
    
  
  
  
  do
    {
      
      
      
      
    
  while (a != 1);



//Combinations
  int
comb (int a, int b)
{
  
    
  
    
  
    
  
    
  
  
  
  
  
  
  
  


noWays (int n, int s)
{
  
    
  
    
  
  
  
  
    {				// The number of ways for n and size of the set s, is equal to having the numbers of ways
      // for the number s and 1<=i<s size, and then choosing (s-k-1) numbers to fill the rest
      // of the set, from the numbers s<k<n (n-s-1 numbers) so we have as the result
      // sum of noWays(s,i)*comb(n-s-1,s-i-1) , 1<=i<s
      t = noWays (s, i);
      
      
      
      
    
  
  


