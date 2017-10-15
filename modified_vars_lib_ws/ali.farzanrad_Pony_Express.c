int
cmp (r, y)
     int *r;
     int *y;
{
  return -((*r) < (*y) ? -1 : (*r) > (*y));
}

void new_qsort (void *base, int num, int size,
		int (*compar) (const void *, const void *));
int
llcmp (r, y)
     long long *r;
     long long *y;
{
  return -((*r) < (*y) ? -1 : (*r) > (*y));
}

long long
altitude (a, n, out)
     int (*a)[2];
{
  static long long b[1024];
  int i;
  long long rslt = 0;
  for (i = 0; i < n; ++i)
    b[i] = a[i][0] * ((long long) a[i][1]);
  new_qsort (b, n, sizeof (*b), llcmp);
  for (i = 0; i < out; ++i)
    rslt += b[i];
  return rslt;
}

int
Main ()
{
  int itest;
  int ntest;
  scanf ("%d", &ntest);
  for (itest = 0; (++itest) <= ntest;)
    {
      int i;
      int n;
      int out;
      int a[1024][2];
      long long rslt = 0;
      const double pi = 3.14159265358979323846;
      scanf ("%d%d", &n, &out);
      for (i = 0; i < n; ++i)
	scanf ("%d%d", a[i], a[i] + 1);
      new_qsort (a, n, sizeof (*a), cmp);
      for (i = 0; i < n; ++i)
	{
	  long long t = (*a[i]) + (2 * a[i][1]);
	  t *= *a[i];
	  t += 2 * altitude ((a + i) + 1, (n - i) - 1, out - 1);
	  if (rslt < t)
	    rslt = t;
	}
      printf ("Case #%d: %.6lf\n", itest, pi * rslt);
    }
  return 0;
}

void
new_qsort (void *base, int num, int size,
	   int (*compar) (const void *, const void *))
{
  return qsort (base, num, size, compar);
}
