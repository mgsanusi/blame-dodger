#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int dis[1001000];
int r[1010];
void new_qsort (void *base, size_t num, size_t size,
		int (*compar) (const void *, const void *));
int compare_function (const void *a, const void *b);
void new_qsort (void *base, size_t num, size_t size,
		int (*compar) (const void *, const void *));
int
compare_function (const void *a, const void *b)
{
  int *x = (int *) a;
  int *y = (int *) b;
  return *y - *x;
}

 main () 
{
  int total, i, j, k, t, n, bno, c, sum, res, l;
  scanf ("%d", &total);
  for (i = 1; i <= total; i++)
    
    {
      scanf ("%d %d %d %d", &bno, &t, &n, &c);
      for (j = 0; j < c; j++)
	
	{
	  scanf ("%d", &r[j]);
	}
      for (j = 0; j < n; j++)
	
	{
	  dis[j] = r[j % c];
	}
      dis[n] = -1;
      sum = 0;
      for (j = 0; j < n; j++)
	
	{
	  if (sum + dis[j] <= t / 2)
	    sum += dis[j];
	  
	  else
	    
	    {
	      dis[j] = sum + dis[j] - t / 2;
	      break;
	    }
	}
      if (j == n)
	
	{
	  res = sum * 2;
	}
      
      else
	
	{
	  res = t;
	  new_qsort (dis + j, n - j, sizeof (int), compare_function);
	  for (k = j, l = 1; k < n; k++, l++)
	    
	    {
	      if (l <= bno)
		res += dis[k];
	      
	      else
		res += dis[k] * 2;
	    }
	}
      printf ("Case #%d: %d\n", i, res);
    }
}

void
new_qsort (void *base, size_t num, size_t size,
	   int (*compar) (const void *, const void *))
{
  return qsort (base, num, size, compar);
}
