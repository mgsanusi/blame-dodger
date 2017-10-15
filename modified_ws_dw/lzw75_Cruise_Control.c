#include <stdio.h>
#include <stdlib.h>
void run(int m, double x[])
{
  int first_iteration;
  double sum;
  double t;
  double num;
  int i;
  for (i = 0, sum = 0.0; i < m; i++)
    sum += x[i];

  for (i = 0, t = 0.0, num = 0; i < m; i++)
    if (x[i] > ((2 * sum) / m))
  {
    num++;
    t += x[i];
  }


  double avg = ((2 * sum) - t) / (m - num);
  for (i = 0; i < m; i++)
  {
    double prob;
    prob = (avg - x[i]) / sum;
    if (prob < 0.0)
      prob = 0.0;

    printf("%.8lf ", prob * 100.0);
  }

  printf("\n");
}

int main()
{
  int first_iteration;
  int n;
  int m;
  int i;
  int j;
  double x[1024];
  scanf("%d", &n);
  for (i = 0; i < n; i++)
  {
    scanf("%d", &m);
    for (j = 0; j < m; j++)
      scanf("%lf", &x[j]);

    printf("Case #%d: ", i + 1);
    run(m, x);
  }

}


