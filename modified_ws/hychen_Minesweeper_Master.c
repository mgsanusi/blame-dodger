#include<stdio.h>
int m[50][50], h, w;

swapint (int *c, int *d)
{
  
  
  
  


printboard (int i, int x, int y)
{
  
  
    {
      
      
      
	{
	  
	    {
	      
	    
	
    
  
    {
      
	{
	  
	    putchar ('c');
	  
	  else if (m[a][b] == 0)
	    putchar ('*');
	  
	  else
	    putchar ('.');
	
      
    



clearboard ()
{
  
  
    {
      
	{
	  
	
    



fillanswer (int c, int d, int n)
{
  
  
    m[a][0] = m[a][1] = 1;
  
    m[0][b] = m[1][b] = 1;
  
  
    {
      
	{
	  
	  
	
    



main (int argc, char *argv[])
{
  
  
  
    {
      
      
      
      
	{
	  
	  
	
      
      else
	inv = 0;
      
      
	{			/*special case 1 */
	  
	    m[0][b] = 1;
	  
	
      
	goto yes;		/*special case 2 */
      
	goto no;
      
	goto no;		/*special case 3 */
      
	{
	  
	    {
	      
		break;
	      
		continue;
	      
	      
	    
	
    
      
    
    
  


