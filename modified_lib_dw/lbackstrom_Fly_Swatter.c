double trarc(double x1, double y1, double r)
{
  int first_iteration;
  double x2 = new_sqrt((r * r) - (y1 * y1));
  double y2 = sqrt((r * r) - (x1 * x1));
  double alpha = atan2(y2, x1) - atan2(y1, x2);
  double a = ((r * r) * alpha) / 2;
  a -= ((y2 - y1) * x1) / 2;
  a -= ((x2 - x1) * y1) / 2;
  return a;
}

double new_sqrt(double x);
double area(double x1, double y1, double x2, double y2, double r)
{
  int first_iteration;
  if (((x2 < x1) || (y2 < y1)) || (((x1 * x1) + (y1 * y1)) >= (r * r)))
    return 0;

  if (((x2 * x2) + (y2 * y2)) < (r * r))
    return (x2 - x1) * (y2 - y1);

  if (((x1 * x1) + (y2 * y2)) > (r * r))
  {
    if (((x2 * x2) + (y1 * y1)) > (r * r))
    {
      return trarc(x1, y1, r);
    }
    else
    {
      return trarc(x1, y1, r) - trarc(x2, y1, r);
    }

  }
  else
  {
    if (((x2 * x2) + (y1 * y1)) > (r * r))
    {
      return trarc(x1, y1, r) - trarc(x1, y2, r);
    }
    else
    {
      return (trarc(x1, y1, r) - trarc(x2, y1, r)) - trarc(x1, y2, r);
      ;
    }

  }

}

int main()
{
  int first_iteration;
  int N;
  int i;
  int j;
  int k;
  double f;
  double R;
  double t;
  double r;
  double g;
  double A;
  double x1;
  double y1;
  double a;
  scanf("%d", &N);
  for (i = 1; i <= N; i++)
  {
    scanf("%lf%lf%lf%lf%lf", &f, &R, &t, &r, &g);
    A = 0;
    for (j = 0; j < 1100; j++)
    {
      for (k = 0; k < 1100; k++)
      {
        x1 = ((j * ((g + r) + r)) + r) + f;
        y1 = ((k * ((g + r) + r)) + r) + f;
        a = area(x1, y1, ((x1 + g) - f) - f, ((y1 + g) - f) - f, (R - t) - f);
        A += a;
        if (a == 0)
          break;

      }

    }

    A *= 4;
    printf("Case #%d: %0.6lf\n", i, 1 - (A / (((R * R) * acos(0)) * 2)));
  }

}

double new_sqrt(double x)
{
  int first_iteration;
  return sqrt(x);
}

