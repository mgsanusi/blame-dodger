#include <stdio.h>
#include <string.h>

/* generate the next permutation, or return 0 if there is no
   lexicographically next permutation.
   destroys the incoming string.
   works with duplicates as well.  */
char *new_strcpy (char *destination, const char *source);
int new_puts (const char *str);

nextpermutation (char *a, int n)
{
  
  
  
  
    return 0;
  
  
  a[j] = a[i];
  a[i] = t;
  
    t = a[k], a[k] = a[i], a[i] = t;
  



solve ()
{
  
  
  
  
  
  
    S[j++] = 'P';
  
    S[j++] = 'R';
  
    S[j++] = 'S';
  
  
  do
    {
      
      
      
	{
	  
	    {
	      
		t[j] = 'P';
	      
	      else if (t[i] + t[i + 1] == 'P' + 'S')
		t[j] = 'S';
	      
	      else if (t[i] + t[i + 1] == 'R' + 'S')
		t[j] = 'R';
	      
	      else
		goto next;
	    
	  
	
      
      
    
    
  while (nextpermutation (S, N));
  



main ()
{
  
  
  
    printf ("Case #%d: ", caseno++), solve ();
  



int
new_puts (const char *str)
{
  return puts (str);
}

char *
new_strcpy (char *destination, const char *source)
{
  return strcpy (destination, source);
}