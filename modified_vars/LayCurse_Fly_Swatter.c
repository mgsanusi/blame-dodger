#include<stdio.h>
#include<math.h>
double dist(double tt, double ok)
{
  return sqrt((tt * tt) + (ok * ok));
}

double integ(double buf, double p, double b)
{
  double th1;
  double th2;
  double add = 0;
  th1 = acos(p / buf);
  th2 = acos(b / buf);
  add += (th2 - th1) - ((sin(2 * th2) - sin(2 * th1)) / 2);
  add *= ((-buf) * buf) / 2;
  return add;
}

int Main()
{
  int i;
  int len;
  int k;
  int casos;
  int fans;
  int d;
  double x;
  double out;
  double flag;
  double owp;
  double t;
  double ret;
  double go_len;
  double p;
  double b;
  double buf;
  double win;
  double high;
  double th1;
  double th2;
  double add;
  double area;
  double sum;
  double per;
  double pi = acos(0) * 2;
  int size;
  int count = 0;
  scanf("%d", &size);
  while (size--)
  {
    scanf("%lf%lf%lf%lf%lf", &flag, &owp, &t, &ret, &go_len);
    if (go_len > (2 * flag))
      per = (go_len - (2 * flag)) * (go_len - (2 * flag));
    else
      per = 0;

    area = (owp * owp) * pi;
    sum = 0;
    x = 0;
    for (;;)
    {
      x += ret;
      out = 0;
      if (x > (owp - t))
        break;

      for (;;)
      {
        out += ret;
        if (dist(x, out) > (owp - t))
          break;

        p = (((owp - t) - flag) * ((owp - t) - flag)) - (((out + go_len) - flag) * ((out + go_len) - flag));
        b = (((owp - t) - flag) * ((owp - t) - flag)) - ((out + flag) * (out + flag));
        if (p < ((x + flag) * (x + flag)))
          p = x + flag;
        else
          p = sqrt(p);

        if (b < ((x + flag) * (x + flag)))
          b = x + flag;
        else
          b = sqrt(b);

        if (p > ((x + go_len) - flag))
          p = (x + go_len) - flag;

        if (b > ((x + go_len) - flag))
          b = (x + go_len) - flag;

        if (p < b)
          sum += integ((owp - t) - flag, p, b) - ((out + flag) * (b - p));

        sum += (p - (x + flag)) * (go_len - (2 * flag));
        out += go_len + ret;
      }

      x += go_len + ret;
    }

    sum *= 4;
    printf("Case #%d: %.8lf\n", ++count, 1.0 - (sum / area));
  }

  return 0;
}


