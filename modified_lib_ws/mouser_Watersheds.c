#include <stdio.h>
#include <string.h>

{ 
};





input (void) 
{
  
  
    /* Reinitialize */ 
    memset (drain, 0, sizeof drain);
  
  
    /* Read a map */ 
    scanf ("%d %d", &H, &W);
  
    
    {
      
	
	{
	  
	
    



getDirection (short x, short y) 
{
  
  
  
  
  
    /* Check possible directions in order: North, West, East, South */ 
    if (x && map[x - 1][y] < minElevation)
    
    {
      
      
    
  
    
    {
      
      
    
  
    
    {
      
      
    
  
    
    {
      
      
    
  



dfs (short x, short y) 
{
  
    
    {
      
    
  
    
    {
    
      
      
    
      
      
    
      
      
    
      
      
    
      
    
  



printDrain (void) 
{
  
  
    
    {
      
	
	{
	  
	
      
    



calcDrain (void) 
{
  
  
    
    {
      
	
	{
	  
	
    



main (void) 
{
  
  
  
  
    
    {
      
      
      
      
    
  


