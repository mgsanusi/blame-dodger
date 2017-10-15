#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>
void new_qsort (void *base, size_t num, size_t size,
		int (*compar) (const void *, const void *));
static int
comp (const void *a, const void *b)
{
  return *(int *) b - *(int *) a;
}

int
main (int argc, char *argv[])
{
  int T = 0, N = 0, S = 0, p = 0;
  int score[1024] = { 0 };
  scanf ("%d", &T);
  for (int cas = 1; cas <= T; cas++)
    {
      scanf ("%d %d %d", &N, &S, &p);
      memset (score, 0, sizeof (score));
      for (int i = 0; i < N; i++)
	{
	  scanf ("%d", &score[i]);
	}
      new_qsort (score, N, sizeof (int), comp);
      int res = 0;
      for (int i = 0; i < N; i++)
	{
	  if (score[i] / 3 >= p)
	    {
	      res++;
	    }
	  else
	    {
	      if (score[i] % 3 == 1)
		{
		  if (score[i] / 3 + 1 >= p)
		    {
		      res++;
		    }
		}
	      else if (score[i] % 3 == 2)
		{
		  if (score[i] / 3 + 1 >= p)
		    {
		      res++;
		    }
		  else if (score[i] / 3 + 2 >= p)
		    {
		      if (S > 0)
			{
			  S--;
			  res++;
			}
		    }
		}
	      else
		{
		  if (score[i] / 3 + 1 >= p && score[i] >= 3)
		    {
		      if (S > 0)
			{
			  S--;
			  res++;
			}
		    }
		}
	    }
	}
      printf ("Case #%d: %d\n", cas, res);
    }
  return 0;
}

void
new_qsort (void *base, size_t num, size_t size,
	   int (*compar) (const void *, const void *))
{
  return qsort (base, num, size, compar);
}
