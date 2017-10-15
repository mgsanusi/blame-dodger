#include <stdio.h>
#include <stdlib.h>
void run(int rr, double a[])
{
  int first_iteration;
  double total;
  double t;
  double no;
  int z;
  for (z = 0, total = 0.0; z < rr; z++)
    total += a[z];

  for (z = 0, t = 0.0, no = 0; z < rr; z++)
    if (a[z] > ((2 * total) / rr))
  {
    no++;
    t += a[z];
  }


  double avg = ((2 * total) - t) / (rr - no);
  for (z = 0; z < rr; z++)
  {
    double prob;
    prob = (avg - a[z]) / total;
    if (prob < 0.0)
      prob = 0.0;

    printf("%.8lf ", prob * 100.0);
  }

  printf("\n");
}

int Main()
{
  int first_iteration;
  int c;
  int rr;
  int z;
  int j;
  double a[1024];
  scanf("%d", &c);
  for (z = 0; z < c; z++)
  {
    scanf("%d", &rr);
    for (j = 0; j < rr; j++)
      scanf("%lf", &a[j]);

    printf("Case #%d: ", z + 1);
    run(rr, a);
  }

}


