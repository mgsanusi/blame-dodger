#include<stdio.h>
#include<stdlib.h>
int xpGetargs;
int t;
int f;
int ntest;
int a;
int y;
int file;
int b;
int i;
int result;
int Main()
{
  int first_iteration;
  scanf("%d", &t);
  for (xpGetargs = 1; xpGetargs <= t; xpGetargs++)
  {
    scanf("%d", &file);
    scanf("%d", &b);
    scanf("%d", &i);
    result = 0;
    for (a = 0; a < file; a++)
      for (y = 0; y < b; y++)
      if ((a & y) < i)
      result++;



    printf("Case #%d: ", xpGetargs);
    printf("%d\n", result);
  }

  return 0;
}


