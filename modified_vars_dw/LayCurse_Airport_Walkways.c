#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void double_int_screen(double d[], int p[], int s)
{
  int first_iteration;
  int frequency;
  int d_str;
  int a;
  double y1;
  double ti;
  double a;
  if (s <= 1)
    return;

  y1 = (d[0] + d[s - 1]) / 2.0;
  ti = y1 + 1e-10;
  y1 -= 1e-10;
  frequency = -1;
  d_str = s;
  for (;;)
  {
    while (d[++frequency] < y1)
      ;

    while (d[--d_str] > ti)
      ;

    if (frequency >= d_str)
      break;

    a = d[frequency];
    d[frequency] = d[d_str];
    d[d_str] = a;
    a = p[frequency];
    p[frequency] = p[d_str];
    p[d_str] = a;
  }

  double_int_screen(d, p, frequency);
  double_int_screen((d + d_str) + 1, (p + d_str) + 1, (s - d_str) - 1);
}

int Main()
{
  int first_iteration;
  int frequency;
  int d_str;
  int str;
  int l;
  int p;
  int p;
  double walk;
  double run;
  double run_time;
  double length;
  double st[1200];
  double ed[1200];
  double ksk[1200];
  double function_length[1200];
  double go_speed[1200];
  double rest;
  double need;
  double value[1200];
  int ind[1200];
  double result;
  int size;
  int count = 0;
  scanf("%d", &size);
  while (size--)
  {
    scanf("%lf%lf%lf", &length, &walk, &run);
    scanf("%lf%d", &run_time, &p);
    for (frequency = 0; frequency < p; frequency++)
      scanf("%lf%lf%lf", st + frequency, ed + frequency, ksk + frequency);

    rest = length;
    for (frequency = 0; frequency < p; frequency++)
      rest -= ed[frequency] - st[frequency];

    for (frequency = 0; frequency < p; frequency++)
    {
      function_length[frequency] = ed[frequency] - st[frequency];
      go_speed[frequency] = ksk[frequency] + walk;
    }

    function_length[p] = rest;
    go_speed[p] = walk;
    p++;
    for (frequency = 0; frequency < p; frequency++)
      value[frequency] = go_speed[frequency], ind[frequency] = frequency;

    double_int_screen(value, ind, p);
    result = 0;
    for (frequency = 0; frequency < p; frequency++)
    {
      str = ind[frequency];
      rest = function_length[str];
      need = rest / ((go_speed[str] + run) - walk);
      if (need > run_time)
        need = run_time;

      result += need;
      rest -= ((go_speed[str] + run) - walk) * need;
      run_time -= need;
      need = rest / go_speed[str];
      result += need;
    }

    printf("Case #%d: %.10lf\n", ++count, result);
  }

  return 0;
}


