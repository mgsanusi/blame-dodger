#include <stdio.h>
#include <math.h>
double start;
double works;
double j;
void handle()
{
  scanf("%lf %lf %lf ", &start, &works, &j);
  double s = ((works * j) - (works * start)) / start;
  double answer = 0.0;
  double cur_r = 2.0;
  while (cur_r < s)
  {
    answer += start / cur_r;
    cur_r += works;
  }

  answer += j / cur_r;
  printf("%.7f\n", answer);
}

int Main()
{
  int t;
  int draw;
  scanf("%d ", &t);
  for (draw = 0; draw < t; draw++)
  {
    printf("Case #%d: ", draw + 1);
    handle();
  }

  return 0;
}


