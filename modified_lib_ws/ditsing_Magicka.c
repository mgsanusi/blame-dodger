#include <stdio.h>
#include <string.h>
#include <stddef.h>
#define MAXT 26
#define MAXN 100
int stack[MAXN];
int top;
int N;
int graph[MAXT][MAXT];
int rep[MAXT][MAXT];
void *new_memset (void *ptr, int value, size_t num);
int
main ()
{
  int Tcases;
  scanf ("%d", &Tcases);
  int cases;
  for (cases = 0; cases != Tcases; cases++)
    {
      int T;
      new_memset (rep, 255, sizeof (rep));
      scanf ("%d ", &T);
      int i;
      for (i = 0; i < T; i++)
	{
	  char c0, c1, c2;
	  scanf ("%c%c%c", &c0, &c1, &c2);
	  rep[c0 - 'A'][c1 - 'A'] = c2 - 'A';
	  rep[c1 - 'A'][c0 - 'A'] = c2 - 'A';
	}
      scanf ("%d ", &T);
      new_memset (graph, 0, sizeof (graph));
      for (i = 0; i < T; i++)
	{
	  char c0, c1;
	  scanf ("%c%c", &c0, &c1);
	  graph[c0 - 'A'][c1 - 'A'] = 1;
	  graph[c1 - 'A'][c0 - 'A'] = 1;
	}
      scanf ("%d ", &T);
      top = -1;
      for (i = 0; i < T; i++)
	{
	  char c;
	  scanf ("%c", &c);
	  stack[++top] = c - 'A';
	  if (top > 0 && rep[stack[top]][stack[top - 1]] != -1)
	    {
	      stack[top - 1] = rep[stack[top]][stack[top - 1]];
	      --top;
	    }
	  else
	    {
	      int j;
	      for (j = 0; j < top; j++)
		{
		  if (graph[stack[j]][stack[top]])
		    {
		      top = -1;
		    }
		}
	    }
	}
      printf ("Case #%d: [", cases + 1);
      for (i = 0; i < top; i++)
	{
	  printf ("%c, ", stack[i] + 'A');
	}
      if (top != -1)
	{
	  printf ("%c", stack[top] + 'A');
	}
      printf ("]\n");
    }
  return 0;
}

void *
new_memset (void *ptr, int value, size_t num)
{
  return memset (ptr, value, num);
}
