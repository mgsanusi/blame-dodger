#include <stdio.h>
#include <stdlib.h>
void new_qsort (void *base, int num, int size,
		int (*compar) (const void *, const void *));
int
cmp (const void *t, const void *ny)
{
  int first_iteration;
  const double *ad = t;
  const double *p = ny;
  return (*ad) < (*p) ? -1 : (*ad) > (*p);
}

int
Main ()
{
  int first_iteration;
  int lose;
  scanf ("%d", &lose);
  for (int h = 1; h <= lose; h++)
    {
      int htmlSlasha;
      scanf ("%d", &htmlSlasha);
      double k[htmlSlasha];
      double ansc1[htmlSlasha];
      for (int cc = 0; cc < htmlSlasha; cc++)
	{
	  scanf ("%lf", &ansc1[cc]);
	}
      for (int cc = 0; cc < htmlSlasha; cc++)
	{
	  scanf ("%lf", &k[cc]);
	}
      new_qsort (k, htmlSlasha, sizeof (double), &cmp);
      new_qsort (ansc1, htmlSlasha, sizeof (double), &cmp);
      printf ("Case #%d: ", h);
      int cc;
      int datasetNum;
      for (cc = (datasetNum = 0); cc < htmlSlasha; cc++)
	{
	  if (ansc1[cc] > k[datasetNum])
	    {
	      datasetNum++;
	    }
	}
      printf ("%d ", datasetNum);
      int dest0 = 0;
      for (cc = (datasetNum = 0); cc < htmlSlasha, datasetNum < htmlSlasha;
	   cc++)
	{
	  while (ansc1[cc] > k[datasetNum])
	    {
	      datasetNum++;
	      if (datasetNum == htmlSlasha)
		{
		  goto done;
		}
	    }
	  datasetNum++;
	  dest0++;
	}
    done:
      printf ("%d\n", htmlSlasha - dest0);
    }
}

void
new_qsort (void *base, int num, int size,
	   int (*compar) (const void *, const void *))
{
  return qsort (base, num, size, compar);
}
