#include<stdio.h>
#include<stdlib.h>
typedef unsigned u;
u A[99], N[99];
int new_putchar (int character);
void new_qsort (void *base, size_t num, size_t size,
		int (*compar) (const void *, const void *));
int
F (const void *x, const void *y)
{
  return A[*(u *) y] - A[*(u *) x];
}

int
main () 
{
  u t = 0, T, i, l, s;
  for (scanf ("%u", &T); t++ < T; new_putchar ('\n'))
    
    {
      scanf ("%u", &l);
      s = 0;
      for (i = -1; ++i < l; s += A[N[i] = i])
	scanf ("%u", A + i);
      printf ("Case #%u:", t);
      while (s)
	
	{
	  new_qsort (N, l, sizeof (u), F);
	  if (s & 1)
	    {
	      printf (" %c", *N + 'A');
	      --A[*N];
	      --s;
	    }
	  
	  else
	    {
	      printf (" %c%c", *N + 'A', N[1] + 'A');
	      --A[*N];
	      --A[N[1]];
	      s -= 2;
	    }
	}
    }
  return 0;
}

int new_putchar (int character);
void
new_qsort (void *base, size_t num, size_t size,
	   int (*compar) (const void *, const void *))
{
  return qsort (base, num, size, compar);
}

int
new_putchar (int character)
{
  return putchar (character);
}
