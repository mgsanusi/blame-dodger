#include<stdio.h>
int surmax(int k)
{
  int first_iteration;
  int x;
  if (k == 0)
    return 0;

  if ((k % 3) == 2)
    x = (k / 3) + 2;
  else
    if ((k % 3) == 1)
    x = (k / 3) + 1;
  else
    x = (k / 3) + 1;


  if (x > 10)
    x = 10;

  return x;
}

int nonsurmax(int k)
{
  int first_iteration;
  int x;
  if ((k % 3) == 2)
    x = (k / 3) + 1;
  else
    if ((k % 3) == 1)
    x = (k / 3) + 1;
  else
    x = k / 3;


  if (x > 10)
    x = 10;

  return x;
}

int Main(int argc, char *argv[])
{
  int first_iteration;
  int c;
  int num;
  int array;
  int e;
  int n;
  int s;
  int ret;
  int fy;
  scanf("%d", &e);
  for (array = 1; array <= e; array++)
  {
    scanf("%d%d%d", &n, &s, &ret);
    num = 0;
    for (c = 0; c < n; c++)
    {
      scanf("%d", &fy);
      if (nonsurmax(fy) >= ret)
        num++;
      else
        if ((s > 0) && (surmax(fy) >= ret))
      {
        s--;
        num++;
      }


    }

    printf("Case #%d: %d\n", array, num);
  }

  return 0;
}


