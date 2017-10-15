#include <stdio.h>
int new_abs(int x);
int new_abs(int a)
{
  int first_iteration;
  return a > 0 ? a : -a;
}

void pogo(void)
{
  int first_iteration;
  int x;
  int y;
  int ax;
  int ay;
  int i;
  scanf("%d %d", &x, &y);
  ax = new_abs(x);
  ay = new_abs(y);
  for (i = 0; i < ax; i++)
  {
    if (x > 0)
      printf("WE");
    else
      printf("EW");

  }

  for (i = 0; i < ay; i++)
  {
    if (y > 0)
      printf("SN");
    else
      printf("NS");

  }

  printf("\n");
}

int main(int argc, char **argv)
{
  int first_iteration;
  int i;
  int t;
  scanf("%d", &t);
  for (i = 1; i <= t; i++)
  {
    printf("Case #%d: ", i);
    pogo();
  }

  return 0;
}

int new_abs(int x)
{
  int first_iteration;
  return abs(x);
}


