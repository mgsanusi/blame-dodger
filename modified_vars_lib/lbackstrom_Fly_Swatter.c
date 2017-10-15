double trarc(double re_why, double wp, double x)
{
  double d = new_sqrt((x * x) - (wp * wp));
  double names = sqrt((x * x) - (re_why * re_why));
  double alpha = atan2(names, re_why) - atan2(wp, d);
  double m = ((x * x) * alpha) / 2;
  m -= ((names - wp) * re_why) / 2;
  m -= ((d - re_why) * wp) / 2;
  return m;
}
double new_sqrt(double x);


double area(double re_why, double wp, double d, double names, double x)
{
  if (((d < re_why) || (names < wp)) || (((re_why * re_why) + (wp * wp)) >= (x * x)))
    return 0;

  if (((d * d) + (names * names)) < (x * x))
    return (d - re_why) * (names - wp);

  if (((re_why * re_why) + (names * names)) > (x * x))
  {
    if (((d * d) + (wp * wp)) > (x * x))
    {
      return trarc(re_why, wp, x);
    }
    else
    {
      return trarc(re_why, wp, x) - trarc(d, wp, x);
    }

  }
  else
  {
    if (((d * d) + (wp * wp)) > (x * x))
    {
      return trarc(re_why, wp, x) - trarc(re_why, names, x);
    }
    else
    {
      return (trarc(re_why, wp, x) - trarc(d, wp, x)) - trarc(re_why, names, x);
      ;
    }

  }

}

int Main()
{
  int n;
  int m1;
  int j;
  int k;
  double f;
  double r;
  double tmp;
  double x;
  double nextlado;
  double x;
  double re_why;
  double wp;
  double m;
  scanf("%d", &n);
  for (m1 = 1; m1 <= n; m1++)
  {
    scanf("%lf%lf%lf%lf%lf", &f, &r, &tmp, &x, &nextlado);
    x = 0;
    for (j = 0; j < 1100; j++)
    {
      for (k = 0; k < 1100; k++)
      {
        re_why = ((j * ((nextlado + x) + x)) + x) + f;
        wp = ((k * ((nextlado + x) + x)) + x) + f;
        m = area(re_why, wp, ((re_why + nextlado) - f) - f, ((wp + nextlado) - f) - f, (r - tmp) - f);
        x += m;
        if (m == 0)
          break;

      }

    }

    x *= 4;
    printf("Case #%d: %0.6lf\n", m1, 1 - (x / (((r * r) * acos(0)) * 2)));
  }

}



double new_sqrt(double x) {
  return sqrt(x);
}