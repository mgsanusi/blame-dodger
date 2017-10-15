int
Main ()
{
  int itest;
  int ntest;
  scanf ("%d", &ntest);
  for (itest = 0; (++itest) <= ntest;)
    {
      int casos;
      int root;
      int k;
      int b;
      int b[128];
      int n;
      int x;
      int result = 0;
      char mark[128];
      scanf ("%d%d", &n, &x);
      memset (mark, 0, sizeof (mark));
      for (casos = 0; casos < n; ++casos)
	scanf ("%d", b + casos);
      for (casos = 0; casos < n; ++casos)
	if ((!mark[casos]) && ((b[casos] % x) == 0))
	  {
	    mark[casos] = 1;
	    ++result;
	  }
      for (casos = 0; casos < n; ++casos)
	for (root = casos; (++root) < n;)
	  if (((!mark[casos]) && (!mark[root]))
	      && (((b[casos] + b[root]) % x) == 0))
	    {
	      mark[casos] = (mark[root] = 1);
	      ++result;
	    }
      for (casos = 0; casos < n; ++casos)
	for (root = casos; (++root) < n;)
	  for (k = root; (++k) < n;)
	    if ((((!mark[casos]) && (!mark[root])) && (!mark[k]))
		&& ((((b[casos] + b[root]) + b[k]) % x) == 0))
	      {
		mark[casos] = (mark[root] = (mark[k] = 1));
		++result;
	      }
      for (casos = 0; casos < n; ++casos)
	for (root = casos; (++root) < n;)
	  for (k = root; (++k) < n;)
	    for (b = k; (++b) < n;)
	      if (((((!mark[casos]) && (!mark[root])) && (!mark[k]))
		   && (!mark[b]))
		  && (((((b[casos] + b[root]) + b[k]) + b[b]) % x) == 0))
		{
		  mark[casos] = (mark[root] = (mark[k] = (mark[b] = 1)));
		  ++result;
		}
      for (casos = 0; casos < n; ++casos)
	if (!mark[casos])
	  {
	    ++result;
	    break;
	  }
      printf ("Case #%d: %d\n", itest, result);
    }
  return 0;
}
