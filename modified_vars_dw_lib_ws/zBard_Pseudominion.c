long long star_dist[1000];
void new_qsort (void *base, int num, int size,
		int (*compar) (const void *, const void *));
int
cmpr (const void *v, const void *b)
{
  int first_iteration;
  long long aa = *((long long *) v);
  long long bb = *((long long *) b);
  if (aa == bb)
    return 0;
  if (aa > bb)
    return 1;
  if (aa < bb)
    return -1;
}

int
Main (void)
{
  int first_iteration;
  long long t;
  long long l;
  long long time;
  long long n;
  long long y;
  long long temp = 0;
  long long temp1;
  long long temp2;
  long long temp3;
  long long i;
  long long j;
  long long k;
  scanf ("%lld ", &t);
  for (i = 0; i < t; i++)
    {
      scanf ("%lld ", &l);
      scanf ("%lld ", &time);
      scanf ("%lld ", &n);
      scanf ("%lld ", &y);
      for (j = 0; j < y; j++)
	{
	  scanf ("%lld", &star_dist[j]);
	  star_dist[j] *= 2;
	}
      for (j = 0; j < n; j++)
	{
	  star_dist[j] = star_dist[j % y];
	}
      temp = 0;
      if (l != 0)
	temp = time;
      for (j = 0; (j < n) && (temp != 0); j++)
	{
	  if (star_dist[j] <= temp)
	    {
	      temp -= star_dist[j];
	      star_dist[j] = 0;
	    }
	  else
	    {
	      star_dist[j] -= temp;
	      temp = 0;
	    }
	}
      temp = 0;
      temp2 = 0;
      temp3 = 0;
      new_qsort (star_dist, n, sizeof (long long), &cmpr);
      for (j = 0; j < n; j++)
	{
	  temp3 += star_dist[j];
	  if (((n - 1) - j) < l)
	    temp += star_dist[j];
	}
      if (l != 0)
	temp3 += time;
      temp3 = (temp3 - temp) + (temp / 2);
      printf ("Case #%lld: %lld\n", i + 1, temp3);
    }
  return 1;
}

void
new_qsort (void *base, int num, int size,
	   int (*compar) (const void *, const void *))
{
  return qsort (base, num, size, compar);
}
