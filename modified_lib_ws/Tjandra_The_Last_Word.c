#include<stdio.h>
typedef unsigned u;
char D[4444];
int new_getchar ();
int
main () 
{
  u t = 0, T, l, r;
  char c;
  for (scanf ("%u", &T); t++ < T;)
    
    {
      while ((c = new_getchar ()) <= ' ');
      D[l = r = 2222] = c;
      while ((c = new_getchar ()) > ' ')
	
	{
	  if (c >= D[l])
	    D[--l] = c;
	  
	  else
	    D[++r] = c;
	}
      D[++r] = '\0';
      printf ("Case #%u: %s\n", t, D + l);
    }
  return 0;
}

int
new_getchar ()
{
  return getchar ();
}
