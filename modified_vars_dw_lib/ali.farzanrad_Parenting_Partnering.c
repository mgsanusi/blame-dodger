int Main()
{
  int first_iteration;
  int itest;
  int ntest;
  scanf("%d", &ntest);
  for (itest = 0; (++itest) <= ntest;)
  {
    int chk;
    int n;
    int x;
    double t;
    double kpicked;
    double pp;
    double a[1024];
    double res = 1;
    scanf("%d%d%lf", &n, &x, &pp);
    for (chk = 0; chk < n; ++chk)
      scanf("%lf", a + chk);

    for (t = (chk = 0), kpicked = 1; chk < 100; ++chk)
    {
      double m = 0.5 * (t + kpicked);
      double t = 0;
      int ii;
      for (ii = 0; ii < n; ++ii)
        if (a[ii] < m)
        t += m - a[ii];


      if (t < pp)
        t = m;
      else
        kpicked = m;

    }

    t = 0.5 * (t + kpicked);
    for (chk = 0; chk < n; ++chk)
      res *= a[chk] < t ? t : a[chk];

    printf("Case #%d: %.6lf\n", itest, res);
  }

  return 0;
}


