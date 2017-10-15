#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "math.h"
#include <stddef.h>
typedef unsigned long long ubig;
typedef long long big;
void *new_malloc (size_t size);
void new_free (void *ptr);
int
compar (void *data, const void *one, const void *two)
{
  int *ione = *((int **) one);
  int *itwo = *((int **) two);
  int lim = *((int *) data);
  int len;
  for (len = 0; len < lim; len++)
    {
      if (ione[len] < itwo[len])
	{
	  return -1;
	}
      else if (ione[len] > itwo[len])
	{
	  return 1;
	}
    }
  return 0;
}

int
Main ()
{
  long no;
  long iii;
  scanf (" %ld", &no);
  for (iii = 0; iii < no; iii++)
    {
      ubig lim;
      scanf (" %llu", &lim);
      int **input = new_malloc ((sizeof (int *)) * ((2 * lim) - 1));
      if (!input)
	{
	  return 1;
	}
      int len;
      for (len = 0; len < ((2 * lim) - 1); len++)
	{
	  input[len] = new_malloc ((sizeof (int)) * lim);
	  if (!input[len])
	    {
	      return 1;
	    }
	  int state;
	  for (state = 0; state < lim; state++)
	    {
	      scanf (" %d", &input[len][state]);
	    }
	}
      qsort_r (input, (2 * lim) - 1, sizeof (int *), &lim, compar);
      int *total = new_malloc ((sizeof (int)) * 2500);
      memset (total, 0, (sizeof (int)) * 2500);
      for (len = 0; len < ((2 * lim) - 1); len++)
	{
	  int state;
	  for (state = 0; state < lim; state++)
	    {
	      total[input[len][state] - 1]++;
	    }
	}
      printf ("Case #%ld: ", iii + 1);
      for (len = 0; len < 2500; len++)
	{
	  if ((total[len] % 2) == 1)
	    {
	      printf ("%d ", len + 1);
	    }
	}
      printf ("\n");
      new_free (total);
      for (len = 0; len < lim; len++)
	{
	  new_free (input[len]);
	}
      new_free (input);
    }
  return 0;
}

void *new_malloc (size_t size);
void
new_free (void *ptr)
{
  return free (ptr);
}

void *
new_malloc (size_t size)
{
  return malloc (size);
}
